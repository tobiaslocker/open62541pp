#ifndef OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H
#define OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H

// STL
#include <memory>
#include <vector>

#include "browsedescription.hpp"

namespace open62541 {

class RequestHeader {
  // TODO
};

class ViewDescription {
  // TODO
};

class BrowseRequest {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseRequest();

  BrowseRequest(RequestHeader const &request_header,
                ViewDescription const &view,
                uint32_t max_references,
                std::vector<BrowseDescription> const &nodes_to_browse);

  ~BrowseRequest();
  BrowseRequest(BrowseRequest &&) = default;
  BrowseRequest &operator=(BrowseRequest &&);
  BrowseRequest(BrowseRequest const &) = delete;
  BrowseRequest &operator=(BrowseRequest const &) = delete;

  RequestHeader request_header() const;
  ViewDescription view() const;
  uint32_t max_references() const;
  std::vector<BrowseDescription> nodes_to_browse() const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H
