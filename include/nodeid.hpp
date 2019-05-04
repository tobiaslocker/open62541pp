#ifndef OPEN62541_CPP_WRAPPER_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_NODE_ID_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

#include "identifier.hpp"
#include "log.hpp"
#include "nodeid.hpp"

namespace open62541 {

using namespace nlohmann;

class NodeId {
  u_int16_t m_namespace_index;
  explicit NodeId(UA_NodeId const &node_id);

 public:
  explicit NodeId(json const &node_id);
  explicit NodeId(uint16_t namespace_index, Identifier const &identifier);

  Identifier indentifier() const;
  u_int16_t namespace_index() const;
  json to_json() const;

 private:
  UA_NodeId ua_node_id() const;

  Identifier m_id;
  friend class ReferenceDescription;
  friend class ExpandedNodeId;
  friend class Node;
  friend class Client;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_NODE_ID_H
