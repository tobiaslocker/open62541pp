#include "expandednodeid.hpp"
#include "ostr.hpp"

namespace open62541 {

class ExpandedNodeId::impl {
  NodeId m_node_id;
  std::string m_namespace_uri;
  uint32_t m_server_index = 0;

 public:
  impl() {}
  impl(NodeId const &node_id,
       std::string const &namespace_uri,
       uint32_t server_index)
      : m_node_id{node_id},
        m_namespace_uri{namespace_uri},
        m_server_index{server_index} {}

  std::string namespace_uri() const { return m_namespace_uri; }

  NodeId node_id() const { return m_node_id; }

  uint32_t server_index() const { return m_server_index; }

  bool operator==(impl const &rhs) const {
    return namespace_uri() == rhs.namespace_uri() &&
           node_id() == rhs.node_id() && server_index() == rhs.server_index();
  }

  bool operator!=(impl const &rhs) const {
    return namespace_uri() != rhs.namespace_uri() ||
           node_id() != rhs.node_id() || server_index() != rhs.server_index();
  }
};

ExpandedNodeId::ExpandedNodeId(NodeId const &node_id,
                               std::string const &namespace_uri,
                               uint32_t server_index)
    : d_ptr{std::make_unique<impl>(node_id, namespace_uri, server_index)} {}

ExpandedNodeId::ExpandedNodeId() : d_ptr{std::make_unique<impl>()} {}

ExpandedNodeId::ExpandedNodeId(ExpandedNodeId &&) noexcept = default;

ExpandedNodeId::~ExpandedNodeId() = default;

ExpandedNodeId::ExpandedNodeId(ExpandedNodeId const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

ExpandedNodeId &ExpandedNodeId::operator=(ExpandedNodeId const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

std::string ExpandedNodeId::namespace_uri() const {
  return d_ptr->namespace_uri();
}

NodeId ExpandedNodeId::node_id() const { return d_ptr->node_id(); }

uint32_t ExpandedNodeId::server_index() const { return d_ptr->server_index(); }

bool ExpandedNodeId::operator==(ExpandedNodeId const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool ExpandedNodeId::operator!=(ExpandedNodeId const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const ExpandedNodeId &op) {
  return out << "ExpandedNodeId("
             << ostr::fmt(op.node_id(), op.namespace_uri(), op.server_index())
             << ')';
}

}  // namespace open62541
