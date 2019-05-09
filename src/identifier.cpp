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
  auto j = identifier.str();
  out << j;
  return out;
}

std::string Identifier::string() const { return m_string; }

std::string Identifier::byte_string() const { return m_string; }

Guid Identifier::guid() const {
  return m_guid;  // TODO
}

u_int32_t Identifier::numeric() const { return m_numeric; }


std::string Identifier::str() const {

  switch (m_type) {
    case IdentifierType::Guid:
      return guid().str();
    case IdentifierType::String:
      return string();
    case IdentifierType::Numeric:
      return std::to_string(numeric());
    case IdentifierType::ByteString:
      return byte_string();
  }
  return std::string();
}

std::ostream &operator<<(std::ostream &out,
                         const IdentifierType &identifier_type) {
  auto s = identifier_type.str();
  out << s;
  return out;
}

IdentifierType::IdentifierType(const UA_NodeIdType &id_type) {
  switch (id_type) {
    case UA_NODEIDTYPE_GUID:
      m_value = Guid;
      break;
    case UA_NODEIDTYPE_STRING:
      m_value = String;
      break;
    case UA_NODEIDTYPE_NUMERIC:
      m_value = Numeric;
      break;
    case UA_NODEIDTYPE_BYTESTRING:
      m_value = ByteString;
      break;
  }
}

constexpr IdentifierType::IdentifierType(IdentifierType::Value id_type)
    : m_value(id_type) {}

bool IdentifierType::operator==(const IdentifierType &rhs) const {
  return m_value == rhs.m_value;
}

bool IdentifierType::operator!=(const IdentifierType &rhs) const {
  return m_value != rhs.m_value;
}

std::string IdentifierType::str() const {
  switch (m_value) {
    case Guid:
      return "Guid";
    case Numeric:
      return "Numeric";
    case String:
      return "String";
    case ByteString:
      return "ByteString";
  }
  return std::string();
}

open62541::IdentifierType::operator u_int32_t() const { return m_value; }


}  // namespace open62541
