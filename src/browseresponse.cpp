#include "browseresponse.hpp"
#include "ostr.hpp"

namespace open62541 {

class BrowseResponse::impl {
  ResponseHeader m_response_header;
  std::vector<BrowseResult> m_results;
  std::vector<DiagnosticInfo> m_diagnostic_infos;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(const ResponseHeader &response_header,
       const std::vector<BrowseResult> &results,
       const std::vector<DiagnosticInfo> &diagnostic_infos)
      : m_response_header{response_header},
        m_results{results},
        m_diagnostic_infos{diagnostic_infos} {}

  ResponseHeader response_header() const { return m_response_header; }

  std::vector<BrowseResult> results() const { return m_results; }

  std::vector<DiagnosticInfo> diagnostic_infos() const {
    return m_diagnostic_infos;
  }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return response_header() == rhs.response_header() &&
           results() == rhs.results() &&
           diagnostic_infos() == rhs.diagnostic_infos();
  }

  bool operator!=(impl const &rhs) const {
    return response_header() != rhs.response_header() ||
           results() != rhs.results() ||
           diagnostic_infos() != rhs.diagnostic_infos();
  }
};

BrowseResponse::BrowseResponse() : d_ptr{std::make_unique<impl>()} {}

BrowseResponse::~BrowseResponse() = default;

BrowseResponse &BrowseResponse::operator=(BrowseResponse &&) noexcept = default;

BrowseResponse::BrowseResponse(BrowseResponse &&) noexcept = default;

BrowseResponse::BrowseResponse(BrowseResponse const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

BrowseResponse &BrowseResponse::operator=(BrowseResponse const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

BrowseResponse::BrowseResponse(
    ResponseHeader const &response_header,
    std::vector<BrowseResult> const &results,
    std::vector<DiagnosticInfo> const &diagnostic_infos)
    : d_ptr{
          std::make_unique<impl>(response_header, results, diagnostic_infos)} {}

ResponseHeader BrowseResponse::response_header() const {
  return d_ptr->response_header();
}

std::vector<BrowseResult> BrowseResponse::results() const {
  return d_ptr->results();
}

std::vector<DiagnosticInfo> BrowseResponse::diagnostic_infos() const {
  return d_ptr->diagnostic_infos();
}

bool BrowseResponse::empty() const { return d_ptr->empty(); }

bool BrowseResponse::operator==(BrowseResponse const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool BrowseResponse::operator!=(BrowseResponse const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const BrowseResponse &op) {
  return out << "BrowseResponse("
             << ostr::fmt(
                    op.response_header(), op.results(), op.diagnostic_infos())
             << ')';
}

}  // namespace open62541
