#ifndef OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H

#include "open62541.h"

// STL
#include <string>

// Dependencies
#include <nlohmann/json.hpp>

#include "log.hpp"
#include "nodeid.hpp"

namespace open62541 {

using namespace logger;
using namespace nlohmann;

class ExpandedNodeId {
  NodeId m_node_id;
  std::string m_namespace_uri;
  uint32_t m_server_index = 0;

 public:
  //  explicit ExpandedNodeId(NodeId const &node_id);
  explicit ExpandedNodeId(NodeId const &node_id,
                          std::string const &namespace_uri,
                          uint32_t server_index = 0);
  std::string namespace_uri() const;
  NodeId node_id() const;
  uint32_t server_index() const;

  //  json to_json() const;

  bool operator==(ExpandedNodeId const &rhs) const;
  bool operator!=(ExpandedNodeId const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  ExpandedNodeId const &expanded_node_id);

  friend class ReferenceDescription;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H
