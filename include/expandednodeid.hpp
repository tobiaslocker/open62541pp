#ifndef OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H
#define OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H

// STL
#include <string>

#include "nodeid.hpp"

namespace open62541 {

class ExpandedNodeId {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  ~ExpandedNodeId();
  ExpandedNodeId();

  ExpandedNodeId(ExpandedNodeId &&) noexcept;
  ExpandedNodeId &operator=(ExpandedNodeId &&) noexcept;
  ExpandedNodeId(ExpandedNodeId const &);
  ExpandedNodeId &operator=(ExpandedNodeId const &);

  explicit ExpandedNodeId(NodeId const &node_id,
                          std::string const &namespace_uri,
                          uint32_t server_index = 0);

  std::string namespace_uri() const;
  NodeId node_id() const;
  uint32_t server_index() const;

  bool empty() const;

  bool operator==(ExpandedNodeId const &rhs) const;
  bool operator!=(ExpandedNodeId const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, ExpandedNodeId const &op);
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H
