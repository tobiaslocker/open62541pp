#include "nodeid.hpp"
#include "parser.hpp"

namespace open62541 {

NodeId::NodeId(uint16_t namespace_index,
               Identifier const &identifier,
               IdentifierType type)
    : m_namespace_index{namespace_index},
      m_identifier{identifier},
      m_identifier_type{type} {}

Identifier NodeId::identifier() const { return m_identifier; }

IdentifierType NodeId::identifier_type() const { return m_identifier_type; }

uint16_t NodeId::namespace_index() const { return m_namespace_index; }

bool NodeId::operator==(const NodeId &rhs) const {
  return identifier() == rhs.identifier() &&
         namespace_index() == rhs.namespace_index();
}

bool NodeId::operator!=(const NodeId &rhs) const {
  return identifier() != rhs.identifier() &&
         namespace_index() != rhs.namespace_index();
}

std::ostream &operator<<(std::ostream &out, const NodeId &node_id) {
  auto j = parser::to_json(node_id);
  out << j;
  return out;
}

}  // namespace open62541
