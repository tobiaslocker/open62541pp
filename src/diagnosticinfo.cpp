#include "diagnosticinfo.hpp"
#include "ostr.hpp"

namespace open62541 {

class DiagnosticInfo::impl {
  bool m_has_symbolic_id = false;
  bool m_has_namespace_uri = false;
  bool m_has_localized_text = false;
  bool m_has_locale = false;
  bool m_has_additional_info = false;
  bool m_has_inner_status_code = false;
  bool m_has_inner_diagnostic_info = false;
  uint32_t m_symbolic_id = 0;
  uint32_t m_namespace_uri = 0;
  uint32_t m_localized_text = 0;
  uint32_t m_locale = 0;
  std::string m_additional_info;
  StatusCode m_inner_status_code = StatusCode::Unitialized;
  std::shared_ptr<DiagnosticInfo> m_inner_diagnostic_info = nullptr;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}
  impl(bool has_symbolic_id,
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
       std::shared_ptr<DiagnosticInfo> inner_diagnostic_info)
      : m_has_symbolic_id{has_symbolic_id},
        m_has_namespace_uri{has_namespace_uri},
        m_has_localized_text{has_localized_text},
        m_has_locale{has_locale},
        m_has_additional_info{has_additional_info},
        m_has_inner_status_code{has_inner_status_code},
        m_has_inner_diagnostic_info{has_inner_diagnostic_info},
        m_symbolic_id{symbolic_id},
        m_namespace_uri{namespace_uri},
        m_localized_text{localized_text},
        m_locale{locale},
        m_additional_info{additional_info},
        m_inner_status_code{inner_status_code},
        m_inner_diagnostic_info{inner_diagnostic_info} {}

  bool has_symbolic_id() const { return m_has_symbolic_id; }

  bool has_namespace_uri() const { return m_has_namespace_uri; }

  bool has_localized_text() const { return m_has_localized_text; }

  bool has_locale() const { return m_has_locale; }

  bool has_additional_info() const { return m_has_additional_info; }

  bool has_inner_status_code() const { return m_has_inner_status_code; }

  bool has_inner_diagnostic_info() const { return m_has_inner_diagnostic_info; }

  uint32_t symbolic_id() const { return m_symbolic_id; }

  uint32_t namespace_uri() const { return m_namespace_uri; }

  uint32_t localized_text() const { return m_localized_text; }

  uint32_t locale() const { return m_locale; }

  std::string additional_info() const { return m_additional_info; }

  StatusCode inner_status_code() const { return m_inner_status_code; }

  std::shared_ptr<DiagnosticInfo> inner_diagnostic_info() const {
    return m_inner_diagnostic_info;
  }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    bool b = false;
    if (inner_diagnostic_info() && rhs.inner_diagnostic_info()) {
      b = *inner_diagnostic_info() == *rhs.inner_diagnostic_info();
    } else {
      b = true;
    }
    return has_symbolic_id() == rhs.has_symbolic_id() &&
           has_namespace_uri() == rhs.has_namespace_uri() &&
           has_localized_text() == rhs.has_localized_text() &&
           has_locale() == rhs.has_locale() &&
           has_additional_info() == rhs.has_additional_info() &&
           has_inner_status_code() == rhs.has_inner_status_code() &&
           has_inner_diagnostic_info() == rhs.has_inner_diagnostic_info() &&
           symbolic_id() == rhs.symbolic_id() &&
           namespace_uri() == rhs.namespace_uri() &&
           localized_text() == rhs.localized_text() &&
           locale() == rhs.locale() &&
           additional_info() == rhs.additional_info() &&
           inner_status_code() == rhs.inner_status_code() && b;
  }

  bool operator!=(impl const &rhs) const {
    bool b = false;
    if (inner_diagnostic_info() && rhs.inner_diagnostic_info()) {
      b = *inner_diagnostic_info() == *rhs.inner_diagnostic_info();
    } else {
      b = true;
    }
    return has_symbolic_id() != rhs.has_symbolic_id() ||
           has_namespace_uri() != rhs.has_namespace_uri() ||
           has_localized_text() != rhs.has_localized_text() ||
           has_locale() != rhs.has_locale() ||
           has_additional_info() != rhs.has_additional_info() ||
           has_inner_status_code() != rhs.has_inner_status_code() ||
           has_inner_diagnostic_info() != rhs.has_inner_diagnostic_info() ||
           symbolic_id() != rhs.symbolic_id() ||
           namespace_uri() != rhs.namespace_uri() ||
           localized_text() != rhs.localized_text() ||
           locale() != rhs.locale() ||
           additional_info() != rhs.additional_info() ||
           inner_status_code() != rhs.inner_status_code() ||
           inner_diagnostic_info() != rhs.inner_diagnostic_info() || !b;
  }
};

