#include "browserequest.hpp"

namespace open62541 {

class BrowseRequest::impl {
//  std::vector<BrowseDescription> m_nodes_to_browse;
  u_int32_t m_max_references;

 public:
  impl() {}

//  std::vector<BrowseDescription> nodes_to_browse() { return m_nodes_to_browse; }

  u_int32_t max_references() { return m_max_references; }
};

//std::vector<BrowseDescription> BrowseRequest::nodes_to_browse() {
//  return d_ptr->nodes_to_browse();
//}

u_int32_t BrowseRequest::max_references() { return d_ptr->max_references(); }

BrowseRequest::BrowseRequest() : d_ptr{std::make_unique<impl>()} {}

BrowseRequest::~BrowseRequest() = default;

BrowseRequest &BrowseRequest::operator=(BrowseRequest &&) = default;

}  // namespace open62541
