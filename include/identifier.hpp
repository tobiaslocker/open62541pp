#ifndef OPEN62541_CPP_WRAPPER_IDENTIFIER_H
#define OPEN62541_CPP_WRAPPER_IDENTIFIER_H

#include "bytestring.hpp"
#include "enums.hpp"
#include "guid.hpp"

namespace open62541 {

class Identifier {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  Identifier();
  ~Identifier();

  Identifier(Identifier &&) noexcept;
  Identifier &operator=(Identifier &&) noexcept;
  Identifier(Identifier const &);
  Identifier &operator=(Identifier const &);

  explicit Identifier(uint32_t const &numeric);
  explicit Identifier(std::string const &string);
  explicit Identifier(Guid const &guid);

  std::string string() const;
  std::string byte_string() const;
  Guid guid() const;
  uint32_t numeric() const;
  std::string str() const;

  bool operator==(Identifier const &rhs) const;
  bool operator!=(Identifier const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_IDENTIFIER_H
