#include "browseresponse.hpp"

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

}  // namespace open62541
