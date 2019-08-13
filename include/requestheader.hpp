#ifndef OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
#define OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H

// STL
#include <memory>

#include "datetime.hpp"
#include "extensionobject.hpp"
#include "nodeid.hpp"

namespace open62541 {

class RequestHeader {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  RequestHeader();
  ~RequestHeader();

  RequestHeader(RequestHeader &&) noexcept;
  RequestHeader &operator=(RequestHeader &&) noexcept;
  RequestHeader(RequestHeader const &);
  RequestHeader &operator=(RequestHeader const &);

  RequestHeader(NodeId const &authentication_token,
                DateTime const &timestamp,
                uint32_t const &request_handle,
                uint32_t const &return_diagnostics,
                std::string const &audit_entry_id,
                uint32_t const &timeout_hint,
                ExtensionObject const &additional_header);

  NodeId authentication_token() const;
  DateTime timestamp() const;
  uint32_t request_handle() const;
  uint32_t return_diagnostics() const;
  std::string audit_entry_id() const;
  uint32_t timeout_hint() const;
  ExtensionObject additional_header() const;

  bool empty() const;

  bool operator==(RequestHeader const &rhs) const;
  bool operator!=(RequestHeader const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, RequestHeader const &op);

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
