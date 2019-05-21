#include "browsedescription.hpp"

namespace open62541 {

class BrowseDescription::impl {
 public:
  impl() {}
};

BrowseDescription::BrowseDescription() : d_ptr{std::make_unique<impl>()} {}

BrowseDescription::BrowseDescription(BrowseDescription const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

BrowseDescription &BrowseDescription::operator=(BrowseDescription const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

}  // namespace open62541
