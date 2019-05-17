#ifndef OPEN62541_CPP_WRAPPER_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_NODE_ID_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

#include "identifier.hpp"
#include "log.hpp"

namespace open62541 {
using namespace nlohmann;

class NodeId {
  uint16_t m_namespace_index;
  Identifier m_identifier;
  IdentifierType m_identifier_type;
  UA_NodeId m_ua_node_id;

 public:
  UA_NodeId ua_node_id() const;
  explicit NodeId(UA_NodeId const &node_id);
  explicit NodeId(json const &node_id);
  explicit NodeId(uint16_t namespace_index, Identifier const &identifier);
  uint16_t namespace_index() const;
  Identifier indentifier() const;
  json to_json() const;
  bool operator==(NodeId const &rhs) const;
  bool operator!=(NodeId const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out, NodeId const &node_id);
  friend class ReferenceDescription;
  friend class ExpandedNodeId;
  friend class Node;
  friend class ClientPrivate;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_NODE_ID_H
