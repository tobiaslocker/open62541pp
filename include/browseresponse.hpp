#ifndef OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H
#define OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H

// STL
#include <memory>
#include <vector>

#include "browseresult.hpp"

namespace open62541 {

class ResponseHeader {
  // TODO
};

class DiagnosticInfo {
  // TODO
};

class BrowseResponse {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseResponse();
  BrowseResponse(ResponseHeader const &response_header,
                 std::vector<BrowseResult> const &results,
                 std::vector<DiagnosticInfo> const &diagnostic_infos);
  ~BrowseResponse();
  BrowseResponse(BrowseResponse &&) = default;
  BrowseResponse(BrowseResponse const &) = delete;
  BrowseResponse &operator=(BrowseResponse &&);
  BrowseResponse &operator=(BrowseResponse const &) = delete;

  ResponseHeader response_header() const;
  std::vector<BrowseResult> results() const;
  std::vector<DiagnosticInfo> diagnostic_infos() const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H
