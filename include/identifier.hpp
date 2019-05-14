#ifndef OPEN62541_CPP_WRAPPER_IDENTIFIER_H
#define OPEN62541_CPP_WRAPPER_IDENTIFIER_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

#include "guid.hpp"

namespace open62541 {
using namespace nlohmann;

class IdentifierType {
  explicit IdentifierType(UA_NodeIdType const &id_type);

 public:
  enum Value : u_int32_t {
    Numeric,
    String,
    Guid,
    ByteString,
  };
  IdentifierType() = default;
  constexpr IdentifierType(Value id_type);
  bool operator==(IdentifierType const &rhs) const;
  bool operator!=(IdentifierType const &rhs) const;
  std::string str() const;
  operator u_int32_t() const;

 private:
  Value m_value;
  friend class NodeId;
};

std::ostream &operator<<(std::ostream &out,
                         IdentifierType const &identifier_type);

class ByteString {
 public:
  ByteString() {}
  ByteString(std::string const &data) {}

  static ByteString from_base_64(std::string const &data) {}
  // TODO: implement. If done, remove certificate class?
};

class Identifier {
  u_int32_t m_numeric = 0;
  std::string m_string;
  Guid m_guid;
  ByteString m_byte_string;
  IdentifierType m_type;
  explicit Identifier(UA_String const &string);
  explicit Identifier(UA_Guid const &guid);

 public:
  explicit Identifier(u_int32_t const &numeric);
  explicit Identifier(std::string const &string);
  explicit Identifier(Guid const &guid);
  explicit Identifier(ByteString const &byte_string);
  Identifier();
  std::string string() const;
  std::string byte_string() const;
  Guid guid() const;
  u_int32_t numeric() const;
  std::string str() const;
  bool operator==(Identifier const &rhs) const;
  bool operator!=(Identifier const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  Identifier const &identifier);
  friend class NodeId;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_IDENTIFIER_H
