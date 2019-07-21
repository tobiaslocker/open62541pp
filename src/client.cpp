#include "open62541.h"

#include "client.hpp"
#include "log.hpp"
#include "parser.hpp"

namespace open62541 {

using namespace logger;

struct StateCallback {
  static void callback(UA_Client *client, UA_ClientState state) {
    return func(client, state);
  }
  static std::function<void(UA_Client *client, UA_ClientState state)> func;
};

std::function<void(UA_Client *client, UA_ClientState state)>
    StateCallback::func;

class Client::impl {
  src::severity_channel_logger<severity_level, std::string> m_lg;
  std::string m_channel = "ua_client";
  std::unique_ptr<ClientEventHandler> m_handler;
  UA_ClientConfig m_config;
  std::unique_ptr<UA_Client, decltype(&UA_Client_delete)> m_client;

  UA_BrowseResponse browse(const UA_BrowseRequest &request) {
    UA_BrowseResponse browse_response =
        UA_Client_Service_browse(m_client.get(), request);
    return browse_response;
  }

  void on_state_changed(UA_Client *client, UA_ClientState state) {
    if (m_handler) {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "Handler installed";
      m_handler->on_state_changed(ClientState::Connected);
    } else {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No Handler installed";
    }
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info) << "State " << state;
  }

 public:
  impl()
      : m_config{config()},
        m_client{std::unique_ptr<UA_Client, decltype(&UA_Client_delete)>(
            UA_Client_new(m_config), UA_Client_delete)} {
    logger::init();
  }

 public:
  impl(std::unique_ptr<ClientEventHandler> handler)
      : m_handler{std::move(handler)},
        m_config{config()},
        m_client{std::unique_ptr<UA_Client, decltype(&UA_Client_delete)>(
            UA_Client_new(m_config), UA_Client_delete)} {
    logger::init();
  }

  UA_ClientConfig config() {
    auto c = UA_ClientConfig_default;
    StateCallback::func = std::bind(&Client::impl::on_state_changed,
                                    this,
                                    std::placeholders::_1,
                                    std::placeholders::_2);
    void (*c_func)(UA_Client *, UA_ClientState) =
        static_cast<decltype(c_func)>(StateCallback::callback);
    c.stateCallback = c_func;
    return c;
  }

  std::vector<EndpointDescription> get_endpoints(std::string const &url) {
    std::vector<EndpointDescription> result;
    UA_EndpointDescription *endpoints = nullptr;
    size_t len = 0;
    auto status =
        UA_Client_getEndpoints(m_client.get(), url.c_str(), &len, &endpoints);
    if (status == UA_STATUSCODE_GOOD) {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info)
          << "Got endpoints from " << url;
    } else {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
          << "Getting endpoints failed. Status code = " << status;
    }
    for (size_t i = 0; i < len; i++) {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Endpoint " << i;
      result.push_back(parser::from_open62541(endpoints[i]));
    }
    UA_Array_delete(endpoints, len, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION]);
    return result;
  }

  void connect(std::string const &url) {
    auto status = UA_Client_connect(m_client.get(), url.c_str());
    if (status == UA_STATUSCODE_GOOD) {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info) << "Connected to " << url;
    } else {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
          << "Connect failed. Status code = " << status;
    }
  }

  void connect(EndpointDescription const &endpoint) {
    auto url = endpoint.endpoint_url();
    auto status = UA_Client_connect(m_client.get(), url.c_str());
    if (status == UA_STATUSCODE_GOOD) {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info) << "Connected to " << url;
    } else {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
          << "Connect failed. Status code = " << status;
    }
  }
  UA_BrowseRequest browse_request(UA_BrowseDescription *bd,
                                  UA_NodeId const &node_id,
                                  UA_BrowseResultMask br_mask,
                                  UA_NodeId const &rt_id) {
    UA_BrowseRequest browse_req;
    UA_BrowseRequest_init(&browse_req);
    browse_req.requestedMaxReferencesPerNode = 0;
    browse_req.nodesToBrowse = bd;
    browse_req.nodesToBrowseSize = 1;
    browse_req.nodesToBrowse[0].nodeId = node_id;
    browse_req.nodesToBrowse[0].resultMask = br_mask;
    browse_req.nodesToBrowse[0].referenceTypeId = rt_id;
    browse_req.nodesToBrowse[0].includeSubtypes = true;
    return browse_req;
  }

  std::vector<ReferenceDescription> get_child_references(
      ReferenceDescription const &reference,
      BrowseResultMask br_mask,
      NodeClass node_class,
      ReferenceTypeIdentifier id) {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Getting child references";
    std::vector<ReferenceDescription> children;
    std::shared_ptr<UA_BrowseDescription> browse_desc(new UA_BrowseDescription);
    UA_BrowseDescription_init(browse_desc.get());
    browse_desc->nodeClassMask = static_cast<uint32_t>(node_class);
    auto browse_req =
        browse_request(browse_desc.get(),
                       parser::to_open62541(reference.node_id().node_id()),
                       static_cast<UA_BrowseResultMask>(br_mask),
                       UA_NODEID_NUMERIC(0, static_cast<uint32_t>(id)));
    UA_BrowseResponse browse_response = browse(browse_req);
    for (size_t i = 0; i < browse_response.resultsSize; ++i) {
      for (size_t j = 0; j < browse_response.results[i].referencesSize; ++j) {
        auto ep =
            parser::from_open62541(browse_response.results[i].references[j]);
        children.push_back(ep);
      }
    }
    UA_BrowseResponse_deleteMembers(&browse_response);
    return children;
  }

  LocalizedText read_display_name_attribute(const NodeId &node_id) {
    UA_LocalizedText out;
    auto status = UA_Client_readDisplayNameAttribute(
        m_client.get(), parser::to_open62541(node_id), &out);
    if (status == UA_STATUSCODE_GOOD) {
      return LocalizedText(parser::from_open62541(out));
    }
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
        << "Read display name failed. Error code = " << status;
    return LocalizedText();
  }
};

Client::Client() : d_ptr{std::make_unique<impl>()} {}

Client::Client(std::unique_ptr<ClientEventHandler> handler)
    : d_ptr{std::make_unique<impl>(std::move(handler))} {}

std::vector<EndpointDescription> Client::get_endpoints(std::string const &url) {
  return d_ptr->get_endpoints(url);
}

void Client::connect(std::string const &url) { d_ptr->connect(url); }

void Client::connect(EndpointDescription const &endpoint) {
  d_ptr->connect(endpoint);
}

LocalizedText Client::read_display_name_attribute(NodeId const &node_id) {
  return d_ptr->read_display_name_attribute(node_id);
}

std::vector<ReferenceDescription> Client::get_child_references(
    ReferenceDescription const &reference,
    BrowseResultMask browse_result_mask,
    NodeClass node_class,
    ReferenceTypeIdentifier identifier) {
  return d_ptr->get_child_references(
      reference, browse_result_mask, node_class, identifier);
}

Client::~Client() = default;

Client &Client::operator=(Client &&) = default;

ClientEventHandler::~ClientEventHandler() {}

}  // namespace open62541
