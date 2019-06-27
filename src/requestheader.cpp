#include "requestheader.hpp"

namespace open62541 {

class RequestHeader::impl {
  NodeId m_authentication_token;
  DateTime m_timestamp;
  uint32_t m_request_handle;
  uint32_t m_return_diagnostics;
  std::string m_audit_entry_id;
  uint32_t m_timeout_hint;
  ExtensionObject m_additional_header;

 public:
  impl() {}

  impl(NodeId const &authentication_token,
       DateTime const &timestamp,
       uint32_t const &request_handle,
       uint32_t const &return_diagnostics,
       std::string const &audit_entry_id,
       uint32_t const &timeout_hint,
       ExtensionObject const &additional_header)
      : m_authentication_token{authentication_token},
        m_timestamp{timestamp},
        m_request_handle{request_handle},
        m_return_diagnostics{return_diagnostics},
        m_audit_entry_id{audit_entry_id},
        m_timeout_hint{timeout_hint},
        m_additional_header{additional_header} {}

  NodeId authentication_token() const { return m_authentication_token; }

  DateTime timestamp() const { return m_timestamp; }

  uint32_t request_handle() const { return m_request_handle; }

  uint32_t return_diagnostics() const { return m_return_diagnostics; }

  std::string audit_entry_id() const { return m_audit_entry_id; }

  uint32_t timeout_hint() const { return m_timeout_hint; }

  ExtensionObject additional_header() const { return m_additional_header; }

  bool operator==(impl const &rhs) const {
    return authentication_token() == rhs.authentication_token() &&
           timestamp() == rhs.timestamp() &&
           request_handle() == rhs.request_handle() &&
           return_diagnostics() == rhs.return_diagnostics() &&
           audit_entry_id() == rhs.audit_entry_id() &&
           timeout_hint() == rhs.timeout_hint() &&
           additional_header() == rhs.additional_header();
  }

  bool operator!=(impl const &rhs) const {
    return authentication_token() != rhs.authentication_token() &&
           timestamp() != rhs.timestamp() &&
           request_handle() != rhs.request_handle() &&
           return_diagnostics() != rhs.return_diagnostics() &&
           audit_entry_id() != rhs.audit_entry_id() &&
           timeout_hint() != rhs.timeout_hint() &&
           additional_header() != rhs.additional_header();
  }
};

RequestHeader::RequestHeader(RequestHeader &&) noexcept = default;

RequestHeader::~RequestHeader() = default;

RequestHeader::RequestHeader(RequestHeader const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

RequestHeader &RequestHeader::operator=(RequestHeader const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

RequestHeader::RequestHeader() : d_ptr{std::make_unique<impl>()} {}

RequestHeader::RequestHeader(NodeId const &authentication_token,
                             DateTime const &timestamp,
                             uint32_t const &request_handle,
                             uint32_t const &return_diagnostics,
                             std::string const &audit_entry_id,
                             uint32_t const &timeout_hint,
                             ExtensionObject const &additional_header)
    : d_ptr{std::make_unique<impl>(authentication_token,
                                   timestamp,
                                   request_handle,
                                   return_diagnostics,
                                   audit_entry_id,
                                   timeout_hint,
                                   additional_header)} {}

NodeId RequestHeader::authentication_token() const {
  return d_ptr->authentication_token();
}

DateTime RequestHeader::timestamp() const { return d_ptr->timestamp(); }

uint32_t RequestHeader::request_handle() const {
  return d_ptr->request_handle();
}

uint32_t RequestHeader::return_diagnostics() const {
  return d_ptr->return_diagnostics();
}

std::string RequestHeader::audit_entry_id() const {
  return d_ptr->audit_entry_id();
}

uint32_t RequestHeader::timeout_hint() const { return d_ptr->timeout_hint(); }

ExtensionObject RequestHeader::additional_header() const {
  return d_ptr->additional_header();
}

bool RequestHeader::operator==(RequestHeader const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool RequestHeader::operator!=(RequestHeader const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
