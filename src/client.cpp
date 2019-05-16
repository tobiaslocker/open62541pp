#include "open62541.h"

#include "client.hpp"

#include "log.hpp"

namespace open62541 {

using namespace logger;

class ClientPrivate {
  src::severity_channel_logger<severity_level, std::string> m_lg;
  std::string m_channel = "ua_client";
  std::shared_ptr<UA_Client> m_client;
  std::shared_ptr<Client> q_ptr;

 public:
  ClientPrivate(Client *client) : q_ptr(client) {}
  ClientPrivate()
      : m_client{std::shared_ptr<UA_Client>(
            UA_Client_new(UA_ClientConfig_default), UA_Client_delete)} {
    logger::init();
  }

  UA_BrowseResponse browse(const UA_BrowseRequest &request) {
    UA_BrowseResponse browse_response =
        UA_Client_Service_browse(m_client.get(), request);
    return browse_response;
  }

  std::vector<EndpointDescription> get_endpoints(std::string const &url) {
    std::vector<EndpointDescription> result;
    UA_EndpointDescription *arr = nullptr;
    size_t len = 0;
    auto status =
        UA_Client_getEndpoints(m_client.get(), url.c_str(), &len, &arr);
    if (status == UA_STATUSCODE_GOOD) {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info)
          << "Got endpoints from " << url;
    } else {
      BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
          << "Getting endpoints failed. Status code = " << status;
    }
    for (size_t i = 0; i < len; i++) {
      result.push_back(EndpointDescription(arr[i]));
    }
    UA_Array_delete(arr, len, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION]);
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
    auto url = endpoint.to_json()["EndpointUrl"].get<std::string>();
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
      NodeClassMask node_class_mask,
      ReferenceTypeIdentifier id) {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Browsing children";
    std::vector<ReferenceDescription> children;
    std::shared_ptr<UA_BrowseDescription> browse_desc(new UA_BrowseDescription);
    UA_BrowseDescription_init(browse_desc.get());
    browse_desc->nodeClassMask = node_class_mask;

    auto node_id = reference.node_id().ua_node_id();
    auto browse_req =
        browse_request(browse_desc.get(),
                       node_id,
                       static_cast<UA_BrowseResultMask>(br_mask),
                       UA_NODEID_NUMERIC(0, static_cast<u_int32_t>(id)));

    UA_BrowseResponse browse_response = browse(browse_req);
    for (size_t i = 0; i < browse_response.resultsSize; ++i) {
      for (size_t j = 0; j < browse_response.results[i].referencesSize; ++j) {
        auto ref =
            ReferenceDescription(browse_response.results[i].references[j]);
        children.push_back(ref);
      }
    }
    UA_BrowseResponse_deleteMembers(&browse_response);
    return children;
  }

  std::vector<ReferenceDescription> browse_children(
      NodeId const &node_id,
      BrowseResultMask mask,
      NodeClassMask node_class_mask,
      ReferenceTypeIdentifier id) {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Browsing children";
    std::vector<ReferenceDescription> children;
    UA_BrowseRequest browse_req;
    UA_BrowseRequest_init(&browse_req);
    std::shared_ptr<UA_BrowseDescription> browse_desc(new UA_BrowseDescription);
    UA_BrowseDescription_init(browse_desc.get());
    browse_desc->nodeClassMask = node_class_mask;
    browse_req.requestedMaxReferencesPerNode = 0;
    browse_req.nodesToBrowse = browse_desc.get();
    browse_req.nodesToBrowseSize = 1;
    browse_req.nodesToBrowse[0].nodeId = node_id.ua_node_id();
    browse_req.nodesToBrowse[0].resultMask = static_cast<u_int32_t>(mask);
    browse_req.nodesToBrowse[0].referenceTypeId =
        UA_NODEID_NUMERIC(0, static_cast<u_int32_t>(id));
    browse_req.nodesToBrowse[0].includeSubtypes = true;
    UA_BrowseResponse browse_response = browse(browse_req);
    for (size_t i = 0; i < browse_response.resultsSize; ++i) {
      for (size_t j = 0; j < browse_response.results[i].referencesSize; ++j) {
        auto ref =
            ReferenceDescription(browse_response.results[i].references[j]);
        children.push_back(ref);
      }
    }
    UA_BrowseResponse_deleteMembers(&browse_response);
    return children;
  }

  LocalizedText read_display_name_attribute(const NodeId &node_id) {
    UA_LocalizedText out;
    auto status = UA_Client_readDisplayNameAttribute(
        m_client.get(), node_id.ua_node_id(), &out);
    if (status == UA_STATUSCODE_GOOD) {
      return LocalizedText(out);
    }
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
        << "Read display name failed. Error code = " << status;
    return LocalizedText();
  }
};

Client::Client() : d_ptr{new ClientPrivate} {}

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
    BrowseResultMask br_mask,
    NodeClassMask nc_mask,
    ReferenceTypeIdentifier id) {
  return d_ptr->get_child_references(reference, br_mask, nc_mask, id);
}

Client::~Client() = default;

}  // namespace open62541
