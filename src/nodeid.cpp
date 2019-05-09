#include "nodeid.hpp"

namespace open62541 {

NodeId::NodeId(UA_NodeId const &node_id)
    : m_namespace_index{node_id.namespaceIndex},
      m_identifier_type{node_id.identifierType},
      m_ua_node_id{node_id} {
  switch (m_identifier_type) {
    case IdentifierType::Guid:
      m_identifier = Identifier(node_id.identifier.guid);
      break;
    case IdentifierType::Numeric:
      m_identifier = Identifier(node_id.identifier.numeric);
      break;
    case IdentifierType::String:
      m_identifier = Identifier(node_id.identifier.string);
      break;
    case IdentifierType::ByteString:
      m_identifier = Identifier(node_id.identifier.string);
      break;
  }
}

NodeId::NodeId(json const &node_id)
    : m_namespace_index{node_id["NamespaceIndex"]},
      m_identifier{Identifier(node_id["Identifier"])} {}

NodeId::NodeId(uint16_t namespace_index, Identifier const &identifier)
    : m_namespace_index{namespace_index}, m_identifier{identifier} {}

Identifier NodeId::indentifier() const { return m_identifier; }

u_int16_t NodeId::namespace_index() const { return m_namespace_index; }

json NodeId::to_json() const {
  json node_id;
  node_id["NamespaceIndex"] = m_namespace_index;
  node_id["IdentifierType"] = m_identifier_type.to_string();
  // node_id["Identifier"] = m_identifier.to_json_value();
  node_id["Identifier"] = m_identifier.to_string();
  return node_id;
}

bool NodeId::operator==(const NodeId &rhs) const {
  return indentifier() == rhs.indentifier() &&
         namespace_index() == rhs.namespace_index();
}

bool NodeId::operator!=(const NodeId &rhs) const {
  return indentifier() != rhs.indentifier() &&
         namespace_index() != rhs.namespace_index();
}

std::ostream &operator<<(std::ostream &out, const NodeId &node_id) {
  auto j = node_id.to_json();
  out << j;
  return out;
}

UA_NodeId NodeId::ua_node_id() const { return m_ua_node_id; }

}  // namespace open62541
