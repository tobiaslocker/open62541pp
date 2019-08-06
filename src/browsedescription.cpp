#include "browsedescription.hpp"

namespace open62541 {

class BrowseDescription::impl {
  NodeId m_node_id;
  BrowseDirection m_browse_direction;
  NodeId m_reference_type_id;
  bool m_include_subtypes;
  uint32_t m_node_class_mask;
  uint32_t m_result_mask;

 public:
  impl() {}

  impl(NodeId node_id,
       BrowseDirection browse_direction,
       NodeId reference_type_id,
       bool include_subtypes,
       uint32_t node_class_mask,
       uint32_t result_mask)
      : m_node_id{node_id},
        m_browse_direction{browse_direction},
        m_reference_type_id{reference_type_id},
        m_include_subtypes{include_subtypes},
        m_node_class_mask{node_class_mask},
        m_result_mask{result_mask} {}

  NodeId node_id() const { return m_node_id; }

  BrowseDirection browse_direction() const { return m_browse_direction; }

  NodeId reference_type_id() const { return m_reference_type_id; }

  bool include_subtypes() const { return m_include_subtypes; }

  uint32_t node_class_mask() const { return m_node_class_mask; }

  uint32_t result_mask() const { return m_result_mask; }

  bool operator==(impl const &rhs) const {
    return node_id() == rhs.node_id() &&
           browse_direction() == rhs.browse_direction() &&
           reference_type_id() == rhs.reference_type_id() &&
           include_subtypes() == rhs.include_subtypes() &&
           node_class_mask() == rhs.node_class_mask() &&
           result_mask() == rhs.result_mask();
  }

  bool operator!=(impl const &rhs) const {
    return node_id() != rhs.node_id() ||
           browse_direction() != rhs.browse_direction() ||
           reference_type_id() != rhs.reference_type_id() ||
           include_subtypes() != rhs.include_subtypes() ||
           node_class_mask() != rhs.node_class_mask() ||
           result_mask() != rhs.result_mask();
  }
};

BrowseDescription::BrowseDescription() : d_ptr{std::make_unique<impl>()} {}

BrowseDescription &BrowseDescription::operator=(BrowseDescription &&) noexcept =
    default;

BrowseDescription::BrowseDescription(BrowseDescription &&) noexcept = default;

BrowseDescription::BrowseDescription(NodeId node_id,
                                     BrowseDirection browse_direction,
                                     NodeId reference_type_id,
                                     bool include_subtypes,
                                     uint32_t node_class_mask,
                                     uint32_t result_mask)
    : d_ptr{std::make_unique<impl>(node_id,
                                   browse_direction,
                                   reference_type_id,
                                   include_subtypes,
                                   node_class_mask,
                                   result_mask)} {}

BrowseDescription::~BrowseDescription() = default;

BrowseDescription::BrowseDescription(BrowseDescription const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

BrowseDescription &BrowseDescription::operator=(BrowseDescription const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

NodeId BrowseDescription::node_id() const { return d_ptr->node_id(); }

BrowseDirection BrowseDescription::browse_direction() const {
  return d_ptr->browse_direction();
}

NodeId BrowseDescription::reference_type_id() const {
  return d_ptr->reference_type_id();
}

bool BrowseDescription::include_subtypes() const {
  return d_ptr->include_subtypes();
}

uint32_t BrowseDescription::node_class_mask() const {
  return d_ptr->node_class_mask();
}

uint32_t BrowseDescription::result_mask() const { return d_ptr->result_mask(); }

bool BrowseDescription::operator==(BrowseDescription const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool BrowseDescription::operator!=(BrowseDescription const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
