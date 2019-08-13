#ifndef OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H
#define OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H

// STL
#include <memory>
#include <vector>

#include "browseresult.hpp"
#include "diagnosticinfo.hpp"
#include "responseheader.hpp"

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

  BrowseResponse(ResponseHeader const &response_header,
                 std::vector<BrowseResult> const &results,
                 std::vector<DiagnosticInfo> const &diagnostic_infos);

  ResponseHeader response_header() const;
  std::vector<BrowseResult> results() const;
  std::vector<DiagnosticInfo> diagnostic_infos() const;

  bool operator==(BrowseResponse const &rhs) const;
  bool operator!=(BrowseResponse const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, BrowseResponse const &op);
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_RESPONSE_H