DiagnosticInfo::DiagnosticInfo(
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
    std::shared_ptr<DiagnosticInfo> inner_diagnostic_info)
    : d_ptr{std::make_unique<impl>(has_symbolic_id,
                                   has_namespace_uri,
                                   has_localized_text,
                                   has_locale,
                                   has_additional_info,
                                   has_inner_status_code,
                                   has_inner_diagnostic_info,
                                   symbolic_id,
                                   namespace_uri,
                                   localized_text,
                                   locale,
                                   additional_info,
                                   inner_status_code,
                                   inner_diagnostic_info)} {}

bool DiagnosticInfo::has_symbolic_id() const {
  return d_ptr->has_symbolic_id();
}

bool DiagnosticInfo::has_namespace_uri() const {
  return d_ptr->has_namespace_uri();
}

bool DiagnosticInfo::has_localized_text() const {
  return d_ptr->has_localized_text();
}

bool DiagnosticInfo::has_locale() const { return d_ptr->has_locale(); }

bool DiagnosticInfo::has_additional_info() const {
  return d_ptr->has_additional_info();
}

bool DiagnosticInfo::has_inner_status_code() const {
  return d_ptr->has_inner_status_code();
}

bool DiagnosticInfo::has_inner_diagnostic_info() const {
  return d_ptr->has_inner_diagnostic_info();
}

uint32_t DiagnosticInfo::symbolic_id() const {
  return d_ptr->has_symbolic_id();
}

uint32_t DiagnosticInfo::namespace_uri() const {
  return d_ptr->namespace_uri();
}

uint32_t DiagnosticInfo::localized_text() const {
  return d_ptr->localized_text();
}

uint32_t DiagnosticInfo::locale() const { return d_ptr->locale(); }

std::string DiagnosticInfo::additional_info() const {
  return d_ptr->additional_info();
}

StatusCode DiagnosticInfo::inner_status_code() const {
  return d_ptr->inner_status_code();
}

std::shared_ptr<DiagnosticInfo> DiagnosticInfo::inner_diagnostic_info() const {
  return d_ptr->inner_diagnostic_info();
}

bool DiagnosticInfo::empty() const { return d_ptr->empty(); }

DiagnosticInfo::DiagnosticInfo() : d_ptr{std::make_unique<impl>()} {}

DiagnosticInfo &DiagnosticInfo::operator=(DiagnosticInfo &&) noexcept = default;

DiagnosticInfo::DiagnosticInfo(DiagnosticInfo &&) noexcept = default;

DiagnosticInfo::~DiagnosticInfo() = default;

DiagnosticInfo::DiagnosticInfo(DiagnosticInfo const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

DiagnosticInfo &DiagnosticInfo::operator=(DiagnosticInfo const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

bool DiagnosticInfo::operator==(DiagnosticInfo const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool DiagnosticInfo::operator!=(DiagnosticInfo const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const DiagnosticInfo &op) {
  return out << "DiagnosticInfo("
             << ostr::fmt(op.has_symbolic_id(),
                          op.has_namespace_uri(),
                          op.has_localized_text(),
                          op.has_locale(),
                          op.has_additional_info(),
                          op.has_inner_status_code(),
                          op.symbolic_id(),
                          op.namespace_uri(),
                          op.localized_text(),
                          op.locale(),
                          op.additional_info(),
                          op.inner_status_code())
             //                          op.inner_diagnostic_info())
             << ')';
}

}  // namespace open62541
