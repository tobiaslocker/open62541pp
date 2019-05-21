#include "browserequest.hpp"

namespace open62541 {

class BrowseRequest::impl {
  RequestHeader m_request_header;
  ViewDescription m_view;
  uint32_t m_max_references;
  std::vector<BrowseDescription> m_nodes_to_browse;

 public:
  impl() {}
  impl(RequestHeader request_header,
       ViewDescription view,
       uint32_t max_references,
       std::vector<BrowseDescription> nodes_to_browse)
      : m_request_header{request_header},
        m_view{view},
        m_max_references{max_references},
        m_nodes_to_browse{nodes_to_browse} {}

  RequestHeader request_header() const { return m_request_header; }

  ViewDescription view() const { return m_view; }

  uint32_t max_references() const { return m_max_references; }

  std::vector<BrowseDescription> nodes_to_browse() const {
    return m_nodes_to_browse;
  }
};

RequestHeader BrowseRequest::request_header() const {
  return d_ptr->request_header();
}

ViewDescription BrowseRequest::view() const { return d_ptr->view(); }

uint32_t BrowseRequest::max_references() const {
  return d_ptr->max_references();
}

std::vector<BrowseDescription> BrowseRequest::nodes_to_browse() const {
  return d_ptr->nodes_to_browse();
}

BrowseRequest::BrowseRequest() : d_ptr{std::make_unique<impl>()} {}

BrowseRequest::BrowseRequest(RequestHeader request_header,
                             ViewDescription view,
                             uint32_t max_references,
                             std::vector<BrowseDescription> nodes_to_browse)
    : d_ptr{std::make_unique<impl>(
          request_header, view, max_references, nodes_to_browse)} {}

BrowseRequest::~BrowseRequest() = default;

BrowseRequest &BrowseRequest::operator=(BrowseRequest &&) = default;

}  // namespace open62541
