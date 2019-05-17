#ifndef OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H
#define OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H

// STL
#include <memory>
#include <vector>

#include "browsedescription.hpp"

namespace open62541 {

class BrowseRequest {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseRequest();
  ~BrowseRequest();
  BrowseRequest(BrowseRequest &&) = default;
  BrowseRequest &operator=(BrowseRequest &&);
  BrowseRequest(BrowseRequest const &) = delete;
  BrowseRequest &operator=(BrowseRequest const &) = delete;
  std::vector<BrowseDescription> nodes_to_browse();
  uint32_t max_references();
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H
