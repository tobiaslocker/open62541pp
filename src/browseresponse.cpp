#include "browseresponse.hpp"

#include <algorithm>

namespace open62541 {

class BrowseResponse::impl {
  ResponseHeader m_response_header;
  std::vector<BrowseResult> m_results;
  std::vector<DiagnosticInfo> m_diagnostic_infos;

 public:
  impl() {}

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

BrowseResponse::~BrowseResponse() = default;

BrowseResponse &BrowseResponse::operator=(BrowseResponse &&) = default;

BrowseResponse::BrowseResponse() : d_ptr{std::make_unique<impl>()} {}

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

bool BrowseResponse::operator==(BrowseResponse const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool BrowseResponse::operator!=(BrowseResponse const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const BrowseResponse &op) {
  out << "BrowseResponse(" << op.response_header() << ", [";
  std::for_each(op.results().begin(),
                op.results().end() - 1,
                [&](BrowseResult const &u) { out << u << ", "; });
  out << op.results().back();

  out << "], [";
  std::for_each(op.diagnostic_infos().begin(),
                op.diagnostic_infos().end() - 1,
                [&](auto const &u) { out << u << ", "; });
  out << op.diagnostic_infos().back();
  out << "])";
  return out;
}

}  // namespace open62541
