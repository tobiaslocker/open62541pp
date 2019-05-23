#ifndef OPEN62541_CPP_WRAPPER_BROWSE_RESULT_H
#define OPEN62541_CPP_WRAPPER_BROWSE_RESULT_H

// STL
#include <memory>
#include <vector>

#include "bytestring.hpp"
#include "enums.hpp"
#include "referencedescription.hpp"

namespace open62541 {

class BrowseResult {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseResult();
  ~BrowseResult();

  BrowseResult(BrowseResult &&) noexcept;
  BrowseResult &operator=(BrowseResult &&) noexcept;
  BrowseResult(BrowseResult const &);
  BrowseResult &operator=(BrowseResult const &);

  BrowseResult(StatusCode status_code,
               ByteString const &continuation_point,
               std::vector<ReferenceDescription> const &references);

  StatusCode status_code() const;
  ByteString continuation_point() const;
  std::vector<ReferenceDescription> references() const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_RESULT_H
