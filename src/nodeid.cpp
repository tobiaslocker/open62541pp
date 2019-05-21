#include "nodeid.hpp"

namespace open62541 {

NodeId::NodeId(uint16_t namespace_index, Identifier const &identifier)
    : m_namespace_index{namespace_index}, m_identifier{identifier} {}

Identifier NodeId::indentifier() const { return m_identifier; }

uint16_t NodeId::namespace_index() const { return m_namespace_index; }

json NodeId::to_json() const {
  //  json node_id;
  //  node_id["NamespaceIndex"] = m_namespace_index;
  //  node_id["IdentifierType"] = m_identifier_type.str();
  //  switch (m_identifier_type) {
  //    case IdentifierType::Guid:
  //      node_id["Identifier"] = m_identifier.guid().str();
  //      break;
  //    case IdentifierType::String:
  //      node_id["Identifier"] = m_identifier.string();
  //      break;
  //    case IdentifierType::Numeric:
  //      node_id["Identifier"] = m_identifier.numeric();
  //      break;
  //    case IdentifierType::ByteString:
  //      node_id["Identifier"] = m_identifier.byte_string();
  //      break;
  //  }
  //  return node_id;
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

}  // namespace open62541
