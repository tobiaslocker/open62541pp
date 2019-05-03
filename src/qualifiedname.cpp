#include "qualifiedname.hpp"

namespace open62541 {

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

QualifiedName::QualifiedName(UA_QualifiedName const &name)
    : m_name{to_std_string(name.name)},
      m_namespace_index{name.namespaceIndex} {}

std::string QualifiedName::name() { return m_name; }

u_int16_t QualifiedName::namespace_index() { return m_namespace_index; }

}  // namespace open62541
