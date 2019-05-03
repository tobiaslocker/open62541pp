#include "identifier.hpp"

namespace open62541 {

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

Identifier::Identifier() {}

Identifier::Identifier(UA_UInt32 const &numeric)
    : m_numeric{numeric}, m_type{Type::Numeric} {}

Identifier::Identifier(UA_String const &string)
    : m_string{to_std_string(string)}, m_type{Type::String} {}

Identifier::Identifier(UA_Guid const &guid)
    : m_guid{guid}, m_type{Type::Guid} {}

Identifier::Identifier(nlohmann::json::value_type const &json_value) {
  switch (json_value.type()) {
    case json::value_t::number_integer:
    case json::value_t::number_unsigned:
      json_value.get_to(m_numeric);
      m_type = Type::Numeric;
      break;
    case json::value_t::string:
      json_value.get_to(m_string);
      m_type = Type::String;
      break;
    case json::value_t::object:
    case json::value_t::array:
    case json::value_t::boolean:
    case json::value_t::discarded:
    case json::value_t::null:
    case json::value_t::number_float:
      // TODO: assert this never happens
      break;
  }
}

Identifier::Type Identifier::type() const { return m_type; }

Identifier Identifier::from_node_id(UA_NodeId const &node_id) {
  switch (node_id.identifierType) {
    case UA_NODEIDTYPE_NUMERIC:
      return Identifier(node_id.identifier.numeric);
    case UA_NODEIDTYPE_STRING:
      return Identifier(node_id.identifier.string);
    case UA_NODEIDTYPE_GUID:
      return Identifier(node_id.identifier.guid);
    case UA_NODEIDTYPE_BYTESTRING:
      return Identifier(node_id.identifier.byteString);
  }
  return Identifier();
}

std::string Identifier::type_to_string() const {
  switch (type()) {
    case Type::Numeric:
      return "Numeric";
    case Type::String:
      return "String";
    case Type::ByteString:
      return "ByteString";
    case Type::Guid:
      return "Guid";
  }
  return std::string();
}

std::string Identifier::to_string() const {
  switch (type()) {
    case Type::Numeric:
      return std::to_string(numeric());
    case Type::String:
      return string();
    case Type::ByteString:
      // TODO
    case Type::Guid:
      // TODO
      break;
  }
  return std::string();
}

json::value_type Identifier::to_json_value() const {
  switch (type()) {
    case Type::Numeric:
      return numeric();
    case Type::String:
      return string();
    case Type::ByteString:
      // TODO
    case Type::Guid:
      // TODO
      break;
  }
  return json::value_t::null;
}

std::string Identifier::string() const { return m_string; }

u_int32_t Identifier::numeric() const { return m_numeric; }
}  // namespace open62541
