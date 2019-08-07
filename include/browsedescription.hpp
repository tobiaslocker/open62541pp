#ifndef OPEN62541_CPP_WRAPPER_BROWSE_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_BROWSE_DESCRIPTION_H

// STL
#include <memory>

#include "nodeid.hpp"

namespace open62541 {

class BrowseDescription {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseDescription();
  ~BrowseDescription();

  BrowseDescription(BrowseDescription &&) noexcept;
  BrowseDescription &operator=(BrowseDescription &&) noexcept;
  BrowseDescription(BrowseDescription const &);
  BrowseDescription &operator=(BrowseDescription const &);

  BrowseDescription(NodeId const &node_id,
                    BrowseDirection browse_direction,
                    NodeId const &reference_type_id,
                    bool include_subtypes,
                    uint32_t node_class_mask,
                    uint32_t result_mask);

  NodeId node_id() const;
  BrowseDirection browse_direction() const;
  NodeId reference_type_id() const;
  bool include_subtypes() const;
  uint32_t node_class_mask() const;
  uint32_t result_mask() const;

  bool empty() const;

  bool operator==(BrowseDescription const &rhs) const;
  bool operator!=(BrowseDescription const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, BrowseDescription const &op);

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_DESCRIPTION_H
