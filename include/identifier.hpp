#ifndef OPEN62541_CPP_WRAPPER_IDENTIFIER_H
#define OPEN62541_CPP_WRAPPER_IDENTIFIER_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

#include "enums.hpp"
#include "guid.hpp"

namespace open62541 {
using namespace nlohmann;

class ByteString {
 public:
  ByteString() {}
  ByteString(std::string const &data) {}

  static ByteString from_base_64(std::string const &data) {
    ByteString b;
    return b;
  }
  // TODO: implement. If done, remove certificate class?
};

class Identifier {
  uint32_t m_numeric = 0;
  std::string m_string;
  Guid m_guid;
  ByteString m_byte_string;

 public:
  explicit Identifier(uint32_t const &numeric);
  explicit Identifier(std::string const &string);
  explicit Identifier(Guid const &guid);
  explicit Identifier(ByteString const &byte_string);
  Identifier();
  std::string string() const;
  std::string byte_string() const;
  Guid guid() const;
  uint32_t numeric() const;
  std::string str() const;
  bool operator==(Identifier const &rhs) const;
  bool operator!=(Identifier const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  Identifier const &identifier);
  friend class NodeId;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_IDENTIFIER_H
