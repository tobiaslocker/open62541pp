#ifndef OPEN62541_CPP_WRAPPER_BROWSE_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_BROWSE_DESCRIPTION_H

// STL
#include <memory>

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
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_DESCRIPTION_H
