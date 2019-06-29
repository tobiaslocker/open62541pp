#ifndef OPEN6541_CPP_WRAPPER_VIEW_DESCRIPTION_H
#define OPEN6541_CPP_WRAPPER_VIEW_DESCRIPTION_H

// STL
#include <memory>

#include "nodeid.hpp"
#include "datetime.hpp"

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

  bool operator==(ViewDescription const &rhs) const;
  bool operator!=(ViewDescription const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_VIEW_DESCRIPTION_H
