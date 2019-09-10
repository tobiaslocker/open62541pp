#include "viewdescription.hpp"
#include "ostr.hpp"

namespace open62541 {

class ViewDescription::impl {
  NodeId m_view_id;
  DateTime m_timestamp;
  uint32_t m_view_version = 0;
  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(NodeId const &view_id,
       DateTime const &timestamp,
       uint32_t const &view_version)
      : m_view_id{view_id},
        m_timestamp{timestamp},
        m_view_version{view_version} {}

  NodeId view_id() const { return m_view_id; }

  DateTime timestamp() const { return m_timestamp; }

  uint32_t view_version() const { return m_view_version; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return view_id() == rhs.view_id() && timestamp() == rhs.timestamp() &&
           view_version() == rhs.view_version();
  }

  bool operator!=(impl const &rhs) const {
    return view_id() != rhs.view_id() || timestamp() != rhs.timestamp() ||
           view_version() != rhs.view_version();
  }
};

ViewDescription::ViewDescription(ViewDescription &&) noexcept = default;

ViewDescription::~ViewDescription() = default;

ViewDescription::ViewDescription(ViewDescription const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

ViewDescription &ViewDescription::operator=(ViewDescription const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

ViewDescription::ViewDescription() : d_ptr{std::make_unique<impl>()} {}

ViewDescription::ViewDescription(NodeId const &view_id,
                                 DateTime const &timestamp,
                                 uint32_t view_version)
    : d_ptr{std::make_unique<impl>(view_id, timestamp, view_version)} {}

NodeId ViewDescription::view_id() const { return d_ptr->view_id(); }

DateTime ViewDescription::timestamp() const { return d_ptr->timestamp(); }

uint32_t ViewDescription::view_version() const { return d_ptr->view_version(); }

bool ViewDescription::empty() const { return d_ptr->empty(); }

bool ViewDescription::operator==(ViewDescription const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool ViewDescription::operator!=(ViewDescription const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, ViewDescription const &op) {
  out << "ViewDescription("
      << ostr::fmt(op.view_id(), op.timestamp(), op.view_version()) << ')';
  return out;
}

}  // namespace open62541
