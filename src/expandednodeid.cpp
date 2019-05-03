#include "expandednodeid.hpp"

namespace open62541 {

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

ExpandedNodeId::ExpandedNodeId(UA_ExpandedNodeId const &expanded_node_id)
    : m_node_id{expanded_node_id.nodeId},
      m_namespace_uri{to_std_string(expanded_node_id.namespaceUri)},
      m_server_index{expanded_node_id.serverIndex} {}

ExpandedNodeId::ExpandedNodeId(NodeId const &node_id) : m_node_id{node_id} {}

ExpandedNodeId::ExpandedNodeId(NodeId const &node_id,
                               std::string const &namespace_uri,
                               u_int32_t server_index)
    : m_node_id{node_id},
      m_namespace_uri{namespace_uri},
      m_server_index{server_index} {}

std::string ExpandedNodeId::namespace_uri() const { return m_namespace_uri; }

NodeId ExpandedNodeId::node_id() const { return m_node_id; }

u_int32_t ExpandedNodeId::server_index() const { return m_server_index; }

json ExpandedNodeId::to_json() const {
  json j;
  j["NodeId"] = node_id().to_json();
  j["NamespaceUri"] = namespace_uri();
  j["SeverIndex"] = server_index();
  return j;
}

}  // namespace open62541
