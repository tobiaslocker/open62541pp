#include "client.hpp"

#include "node.hpp"

namespace open62541 {

bool status_is_good(UA_StatusCode status) {
  if (status != UA_STATUSCODE_GOOD) {
    return false;
  }
  return true;
}

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
  if (status_is_good(
          UA_Client_getEndpoints(m_client.get(), url.c_str(), &len, &arr))) {
    for (size_t i = 0; i < len; i++) {
      result.push_back(EndpointDescription(arr[i]));
    }
  }
  UA_Array_delete(arr, len, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION]);
  return result;
}

void Client::connect_to_endpoint(std::string const &url) {
  if (status_is_good(UA_Client_connect(m_client.get(), url.c_str()))) {
    // TODO set state?
  }
}

void Client::connect_to_endpoint(EndpointDescription const &endpoint) {
  if (status_is_good(UA_Client_connect(
          m_client.get(),
          endpoint.to_json()["EndpointUrl"].get<std::string>().c_str()))) {
    // TODO set state?
  }
}

std::shared_ptr<Node> Client::node(NodeId const &node_id) {
  return std::make_shared<Node>(node_id, shared_from_this());
}

std::shared_ptr<Client> Client::client() { return shared_from_this(); }

std::shared_ptr<Client> Client::create() {
  return std::shared_ptr<Client>(new Client());
}

LocalizedText Client::read_display_name_attribute(const NodeId &node_id) const {
  UA_LocalizedText out;
  if (status_is_good(UA_Client_readDisplayNameAttribute(
          m_client.get(), node_id.ua_node_id(), &out))) {
    return LocalizedText(out);
  }
  return LocalizedText();
}

}  // namespace open62541
