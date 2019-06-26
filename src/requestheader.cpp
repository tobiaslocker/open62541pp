#include "requestheader.hpp"

namespace open62541 {

class RequestHeader::impl {

 public:
  impl() {}
bool operator==(impl const &rhs) const {
}

bool operator!=(impl const &rhs) const {
}
};

RequestHeader::RequestHeader()
    : d_ptr{std::make_unique<impl>()} {}

RequestHeader::RequestHeader(RequestHeader &&) noexcept =
    default;

RequestHeader::~RequestHeader() = default;

RequestHeader::RequestHeader(RequestHeader const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

RequestHeader &RequestHeader::operator=(
    RequestHeader const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}


bool RequestHeader::operator==(RequestHeader const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool RequestHeader::operator!=(RequestHeader const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
