#include "identifier.hpp"

namespace open62541 {

class Identifier::impl {
  uint32_t m_numeric = 0;
  std::string m_string;
  Guid m_guid;
  ByteString m_byte_string;

 public:
  impl(){}

  impl(uint32_t const &numeric) : m_numeric{numeric} {}

  impl(std::string const &string) : m_string{string} {}

  impl(Guid const &guid) : m_guid{guid} {}

  impl(ByteString const &byte_string) : m_byte_string{byte_string} {}

  std::string string() const { return m_string; }

  std::string byte_string() const { return m_string; }

  Guid guid() const { return m_guid; }

  uint32_t numeric() const { return m_numeric; }

  bool operator==(impl const &rhs) const {
    return string() == rhs.string() && numeric() == rhs.numeric();
  }

  bool operator!=(impl const &rhs) const {
    return string() != rhs.string() && numeric() != rhs.numeric();
  }
};

Identifier::Identifier() : d_ptr{std::make_unique<impl>()} {}

Identifier::~Identifier() = default;

Identifier::Identifier(Identifier const &op) : d_ptr(new impl(*op.d_ptr)) {}

Identifier &Identifier::operator=(Identifier const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

Identifier::Identifier(uint32_t const &numeric)
    : d_ptr{std::make_unique<impl>(numeric)} {}

Identifier::Identifier(std::string const &string)
    : d_ptr{std::make_unique<impl>(string)} {}

Identifier::Identifier(Guid const &guid)
    : d_ptr{std::make_unique<impl>(guid)} {}

Identifier::Identifier(ByteString const &byte_string)
    : d_ptr{std::make_unique<impl>(byte_string)} {}

bool Identifier::operator==(Identifier const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool Identifier::operator!=(Identifier const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::string Identifier::string() const { return d_ptr->string(); }

std::string Identifier::byte_string() const { return d_ptr->byte_string(); }

Guid Identifier::guid() const { return d_ptr->guid(); }

uint32_t Identifier::numeric() const { return d_ptr->numeric(); }

}  // namespace open62541
