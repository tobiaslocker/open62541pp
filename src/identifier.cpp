#include "identifier.hpp"

namespace open62541 {

Identifier::Identifier() {}

Identifier::Identifier(UA_UInt32 const &numeric)
    : m_numeric{numeric}, m_type{IdentifierType::Numeric} {}

Identifier::Identifier(UA_String const &string)
    : m_type{IdentifierType::String} {
  m_string.assign(string.data, string.data + string.length);
}

Identifier::Identifier(UA_Guid const &guid)
    : m_guid{guid}, m_type{IdentifierType::Guid} {}

bool Identifier::operator==(const Identifier &rhs) const {
  return string() == rhs.string() && numeric() == rhs.numeric();
}

bool Identifier::operator!=(const Identifier &rhs) const {
  return string() != rhs.string() && numeric() != rhs.numeric();
}

std::ostream &operator<<(std::ostream &out, const Identifier &identifier) {
  auto j = identifier.to_string();
  out << j;
  return out;
}

std::string Identifier::string() const { return m_string; }

u_int32_t Identifier::numeric() const { return m_numeric; }

std::ostream &operator<<(std::ostream &out,
                         const IdentifierType &identifier_type) {
  auto s = identifier_type.to_string();
  out << s;
  return out;
}

}  // namespace open62541
