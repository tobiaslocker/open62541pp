#ifndef OPEN6541_CPP_WRAPPER_DIAGNOSTIC_INFO_H
#define OPEN6541_CPP_WRAPPER_DIAGNOSTIC_INFO_H

// STL
#include <memory>
#include <string>

#include "enums.hpp"

namespace open62541 {

class DiagnosticInfo {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  DiagnosticInfo();
  ~DiagnosticInfo();

  DiagnosticInfo(DiagnosticInfo &&) noexcept;
  DiagnosticInfo &operator=(DiagnosticInfo &&) noexcept;
  DiagnosticInfo(DiagnosticInfo const &);
  DiagnosticInfo &operator=(DiagnosticInfo const &);

  explicit DiagnosticInfo(
      bool has_symbolic_id,
      bool has_namespace_uri,
      bool has_localized_text,
      bool has_locale,
      bool has_additional_info,
      bool has_inner_status_code,
      bool has_inner_diagnostic_info,
      uint32_t symbolic_id,
      uint32_t namespace_uri,
      uint32_t localized_text,
      uint32_t locale,
      std::string additional_info,
      StatusCode inner_status_code,
      std::shared_ptr<DiagnosticInfo> inner_diagnostic_info = nullptr);

 public:

  bool has_symbolic_id() const;
  bool has_namespace_uri() const;
  bool has_localized_text() const;
  bool has_locale() const;
  bool has_additional_info() const;
  bool has_inner_status_code() const;
  bool has_inner_diagnostic_info() const;
  uint32_t symbolic_id() const;
  uint32_t namespace_uri() const;
  uint32_t localized_text() const;
  uint32_t locale() const;
  std::string additional_info() const;
  StatusCode inner_status_code() const;
  std::shared_ptr<DiagnosticInfo> inner_diagnostic_info() const;

  bool empty() const;

  bool operator==(DiagnosticInfo const &rhs) const;
  bool operator!=(DiagnosticInfo const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, DiagnosticInfo const &op);
}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_DIAGNOSTIC_INFO_H
