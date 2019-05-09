#ifndef OPEN62541_CPP_WRAPPER_IDENTIFIER_H
#define OPEN62541_CPP_WRAPPER_IDENTIFIER_H

#include "open62541.h"

// STL
#include <any>

// Dependencies
#include <nlohmann/json.hpp>

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

struct Guid {
  Guid() {}
  Guid(UA_Guid const &guid) {}
  std::string str() const { return "Hi"; }
};

class Identifier {
  UA_UInt32 m_numeric = 0;
  std::string m_string;
  Guid m_guid;
  IdentifierType m_type;

  Identifier();
  explicit Identifier(UA_UInt32 const &numeric);
  explicit Identifier(UA_String const &string);
  explicit Identifier(UA_Guid const &guid);

 public:
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
