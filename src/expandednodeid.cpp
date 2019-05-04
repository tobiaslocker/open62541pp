#include "expandednodeid.hpp"

namespace open62541 {

ExpandedNodeId::ExpandedNodeId(UA_ExpandedNodeId const &expanded_node_id)
    : m_node_id{expanded_node_id.nodeId},
      m_server_index{expanded_node_id.serverIndex} {
  if (auto c = reinterpret_cast<char *>(expanded_node_id.namespaceUri.data)) {
      m_namespace_uri = std::string(c);
  }
}

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
  json exp_node_id;
  exp_node_id["NodeId"] = node_id().to_json();
  exp_node_id["NamespaceUri"] = namespace_uri();
  exp_node_id["SeverIndex"] = server_index();
  return exp_node_id;
}

}  // namespace open62541
