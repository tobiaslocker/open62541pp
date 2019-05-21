#include "identifier.hpp"

namespace open62541 {

Identifier::Identifier() {}

Identifier::Identifier(uint32_t const &numeric) : m_numeric{numeric} {}

Identifier::Identifier(std::string const &string) : m_string{string} {}

Identifier::Identifier(Guid const &guid) : m_guid{guid} {}

Identifier::Identifier(ByteString const &byte_string)
    : m_byte_string{byte_string} {}

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

}  // namespace open62541
