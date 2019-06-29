#include "responseheader.hpp"

namespace open62541 {

class ResponseHeader::impl {
  DateTime m_timestamp;
  uint32_t m_request_handle;
  StatusCode m_service_result;
  std::vector<std::string> m_string_table;
  DiagnosticInfo m_service_diagnostics;
  ExtensionObject m_additional_header;

 public:
  impl() {}

  impl(DateTime timestamp,
       uint32_t request_handle,
       StatusCode service_result,
       std::vector<std::string> string_table,
       DiagnosticInfo service_diagnostics,
       ExtensionObject additional_header)
      : m_timestamp{timestamp},
        m_request_handle{request_handle},
        m_service_result{service_result},
        m_string_table{string_table},
        m_service_diagnostics{service_diagnostics},
        m_additional_header{additional_header} {}

  DateTime timestamp() const { return m_timestamp; }

  uint32_t request_handle() const { return m_request_handle; }

  StatusCode service_result() const { return m_service_result; }

  DiagnosticInfo service_diagnostics() const { return m_service_diagnostics; }

  std::vector<std::string> string_table() const { return m_string_table; }

  ExtensionObject additional_header() const { return m_additional_header; }

  bool operator==(impl const &rhs) const {
    return timestamp() == rhs.timestamp() &&
           request_handle() == rhs.request_handle() &&
           service_result() == rhs.service_result() &&
           service_diagnostics() == rhs.service_diagnostics() &&
           string_table() == rhs.string_table() &&
           additional_header() == rhs.additional_header();
  }

  bool operator!=(impl const &rhs) const {
    return timestamp() == rhs.timestamp() &&
           request_handle() == rhs.request_handle() &&
           service_result() == rhs.service_result() &&
           service_diagnostics() == rhs.service_diagnostics() &&
           string_table() == rhs.string_table() &&
           additional_header() == rhs.additional_header();
  }
};

ResponseHeader::ResponseHeader(ResponseHeader &&) noexcept = default;

ResponseHeader::~ResponseHeader() = default;

ResponseHeader::ResponseHeader(ResponseHeader const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

ResponseHeader &ResponseHeader::operator=(ResponseHeader const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

ResponseHeader::ResponseHeader() : d_ptr{std::make_unique<impl>()} {}

ResponseHeader::ResponseHeader(NodeId const &authentication_token,
                               std::string const &timestamp,
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

NodeId ResponseHeader::authentication_token() const {
  return d_ptr->authentication_token();
}

std::string ResponseHeader::timestamp() const { return d_ptr->timestamp(); }

uint32_t ResponseHeader::request_handle() const {
  return d_ptr->request_handle();
}

uint32_t ResponseHeader::return_diagnostics() const {
  return d_ptr->return_diagnostics();
}

std::string ResponseHeader::audit_entry_id() const {
  return d_ptr->audit_entry_id();
}

uint32_t ResponseHeader::timeout_hint() const { return d_ptr->timeout_hint(); }

ExtensionObject ResponseHeader::additional_header() const {
  return d_ptr->additional_header();
}

bool ResponseHeader::operator==(ResponseHeader const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool ResponseHeader::operator!=(ResponseHeader const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
