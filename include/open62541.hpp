#ifndef OPEN_62541_HPP
#define OPEN_62541_HPP

#include <stdio.h>
#include "log.hpp"
#include "open62541.h"

// STL
#include <iostream>
#include <iterator>
#include <memory>
#include <unordered_set>
#include <vector>

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {
using Url = std::string;
using namespace nlohmann;
using namespace logger;

enum class BrowseResultMask : u_int32_t {
  None = 0,
  ReferenceTypeId = 1,
  IsForward = 2,
  NodeClass = 4,
  QualifiedName = 8,
  LocalizedText = 16,
  TypeDefinition = 32,
  All = 63,
  ReferencetypeInfo = 3,
  TargetInfo = 6,
};

enum class ReferenceTypeIdentifier : u_int32_t {
  Unspecified = 0,
  References = 31,
  NonHierarchicalReferences = 32,
  HierarchicalReferences = 33,
  HasChild = 34,
  Organizes = 35,
  HasEventSource = 36,
  HasModellingRule = 37,
  HasEncoding = 38,
  HasDescription = 39,
  HasTypeDefinition = 40,
  GeneratesEvent = 41,
  Aggregates = 44,
  HasSubtype = 45,
  HasProperty = 46,
  HasComponent = 47,
  HasNotifier = 48,
  HasOrderedComponent = 49,
  FromState = 51,
  ToState = 52,
  HasCause = 53,
  HasEffect = 54,
  HasHistoricalConfiguration = 56,
  HasSubStateMachine = 117,
  AlwaysGeneratesEvent = 3065,
  HasTrueSubState = 9004,
  HasFalseSubState = 9005,
  HasCondition = 9006
};

enum class NodeClass : u_int32_t {
  Unspecified = 0,
  Object = 1,
  Variable = 2,
  Method = 4,
  ObjectType = 8,
  VariableType = 16,
  ReferenceType = 32,
  DataType = 64,
  View = 128,
  All = 255
};

inline NodeClass operator|(NodeClass a, NodeClass b) {
  return static_cast<NodeClass>(static_cast<int>(a) | static_cast<int>(b));
}

struct NodeClassMask {
  u_int32_t i = 0;
  NodeClassMask(NodeClass const &msk) : i{static_cast<u_int32_t>(msk)} {}
  operator u_int32_t() const { return i; }
};

enum class ApplicationType : u_int32_t {
  Server = 0,
  Client = 1,
  ClientAndServer = 2,
  DiscoveryServer = 3
};

enum class MessageSecurityMode {
  Invalid = 0,
  None = 1,
  Sign = 2,
  SignAndEncrypt = 3
};

bool status_is_good(UA_StatusCode status);

std::string to_std_string(UA_String const &str);

class LocalizedText {
  std::string m_text;
  std::string m_locale;
  bool m_is_empty;

 public:
  explicit LocalizedText(UA_LocalizedText const &display_name);
  LocalizedText();
  std::string text() const;
  std::string locale() const;
  bool is_empty() const;
};

class QualifiedName {
  std::string m_name;
  u_int16_t m_namespace_index;

 public:
  QualifiedName(UA_QualifiedName const &name);
  std::string name();
  u_int16_t namespace_index();
};

class ApplicationDescription {
  std::string m_application_uri;
  std::string m_product_uri;
  LocalizedText m_application_name;
  ApplicationType m_application_type;
  std::string m_gateway_server_uri;
  std::string m_discovery_profile_uri;
  std::vector<std::string> m_discovery_urls;

 public:
  ApplicationDescription() {}
  ApplicationDescription(
      UA_ApplicationDescription const &application_description);

  std::string application_uri() const;
  std::string product_uri() const;
  LocalizedText application_name() const;
  ApplicationType application_type() const;
  std::string gateway_server_uri() const;
  std::string discovery_profile_uri() const;
  std::vector<std::string> discovery_urls() const;
  json to_json() const;
};

class Certificate {
  std::string m_certificate;

 public:
  Certificate() {}
  Certificate(UA_ByteString const &certificate);
  std::string to_string() const;
};

enum class UserTokenType : u_int32_t {
  Anonymous = 0,
  UserName = 1,
  Certificate = 2,
  IssuedToken = 3
};

class UserTokenPolicy {
  std::string m_policy_id;
  UserTokenType m_token_type;
  std::string m_issued_token_type;
  std::string m_issuer_endpoint_url;
  std::string m_security_policy_uri;

 public:
  UserTokenPolicy(UA_UserTokenPolicy user_token_policy);

  std::string policy_id() const;
  UserTokenType token_type() const;
  std::string issued_token_type() const;
  std::string issuer_endpoint_url() const;
  std::string security_policy_uri() const;
  json to_json() const;
};

class EndpointDescription {
  std::string m_endpoint_url;
  ApplicationDescription m_server;
  Certificate m_server_certificate;
  MessageSecurityMode m_security_mode;
  std::string m_security_policy_uri;
  size_t m_user_identity_tokens_size;
  std::vector<UserTokenPolicy> m_user_identity_tokens;
  std::string m_transport_profile_uri;
  unsigned char m_security_level;

 public:
  explicit EndpointDescription();
  explicit EndpointDescription(UA_EndpointDescription const &url);
  std::string endpoint_url() const;
  ApplicationDescription server() const;
  Certificate server_certificate() const;
  MessageSecurityMode security_mode() const;
  std::string security_policy_uri() const;
  size_t user_identity_tokens_size() const;
  std::vector<UserTokenPolicy> user_identity_tokens() const;
  std::string transport_profile_uri() const;
  unsigned char security_level() const;

  json to_json() const;
};

class Identifier {
  UA_UInt32 m_numeric;
  std::string m_string;
  UA_Guid m_guid;

 public:
  Identifier();
  explicit Identifier(UA_UInt32 const &numeric);
  explicit Identifier(UA_String const &string);
  explicit Identifier(UA_Guid const &guid);
  explicit Identifier(nlohmann::json::value_type const &json_value);
  // explicit Identifier(UA_ByteString byteString); //TODO make types for
  // constructors to avoid collision with numeric constructor
  enum class Type { Numeric, String, Guid, ByteString };
  Type type() const;
  static Identifier from_node_id(UA_NodeId const &node_id);
  std::string type_to_string() const;
  std::string to_string() const;
  std::string string() const;
  u_int32_t numeric() const;
  json::value_type to_json_value() const;

 private:
  Type m_type;
};

class NodeId {
  u_int16_t m_namespace_index;
  explicit NodeId(UA_NodeId const &node_id);

 public:
  explicit NodeId(json const &node_id);
  explicit NodeId(uint16_t namespace_index, Identifier const &identifier);

  Identifier indentifier() const;
  u_int16_t namespace_index() const;
  json to_json() const;

 private:
  UA_NodeId ua_node_id() const;

  Identifier m_id;
  friend class ReferenceDescription;
  friend class ExpandedNodeId;
  friend class Node;
  friend class Client;
};

class ExpandedNodeId {
  NodeId m_node_id;
  std::string m_namespace_uri;
  u_int32_t m_server_index = 0;
  explicit ExpandedNodeId(UA_ExpandedNodeId const &expanded_node_id);

 public:
  explicit ExpandedNodeId(NodeId const &node_id);
  explicit ExpandedNodeId(NodeId const &node_id,
                          std::string const &namespace_uri,
                          u_int32_t server_index = 0);
  std::string namespace_uri() const;
  NodeId node_id() const;
  u_int32_t server_index() const;
  json to_json() const;
  friend class ReferenceDescription;
};

class ReferenceDescription {
  UA_ReferenceDescription m_ref;
  NodeId m_node_id;
  LocalizedText m_display_name;
  QualifiedName m_browse_name;
  ExpandedNodeId m_type_definition;
  explicit ReferenceDescription(UA_ReferenceDescription const &ref);

 public:
  NodeId node_id() const;
  LocalizedText display_name() const;
  QualifiedName browse_name() const;
  json to_json() const;
  ExpandedNodeId type_definition() const;
  friend class Node;
};

class Client;

class Node {
  NodeId m_node_id;
  std::shared_ptr<Client> m_client;
  src::severity_channel_logger<severity_level, std::string> m_lg;
  std::string m_channel = "ua_node";

 public:
  explicit Node(NodeId const &node_id, std::shared_ptr<Client> client);
  std::vector<ReferenceDescription> browse_children(
      BrowseResultMask mask,
      NodeClassMask node_class_mask,
      ReferenceTypeIdentifier id);
  NodeId node_id() const;
  friend class Client;
};

class Client : public std::enable_shared_from_this<Client> {
  src::severity_channel_logger<severity_level, std::string> m_lg;
  std::string m_channel = "ua_client";
  std::shared_ptr<UA_Client> m_client;
  Client();
  UA_BrowseResponse browse(UA_BrowseRequest const &request);

 public:
  std::vector<EndpointDescription> get_endpoints(Url const &url);
  void connect_to_endpoint(Url const &url);
  void connect_to_endpoint(EndpointDescription const &endpoint);
  std::shared_ptr<Node> node(NodeId const &node_id);
  std::shared_ptr<Client> client();
  static std::shared_ptr<Client> create();
  LocalizedText read_display_name_attribute(NodeId const &node_id) const;

  friend class Node;
};

}  // namespace open62541
#endif  // OPEN_62541_HPP
