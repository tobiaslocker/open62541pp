#include "nodeid.hpp"

namespace open62541 {

NodeId::NodeId(UA_NodeId const &node_id)
    : m_namespace_index{node_id.namespaceIndex},
      m_id{Identifier::from_node_id(node_id)} {}

NodeId::NodeId(json const &node_id)
    : m_namespace_index{node_id["NamespaceIndex"]},
      m_id{Identifier(node_id["Identifier"])} {}

NodeId::NodeId(uint16_t namespace_index, Identifier const &identifier)
    : m_namespace_index{namespace_index}, m_id{identifier} {}

Identifier NodeId::indentifier() const { return m_id; }

u_int16_t NodeId::namespace_index() const { return m_namespace_index; }

json NodeId::to_json() const {
  json node_id;
  node_id["NamespaceIndex"] = m_namespace_index;
  node_id["IdentifierType"] = m_id.type_to_string();
  node_id["Identifier"] = m_id.to_json_value();
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

UA_NodeId NodeId::ua_node_id() const {
  UA_NodeId ua_node;
  switch (indentifier().type()) {
    case Identifier::Type::Numeric:
      ua_node = UA_NODEID_NUMERIC(namespace_index(), indentifier().numeric());
      break;
    case Identifier::Type::String:
      ua_node = UA_NODEID_STRING_ALLOC(namespace_index(),
                                       indentifier().string().c_str());
      break;
    case Identifier::Type::ByteString:
      break;
    case Identifier::Type::Guid:
      break;
  }
  return ua_node;
}

}  // namespace open62541
