#ifndef OPEN62541_CPP_WRAPPER_IDENTIFIER_H
#define OPEN62541_CPP_WRAPPER_IDENTIFIER_H

#include "open62541.h"

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {

using namespace nlohmann;

class Identifier {
  UA_UInt32 m_numeric;
  std::string m_string;
  UA_Guid m_guid;

 public:
  Identifier();
  explicit Identifier(UA_UInt32 const &numeric);
  explicit Identifier(UA_String const &string);
  explicit Identifier(UA_Guid const &guid);
  explicit Identifier(json::value_type const &json_value);
  // explicit Identifier(UA_ByteString byteString); //TODO make types for
  // constructors to avoid collision with numeric constructor
  enum class Type { Numeric, String, Guid, ByteString };
  Type type() const;
  // TODO: change? why from nodeId?
  static Identifier from_node_id(UA_NodeId const &node_id);
  std::string type_to_string() const;
  std::string to_string() const;
  std::string string() const;
  u_int32_t numeric() const;
  json::value_type to_json_value() const;

 private:
  Type m_type;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_IDENTIFIER_H
