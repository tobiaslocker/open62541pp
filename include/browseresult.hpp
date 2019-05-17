#ifndef OPEN62541_CPP_WRAPPER_BROWSE_RESULT_H
#define OPEN62541_CPP_WRAPPER_BROWSE_RESULT_H

// STL
#include <memory>

namespace open62541 {

class BrowseResult {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  BrowseResult();
  ~BrowseResult();
  BrowseResult(BrowseResult &&) = default;
  BrowseResult(BrowseResult const &) = delete;
  BrowseResult &operator=(BrowseResult &&);
  BrowseResult &operator=(BrowseResult const &) = delete;
};

class BrowseResult::impl {
  impl() {}
};

BrowseResult::BrowseResult() : d_ptr{std::make_unique<impl>()} {}
BrowseResult::~BrowseResult() = default;
BrowseResult &BrowseResult::operator=(BrowseResult &&) = default;
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_BROWSE_RESULT_H
