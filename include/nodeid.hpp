#ifndef OPEN62541_CPP_WRAPPER_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_NODE_ID_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

#include "enums.hpp"
#include "identifier.hpp"
#include "log.hpp"

namespace open62541 {
using namespace nlohmann;

class NodeId {
  uint16_t m_namespace_index;
  Identifier m_identifier;
  IdentifierType m_identifier_type;

 public:
  NodeId() = default;
  explicit NodeId(json const &node_id);
  explicit NodeId(uint16_t namespace_index, Identifier const &identifier);

  uint16_t namespace_index() const;
  Identifier indentifier() const;
  json to_json() const;

  bool operator==(NodeId const &rhs) const;
  bool operator!=(NodeId const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out, NodeId const &node_id);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_NODE_ID_H
