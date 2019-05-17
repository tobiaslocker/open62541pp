#include "qualifiedname.hpp"

namespace open62541 {

QualifiedName::QualifiedName(UA_QualifiedName const &name)
    : m_namespace_index{name.namespaceIndex} {
  m_name.assign(name.name.data, name.name.data + name.name.length);
}

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
