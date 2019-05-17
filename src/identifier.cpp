#include "identifier.hpp"

namespace open62541 {

Identifier::Identifier() {}

Identifier::Identifier(uint32_t const &numeric)
    : m_numeric{numeric}, m_type{IdentifierType::Numeric} {}

Identifier::Identifier(std::string const &string)
    : m_string{string}, m_type{IdentifierType::String} {}

Identifier::Identifier(Guid const &guid)
    : m_guid{guid}, m_type{IdentifierType::Guid} {}

Identifier::Identifier(ByteString const &byte_string)
    : m_byte_string{byte_string}, m_type{IdentifierType::ByteString} {}

Identifier::Identifier(UA_String const &string)
    : m_type{IdentifierType::String} {
  m_string.assign(string.data, string.data + string.length);
}

Identifier::Identifier(UA_Guid const &guid)
    : m_guid{guid}, m_type{IdentifierType::Guid} {}

bool Identifier::operator==(Identifier const &rhs) const {
  return string() == rhs.string() && numeric() == rhs.numeric();
}

bool Identifier::operator!=(Identifier const &rhs) const {
  return string() != rhs.string() && numeric() != rhs.numeric();
}

std::ostream &operator<<(std::ostream &out, Identifier const &identifier) {
  auto j = identifier.str();
  out << j;
  return out;
}

std::string Identifier::string() const { return m_string; }

std::string Identifier::byte_string() const { return m_string; }

Guid Identifier::guid() const {
  return m_guid;  // TODO
}

uint32_t Identifier::numeric() const { return m_numeric; }

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
                         IdentifierType const &identifier_type) {
  auto s = identifier_type.str();
  out << s;
  return out;
}

IdentifierType::IdentifierType(UA_NodeIdType const &id_type) {
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

bool IdentifierType::operator==(IdentifierType const &rhs) const {
  return m_value == rhs.m_value;
}

bool IdentifierType::operator!=(IdentifierType const &rhs) const {
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

open62541::IdentifierType::operator uint32_t() const { return m_value; }

}  // namespace open62541
