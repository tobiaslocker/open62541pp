#include "qualifiedname.hpp"

namespace open62541 {

QualifiedName::QualifiedName(std::string const &name, uint16_t namespace_index)
    : m_name{name}, m_namespace_index{namespace_index} {}

std::string QualifiedName::name() const { return m_name; }

uint16_t QualifiedName::namespace_index() const { return m_namespace_index; }

bool QualifiedName::operator==(QualifiedName const &rhs) const {
  return name() == rhs.name() && namespace_index() == rhs.namespace_index();
}

bool QualifiedName::operator!=(QualifiedName const &rhs) const {
  return name() != rhs.name() && namespace_index() != rhs.namespace_index();
}

std::ostream &operator<<(std::ostream &out, QualifiedName const &name) {
  auto s = name.name();
  out << s;
  return out;
}

}  // namespace open62541
