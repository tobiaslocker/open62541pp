#ifndef OPEN62541PP_VIEW_DESCRIPTION_H
#define OPEN62541PP_VIEW_DESCRIPTION_H

// STL
#include <memory>

#include "datetime.hpp"
#include "nodeid.hpp"

namespace open62541 {

class ViewDescription {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  ViewDescription();
  ~ViewDescription();

  ViewDescription(ViewDescription &&) noexcept;
  ViewDescription &operator=(ViewDescription &&) noexcept;
  ViewDescription(ViewDescription const &);
  ViewDescription &operator=(ViewDescription const &);

  ViewDescription(NodeId const &view_id,
                  DateTime const &timestamp,
                  uint32_t view_version);

  NodeId view_id() const;
  DateTime timestamp() const;
  uint32_t view_version() const;

  bool empty() const;

  bool operator==(ViewDescription const &rhs) const;
  bool operator!=(ViewDescription const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, ViewDescription const &op);
}  // namespace open62541

#endif  // OPEN62541PP_VIEW_DESCRIPTION_H
