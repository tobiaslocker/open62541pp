#include "browseresult.hpp"

#include <algorithm>

namespace open62541 {

class BrowseResult::impl {
  StatusCode m_status_code;
  ByteString m_continuation_point;
  std::vector<ReferenceDescription> m_references;

 public:
  impl() : m_status_code{StatusCode::Good} {}

  impl(StatusCode status_code,
       const ByteString &continuation_point,
       const std::vector<ReferenceDescription> &references)
      : m_status_code{status_code},
        m_continuation_point{continuation_point},
        m_references{references} {}

  StatusCode status_code() const { return m_status_code; }

  ByteString continuation_point() const { return m_continuation_point; }

  std::vector<ReferenceDescription> references() const { return m_references; }

  bool operator==(impl const &rhs) const {
    return status_code() == rhs.status_code() &&
           continuation_point() == rhs.continuation_point() &&
           references() == rhs.references();
  }

  bool operator!=(impl const &rhs) const {
    return status_code() != rhs.status_code() ||
           continuation_point() != rhs.continuation_point() ||
           references() != rhs.references();
  }
};

BrowseResult::BrowseResult() : d_ptr{std::make_unique<impl>()} {}

BrowseResult &BrowseResult::operator=(BrowseResult &&) noexcept = default;

BrowseResult::BrowseResult(BrowseResult &&) noexcept = default;

BrowseResult::BrowseResult(StatusCode status_code,
                           const ByteString &continuation_point,
                           const std::vector<ReferenceDescription> &references)
    : d_ptr{std::make_unique<impl>(
          status_code, continuation_point, references)} {}

StatusCode BrowseResult::status_code() const { return d_ptr->status_code(); }

ByteString BrowseResult::continuation_point() const {
  return d_ptr->continuation_point();
}

std::vector<ReferenceDescription> BrowseResult::references() const {
  return d_ptr->references();
}

BrowseResult::BrowseResult(BrowseResult const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

BrowseResult &BrowseResult::operator=(BrowseResult const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

BrowseResult::~BrowseResult() = default;

bool BrowseResult::operator==(const BrowseResult &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool BrowseResult::operator!=(const BrowseResult &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const BrowseResult &op) {
  out << "BrowseResult(" << op.status_code() << ", " << op.continuation_point()
      << ", [";
  std::for_each(op.references().begin(),
                op.references().end() - 1,
                [&](auto const &u) { out << u << ", "; });
  out << op.references().back();
  out << "])";
  return out;
}

}  // namespace open62541
