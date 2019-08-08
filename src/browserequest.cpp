#include "browserequest.hpp"

namespace open62541 {

class BrowseRequest::impl {
  RequestHeader m_request_header;
  ViewDescription m_view;
  uint32_t m_max_references = 0;
  std::vector<BrowseDescription> m_nodes_to_browse;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(RequestHeader const &request_header,
       ViewDescription const &view,
       uint32_t max_references,
       std::vector<BrowseDescription> const &nodes_to_browse)
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

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return request_header() == rhs.request_header() && view() == rhs.view() &&
           max_references() == rhs.max_references() &&
           nodes_to_browse() == rhs.nodes_to_browse();
  }

  bool operator!=(impl const &rhs) const {
    return request_header() != rhs.request_header() || view() != rhs.view() ||
           max_references() != rhs.max_references() ||
           nodes_to_browse() != rhs.nodes_to_browse();
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

BrowseRequest::~BrowseRequest() = default;

BrowseRequest::BrowseRequest(
    RequestHeader const &request_header,
    ViewDescription const &view,
    uint32_t max_references,
    std::vector<BrowseDescription> const &nodes_to_browse)
    : d_ptr{std::make_unique<impl>(
          request_header, view, max_references, nodes_to_browse)} {}

BrowseRequest &BrowseRequest::operator=(BrowseRequest &&) noexcept = default;

BrowseRequest::BrowseRequest(BrowseRequest &&) noexcept = default;

BrowseRequest::BrowseRequest(BrowseRequest const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

BrowseRequest &BrowseRequest::operator=(BrowseRequest const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

bool BrowseRequest::empty() const { return d_ptr->empty(); }

bool BrowseRequest::operator==(BrowseRequest const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool BrowseRequest::operator!=(BrowseRequest const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
