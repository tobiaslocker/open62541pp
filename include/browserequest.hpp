#ifndef OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H
#define OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H

// STL
#include <memory>
#include <vector>

#include "browsedescription.hpp"
#include "requestheader.hpp"
#include "viewdescription.hpp"

namespace open62541 {

class BrowseRequest {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseRequest();
  ~BrowseRequest();

  BrowseRequest(BrowseRequest &&) noexcept;
  BrowseRequest &operator=(BrowseRequest &&) noexcept;
  BrowseRequest(BrowseRequest const &);
  BrowseRequest &operator=(BrowseRequest const &);

  BrowseRequest(RequestHeader const &request_header,
                ViewDescription const &view,
                uint32_t max_references,
                std::vector<BrowseDescription> const &nodes_to_browse);

  RequestHeader request_header() const;
  ViewDescription view() const;
  uint32_t max_references() const;
  std::vector<BrowseDescription> nodes_to_browse() const;

  bool empty() const;

  bool operator==(BrowseRequest const &rhs) const;
  bool operator!=(BrowseRequest const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, BrowseRequest const &op);
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_REQUEST_H
