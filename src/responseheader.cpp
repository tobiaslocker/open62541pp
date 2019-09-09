#include "responseheader.hpp"

#include <algorithm>
#include <iomanip>

namespace open62541 {

class ResponseHeader::impl {
  DateTime m_timestamp;
  uint32_t m_request_handle = 0;
  StatusCode m_service_result = StatusCode::Unitialized;
  std::vector<std::string> m_string_table;
  DiagnosticInfo m_service_diagnostics;
  ExtensionObject m_additional_header;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(DateTime const &timestamp,
       uint32_t const &request_handle,
       StatusCode const &service_result,
       DiagnosticInfo const &service_diagnostics,
       std::vector<std::string> const &string_table,
       ExtensionObject const &additional_header)
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

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return timestamp() == rhs.timestamp() &&
           request_handle() == rhs.request_handle() &&
           service_result() == rhs.service_result() &&
           service_diagnostics() == rhs.service_diagnostics() &&
           string_table() == rhs.string_table() &&
           additional_header() == rhs.additional_header();
  }

  bool operator!=(impl const &rhs) const {
    return timestamp() != rhs.timestamp() ||
           request_handle() != rhs.request_handle() ||
           service_result() != rhs.service_result() ||
           service_diagnostics() != rhs.service_diagnostics() ||
           string_table() != rhs.string_table() ||
           additional_header() != rhs.additional_header();
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

ResponseHeader::ResponseHeader(DateTime const &timestamp,
                               uint32_t const &request_handle,
                               StatusCode const &service_result,
                               DiagnosticInfo const &service_diagnostics,
                               std::vector<std::string> const &string_table,
                               ExtensionObject const &additional_header)
    : d_ptr{std::make_unique<impl>(timestamp,
                                   request_handle,
                                   service_result,
                                   service_diagnostics,
                                   string_table,
                                   additional_header)} {}

DateTime ResponseHeader::timestamp() const { return d_ptr->timestamp(); }

uint32_t ResponseHeader::request_handle() const {
  return d_ptr->request_handle();
}

StatusCode ResponseHeader::service_result() const {
  return d_ptr->service_result();
}

DiagnosticInfo ResponseHeader::service_diagnostics() const {
  return d_ptr->service_diagnostics();
}

std::vector<std::string> ResponseHeader::string_table() const {
  return d_ptr->string_table();
}

ExtensionObject ResponseHeader::additional_header() const {
  return d_ptr->additional_header();
}

bool ResponseHeader::empty() const { return d_ptr->empty(); }

bool ResponseHeader::operator==(ResponseHeader const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool ResponseHeader::operator!=(ResponseHeader const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, ResponseHeader const &op) {
  out << "ResponseHeader(" << op.timestamp() << ", " << op.request_handle()
      << ", " << op.service_result() << ", " << op.service_diagnostics()
      << ", [";

  if (!op.string_table().empty()) {
    std::for_each(op.string_table().begin(),
                  op.string_table().end() - 1,
                  //                  [&](std::string const &u) { out <<
                  //                  std::quoted(u) << ", "; });
                  [&](std::string const &u) { out << u << ", "; });
    //    out << std::quoted(op.string_table().back());
    out << op.string_table().back();
  }
  out << "], " << op.additional_header() << ')';
  return out;
}
}  // namespace open62541
