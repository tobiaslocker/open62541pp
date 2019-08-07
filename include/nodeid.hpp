#ifndef OPEN62541_CPP_WRAPPER_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_NODE_ID_H

#include "enums.hpp"
#include "identifier.hpp"

namespace open62541 {

class NodeId {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  NodeId();
  ~NodeId();

  NodeId(NodeId &&) noexcept;
  NodeId &operator=(NodeId &&) noexcept;
  NodeId(NodeId const &);
  NodeId &operator=(NodeId const &);

  explicit NodeId(uint16_t namespace_index,
                  Identifier const &identifier,
                  IdentifierType type);

  uint16_t namespace_index() const;
  Identifier identifier() const;
  IdentifierType identifier_type() const;

  bool empty() const;

  bool operator==(NodeId const &rhs) const;
  bool operator!=(NodeId const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, NodeId const &op);

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_NODE_ID_H
