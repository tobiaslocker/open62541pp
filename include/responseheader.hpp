#ifndef OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H
#define OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H

// STL
#include <memory>
#include <string>
#include <vector>

#include "datetime.hpp"
#include "diagnosticinfo.hpp"
#include "enums.hpp"
#include "extensionobject.hpp"

namespace open62541 {

class ResponseHeader {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  ResponseHeader();
  ~ResponseHeader();

  ResponseHeader(ResponseHeader &&) noexcept;
  ResponseHeader &operator=(ResponseHeader &&) noexcept;
  ResponseHeader(ResponseHeader const &);
  ResponseHeader &operator=(ResponseHeader const &);

  ResponseHeader(DateTime const &timestamp,
                 uint32_t const &request_handle,
                 StatusCode const &service_result,
                 DiagnosticInfo const &service_diagnostics,
                 std::vector<std::string> const &string_table,
                 ExtensionObject const &additional_header);

  DateTime timestamp() const;
  uint32_t request_handle() const;
  StatusCode service_result() const;
  DiagnosticInfo service_diagnostics() const;
  std::vector<std::string> string_table() const;
  ExtensionObject additional_header() const;

  bool operator==(ResponseHeader const &rhs) const;
  bool operator!=(ResponseHeader const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, ResponseHeader const &op);

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H
