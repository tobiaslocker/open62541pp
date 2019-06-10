#ifndef OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
#define OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H

// STL
#include <memory>

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

  RequestHeader(NodeId authentication_token,
                std::string timestamp,
                uint32_t request_handle,
                uint32_t return_diagnostics,
                std::string audit_entry_id,
                uint32_t timeout_hint,
                ExtensionObject additional_header);

  NodeId authentication_token() const;
  std::string timestamp() const;
  uint32_t request_handle() const;
  uint32_t return_diagnostics() const;
  std::string audit_entry_id() const;
  uint32_t timeout_hint() const;
  ExtensionObject additional_header() const;

  bool operator==(RequestHeader const &rhs) const;
  bool operator!=(RequestHeader const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
