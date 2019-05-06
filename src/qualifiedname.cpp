#include "qualifiedname.hpp"

namespace open62541 {

QualifiedName::QualifiedName(UA_QualifiedName const &name)
    : m_namespace_index{name.namespaceIndex} {
  if (auto c = reinterpret_cast<char *>(name.name.data)) {
    m_name = std::string(c);
  }
}

std::string QualifiedName::name() { return m_name; }

u_int16_t QualifiedName::namespace_index() { return m_namespace_index; }

}  // namespace open62541
