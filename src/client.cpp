#include "client.hpp"
#include "endpointdescription.hpp"
#include "node.hpp"
#include "nodeid.hpp"

namespace open62541 {

Client::Client()
    : m_client{std::shared_ptr<UA_Client>(
          UA_Client_new(UA_ClientConfig_default), UA_Client_delete)} {
  BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Creating client";
}

UA_BrowseResponse Client::browse(const UA_BrowseRequest &request) {
  UA_BrowseResponse browse_response =
      UA_Client_Service_browse(m_client.get(), request);
  return browse_response;
}

std::vector<EndpointDescription> Client::get_endpoints(std::string const &url) {
  std::vector<EndpointDescription> result;
  UA_EndpointDescription *arr = nullptr;
  size_t len = 0;
  auto status = UA_Client_getEndpoints(m_client.get(), url.c_str(), &len, &arr);
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

void Client::connect_to_endpoint(std::string const &url) {
  auto status = UA_Client_connect(m_client.get(), url.c_str());
  if (status == UA_STATUSCODE_GOOD) {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info) << "Connected to " << url;
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
        << "Connect failed. Status code = " << status;
  }
}

void Client::connect_to_endpoint(EndpointDescription const &endpoint) {
  auto url = endpoint.to_json()["EndpointUrl"].get<std::string>();
  auto status = UA_Client_connect(m_client.get(), url.c_str());
  if (status == UA_STATUSCODE_GOOD) {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, info) << "Connected to " << url;
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, error)
        << "Connect failed. Status code = " << status;
  }
}

std::shared_ptr<Node> Client::node(NodeId const &node_id) {
  return std::make_shared<Node>(node_id, shared_from_this());
}

LocalizedText Client::read_display_name_attribute(const NodeId &node_id) {
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

std::shared_ptr<Client> Client::client() { return shared_from_this(); }

std::shared_ptr<Client> Client::create() {
  return std::shared_ptr<Client>(new Client());
}

}  // namespace open62541
