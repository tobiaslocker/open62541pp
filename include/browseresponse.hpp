#ifndef OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H
#define OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H

// STL
#include <memory>

namespace open62541 {

class BrowseResponse {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseResponse();
  ~BrowseResponse();
  BrowseResponse(BrowseResponse &&) = default;
  BrowseResponse(BrowseResponse const &) = delete;
  BrowseResponse &operator=(BrowseResponse &&);
  BrowseResponse &operator=(BrowseResponse const &) = delete;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H
