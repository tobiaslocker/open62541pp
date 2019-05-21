#include "nodeid.hpp"

namespace open62541 {

NodeId::NodeId(json const &node_id) : m_namespace_index{node_id["Namespace"]} {
  /*
   * The IdentifierType encoded as a JSON number.
   * Allowed values are:
   * 0 - UInt32 Identifier encoded as a JSON number.
   * 1 - A String Identifier encoded as a JSON string.
   * 2 - A Guid Identifier encoded as described in 5.4.2.7.
   * 3 - A ByteString Identifier encoded as described in 5.4.2.8.
   * This field is omitted for UInt32 identifiers.
   */

  if (node_id["IdType"].is_number()) {
    auto id = node_id["Id"];
    auto id_type = node_id["IdType"].get<int>();
    switch (id_type) {
      case 0:
        m_identifier = Identifier(id.get<uint32_t>());
        break;
      case 1:
        m_identifier = Identifier(id.get<std::string>());
        break;
      case 2:
        m_identifier = Identifier(Guid(id.get<std::string>()));
        break;
      case 3:
        m_identifier =
            Identifier(ByteString::from_base_64(id.get<std::string>()));
        break;
      default:
        // TODO: handle error case
        break;
    }

  } else {
  }
}

NodeId::NodeId(uint16_t namespace_index, Identifier const &identifier)
    : m_namespace_index{namespace_index}, m_identifier{identifier} {}

Identifier NodeId::indentifier() const { return m_identifier; }

uint16_t NodeId::namespace_index() const { return m_namespace_index; }

json NodeId::to_json() const {
  json node_id;
  node_id["NamespaceIndex"] = m_namespace_index;
  node_id["IdentifierType"] = m_identifier_type.str();
  switch (m_identifier_type) {
    case IdentifierType::Guid:
      node_id["Identifier"] = m_identifier.guid().str();
      break;
    case IdentifierType::String:
      node_id["Identifier"] = m_identifier.string();
      break;
    case IdentifierType::Numeric:
      node_id["Identifier"] = m_identifier.numeric();
      break;
    case IdentifierType::ByteString:
      node_id["Identifier"] = m_identifier.byte_string();
      break;
  }
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
