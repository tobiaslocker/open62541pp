#include "qualifiedname.hpp"
#include "ostr.hpp"

namespace open62541 {

class QualifiedName::impl {
  std::string m_name;
  uint16_t m_namespace_index = 0;

 public:
  impl() {}
  impl(std::string const &name, uint16_t namespace_index)
      : m_name{name}, m_namespace_index{namespace_index} {}

  std::string name() const { return m_name; }

  uint16_t namespace_index() const { return m_namespace_index; }

  bool operator==(impl const &rhs) const {
    return name() == rhs.name() && namespace_index() == rhs.namespace_index();
  }

  bool operator!=(impl const &rhs) const {
    return name() != rhs.name() || namespace_index() != rhs.namespace_index();
  }
};

QualifiedName::QualifiedName() : d_ptr{std::make_unique<impl>()} {}

QualifiedName::~QualifiedName() = default;

QualifiedName::QualifiedName(QualifiedName const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

QualifiedName &QualifiedName::operator=(QualifiedName const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

QualifiedName::QualifiedName(std::string const &name, uint16_t namespace_index)
    : d_ptr{std::make_unique<impl>(name, namespace_index)} {}

std::string QualifiedName::name() const { return d_ptr->name(); }

uint16_t QualifiedName::namespace_index() const {
  return d_ptr->namespace_index();
}

bool QualifiedName::operator==(QualifiedName const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool QualifiedName::operator!=(QualifiedName const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, QualifiedName const &op) {
  return out << "QualifiedName(" << ostr::fmt(op.name(), op.namespace_index())
             << ')';
}

}  // namespace open62541
