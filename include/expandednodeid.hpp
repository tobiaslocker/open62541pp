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
  //  ExpandedNodeId(ExpandedNodeId &&) = default;
  //  ExpandedNodeId &operator=(ExpandedNodeId &&);
  //  ExpandedNodeId(ExpandedNodeId const &) = delete;
  //  ExpandedNodeId &operator=(ExpandedNodeId const &) = delete;

  explicit ExpandedNodeId(NodeId const &node_id,
                          std::string const &namespace_uri,
                          uint32_t server_index = 0);
  std::string namespace_uri() const;
  NodeId node_id() const;
  uint32_t server_index() const;

  bool operator==(ExpandedNodeId const &rhs) const;
  bool operator!=(ExpandedNodeId const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_EXPANDED_NODE_ID_H
