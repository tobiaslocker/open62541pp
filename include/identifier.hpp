#ifndef OPEN62541_CPP_WRAPPER_IDENTIFIER_H
#define OPEN62541_CPP_WRAPPER_IDENTIFIER_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {
using namespace nlohmann;

enum class IdentifierType : u_int32_t {
  Server = 0,
  Client = 1,
  ClientAndServer = 2,
  DiscoveryServer = 3,
};

std::ostream &operator<<(std::ostream &out,
                         IdentifierType const &identifier_type);

class Identifier {
  UA_UInt32 m_numeric;
  std::string m_string;
  UA_Guid m_guid;

  Identifier();
  explicit Identifier(UA_UInt32 const &numeric);
  explicit Identifier(UA_String const &string);
  explicit Identifier(UA_Guid const &guid);
  explicit Identifier(json::value_type const &json_value);

 public:
  enum class Type { Numeric, String, Guid, ByteString };
  Type type() const;
  // TODO: change? why from nodeId?
  static Identifier from_node_id(UA_NodeId const &node_id);
  std::string type_to_string() const;
  std::string string() const;
  u_int32_t numeric() const;

  json::value_type to_json_value() const;

  bool operator==(Identifier const &rhs) const;
  bool operator!=(Identifier const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  Identifier const &identifier);

 private:
  Type m_type;

  friend class NodeId;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_IDENTIFIER_H
