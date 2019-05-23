#ifndef OPEN62541_CPP_WRAPPER_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_NODE_ID_H

#include "enums.hpp"
#include "identifier.hpp"

namespace open62541 {

class NodeId {
  uint16_t m_namespace_index;
  Identifier m_identifier;
  IdentifierType m_identifier_type;

 public:
  NodeId() = default;
  explicit NodeId(uint16_t namespace_index,
                  Identifier const &identifier,
                  IdentifierType type);

  uint16_t namespace_index() const;
  Identifier identifier() const;
  IdentifierType identifier_type() const;

  bool operator==(NodeId const &rhs) const;
  bool operator!=(NodeId const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out, NodeId const &node_id);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_NODE_ID_H
