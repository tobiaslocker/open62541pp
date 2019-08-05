#include "referencedescription.hpp"

namespace open62541 {

class ReferenceDescription::impl {
  NodeId m_reference_type_id;
  bool m_is_forward;
  ExpandedNodeId m_node_id;
  QualifiedName m_browse_name;
  LocalizedText m_display_name;
  NodeClass m_node_class;
  ExpandedNodeId m_type_definition;

 public:
  impl() {}
  impl(NodeId const &reference_type_id,
       bool is_forward,
       ExpandedNodeId const &node_id,
       QualifiedName const &browse_name,
       LocalizedText const &display_name,
       NodeClass const &node_class,
       ExpandedNodeId const &type_definition)
      : m_reference_type_id{reference_type_id},
        m_is_forward{is_forward},
        m_node_id{node_id},
        m_browse_name{browse_name},
        m_display_name{display_name},
        m_node_class{node_class},
        m_type_definition{type_definition} {}

  NodeId reference_type_id() const { return m_reference_type_id; }

  bool is_forward() const { return m_is_forward; }

  ExpandedNodeId node_id() const { return m_node_id; }

  LocalizedText display_name() const { return m_display_name; }

  NodeClass node_class() const { return m_node_class; }

  QualifiedName browse_name() const { return m_browse_name; }

  ExpandedNodeId type_definition() const { return m_type_definition; }

  bool operator==(impl const &rhs) const {
    return node_id() == rhs.node_id() && display_name() == rhs.display_name() &&
           browse_name() == rhs.browse_name() &&
           type_definition() == rhs.type_definition();
  }

  bool operator!=(impl const &rhs) const {
    return node_id() != rhs.node_id() || display_name() != rhs.display_name() ||
           browse_name() != rhs.browse_name() ||
           type_definition() != rhs.type_definition();
  }
};

ReferenceDescription::ReferenceDescription()
    : d_ptr{std::make_unique<impl>()} {}

ReferenceDescription::ReferenceDescription(ReferenceDescription &&) noexcept =
    default;

ReferenceDescription::~ReferenceDescription() = default;

ReferenceDescription::ReferenceDescription(ReferenceDescription const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

ReferenceDescription &ReferenceDescription::operator=(
    ReferenceDescription const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

ReferenceDescription::ReferenceDescription(
    const NodeId &reference_type_id,
    bool is_forward,
    const ExpandedNodeId &node_id,
    QualifiedName const &browse_name,
    LocalizedText const &display_name,
    const NodeClass &node_class,
    ExpandedNodeId const &type_definition)
    : d_ptr{std::make_unique<impl>(reference_type_id,
                                   is_forward,
                                   node_id,
                                   browse_name,
                                   display_name,
                                   node_class,
                                   type_definition)} {}

NodeId ReferenceDescription::reference_type_id() const {
  return d_ptr->reference_type_id();
}

bool ReferenceDescription::is_forward() const { return d_ptr->is_forward(); }

ExpandedNodeId ReferenceDescription::node_id() const {
  return d_ptr->node_id();
}

LocalizedText ReferenceDescription::display_name() const {
  return d_ptr->display_name();
}

NodeClass ReferenceDescription::node_class() const {
  return d_ptr->node_class();
}

QualifiedName ReferenceDescription::browse_name() const {
  return d_ptr->browse_name();
}

ExpandedNodeId ReferenceDescription::type_definition() const {
  return d_ptr->type_definition();
}

bool ReferenceDescription::operator==(ReferenceDescription const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool ReferenceDescription::operator!=(ReferenceDescription const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
