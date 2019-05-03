#include "open62541.hpp"

namespace open62541 {

bool status_is_good(UA_StatusCode status) {
  if (status != UA_STATUSCODE_GOOD) {
    return false;
  }
  return true;
}

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

EndpointDescription::EndpointDescription() {}

EndpointDescription::EndpointDescription(
    const UA_EndpointDescription &endpoint_decription)
    : m_endpoint_url{to_std_string(endpoint_decription.endpointUrl)},
      m_server{endpoint_decription.server},
      m_server_certificate{endpoint_decription.serverCertificate},
      m_security_mode{MessageSecurityMode(endpoint_decription.securityMode)},
      m_security_policy_uri{
          to_std_string(endpoint_decription.securityPolicyUri)},
      m_user_identity_tokens_size{endpoint_decription.userIdentityTokensSize},
      m_transport_profile_uri{
          to_std_string(endpoint_decription.transportProfileUri)},
      m_security_level{endpoint_decription.securityLevel} {
  for (size_t i = 0; i < endpoint_decription.userIdentityTokensSize; ++i) {
    auto policy = UserTokenPolicy(endpoint_decription.userIdentityTokens[i]);
    m_user_identity_tokens.push_back(policy);
  }
}

std::string EndpointDescription::endpoint_url() const { return m_endpoint_url; }

ApplicationDescription EndpointDescription::server() const { return m_server; }

Certificate EndpointDescription::server_certificate() const {
  return m_server_certificate;
}

MessageSecurityMode EndpointDescription::security_mode() const {
  return m_security_mode;
}

std::string EndpointDescription::security_policy_uri() const {
  return m_security_policy_uri;
}

size_t EndpointDescription::user_identity_tokens_size() const {
  return m_user_identity_tokens_size;
}

std::vector<UserTokenPolicy> EndpointDescription::user_identity_tokens() const {
  return m_user_identity_tokens;
}

std::string EndpointDescription::transport_profile_uri() const {
  return m_transport_profile_uri;
}

unsigned char EndpointDescription::security_level() const {
  return m_security_level;
}

json EndpointDescription::to_json() const {
  json j;
  j["EndpointUrl"] = m_endpoint_url;
  j["Server"] = m_server.to_json();
  //  j["Certificate"] = m_server_certificate.to_string();

  switch (m_security_mode) {
    case MessageSecurityMode::Invalid:
      j["SecurityMode"] = "Invalid";
      break;
    case MessageSecurityMode::None:
      j["SecurityMode"] = "None";
      break;
    case MessageSecurityMode::Sign:
      j["SecurityMode"] = "Sign";
      break;
    case MessageSecurityMode::SignAndEncrypt:
      j["SecurityMode"] = "SignAndEncrypt";
      break;
  }

  j["SecurityPolicyUri"] = m_security_policy_uri;
  j["TransportProfileUri"] = m_transport_profile_uri;
  j["SecurityLevel"] = m_security_level;

  json policies;
  std::for_each(m_user_identity_tokens.begin(),
                m_user_identity_tokens.end(),
                [&](UserTokenPolicy const &p) {
                  policies.push_back(p.to_json());
                });
  j["UserIdentityTokens"] = policies;
  return j;
}

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

NodeId::NodeId(UA_NodeId const &node_id)
    : m_namespace_index{node_id.namespaceIndex},
      m_id{Identifier::from_node_id(node_id)} {}

NodeId::NodeId(json const &node_id)
    : m_namespace_index{node_id["NamespaceIndex"]},
      m_id{Identifier(node_id["Identifier"])} {}

NodeId::NodeId(uint16_t namespace_index, Identifier const &identifier)
    : m_namespace_index{namespace_index}, m_id{identifier} {}

Identifier NodeId::indentifier() const { return m_id; }

u_int16_t NodeId::namespace_index() const { return m_namespace_index; }

json NodeId::to_json() const {
  json j;
  j["NamespaceIndex"] = m_namespace_index;
  j["IdentifierType"] = m_id.type_to_string();
  j["Identifier"] = m_id.to_json_value();
  return j;
}

UA_NodeId NodeId::ua_node_id() const {
  UA_NodeId ua_node;
  switch (indentifier().type()) {
    case Identifier::Type::Numeric:
      ua_node = UA_NODEID_NUMERIC(namespace_index(), indentifier().numeric());
      break;
    case Identifier::Type::String:
      ua_node = UA_NODEID_STRING_ALLOC(namespace_index(),
                                       indentifier().string().c_str());
      break;
    case Identifier::Type::ByteString:
      break;
    case Identifier::Type::Guid:
      break;
  }
  return ua_node;
}

LocalizedText::LocalizedText(UA_LocalizedText const &display_name)
    : m_text{to_std_string(display_name.text)},
      m_locale{to_std_string(display_name.locale)} {}

LocalizedText::LocalizedText() : m_is_empty{true} {}

std::string LocalizedText::text() const { return m_text; }

std::string LocalizedText::locale() const { return m_locale; }

bool LocalizedText::is_empty() const { return m_is_empty; }

ReferenceDescription::ReferenceDescription(UA_ReferenceDescription const &ref)
    : m_ref{ref},
      m_node_id{NodeId(ref.nodeId.nodeId)},
      m_display_name{LocalizedText(ref.displayName)},
      m_browse_name{QualifiedName(ref.browseName)},
      m_type_definition{ExpandedNodeId(ref.typeDefinition)} {}

NodeId ReferenceDescription::node_id() const { return m_node_id; }

LocalizedText ReferenceDescription::display_name() const {
  return m_display_name;
}

QualifiedName ReferenceDescription::browse_name() const {
  return m_browse_name;
}

json ReferenceDescription::to_json() const {
  json j;
  j["DisplayName"] = display_name().text();
  j["BrowseName"] = browse_name().name();
  j["NodeId"] = node_id().to_json();
  j["TypeDefinition"] = type_definition().to_json();
  return j;
}

ExpandedNodeId ReferenceDescription::type_definition() const {
  return m_type_definition;
}

Node::Node(const NodeId &node_id, std::shared_ptr<Client> client)
    : m_node_id{node_id}, m_client{client} {
  BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Creating node";
}

std::vector<ReferenceDescription> Node::browse_children(
    BrowseResultMask mask,
    NodeClassMask node_class_mask,
    ReferenceTypeIdentifier id) {
  BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Browsing children";
  std::vector<ReferenceDescription> children;
  UA_BrowseRequest browse_req;
  UA_BrowseRequest_init(&browse_req);
  std::shared_ptr<UA_BrowseDescription> browse_desc(new UA_BrowseDescription);
  UA_BrowseDescription_init(browse_desc.get());
  browse_desc->nodeClassMask = node_class_mask;
  browse_req.requestedMaxReferencesPerNode = 0;
  browse_req.nodesToBrowse = browse_desc.get();
  browse_req.nodesToBrowseSize = 1;
  browse_req.nodesToBrowse[0].nodeId = m_node_id.ua_node_id();
  browse_req.nodesToBrowse[0].resultMask = static_cast<u_int32_t>(mask);
  browse_req.nodesToBrowse[0].referenceTypeId =
      UA_NODEID_NUMERIC(0, static_cast<u_int32_t>(id));
  browse_req.nodesToBrowse[0].includeSubtypes = true;

  UA_BrowseResponse browse_response = m_client->browse(browse_req);

  for (size_t i = 0; i < browse_response.resultsSize; ++i) {
    for (size_t j = 0; j < browse_response.results[i].referencesSize; ++j) {
      auto ref = ReferenceDescription(browse_response.results[i].references[j]);
      children.push_back(ref);
    }
  }
  UA_BrowseResponse_deleteMembers(&browse_response);
  return children;
}

NodeId Node::node_id() const { return NodeId(m_node_id); }

Client::Client()
    : m_client{std::shared_ptr<UA_Client>(
          UA_Client_new(UA_ClientConfig_default), UA_Client_delete)} {
  BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Creating client";
}

UA_BrowseResponse Client::browse(const UA_BrowseRequest &request) {
  UA_BrowseResponse browse_response =
      UA_Client_Service_browse(m_client.get(), request);
  return browse_response;
}

std::vector<EndpointDescription> Client::get_endpoints(Url const &url) {
  std::vector<EndpointDescription> result;
  UA_EndpointDescription *arr = nullptr;
  size_t len = 0;
  if (status_is_good(
          UA_Client_getEndpoints(m_client.get(), url.c_str(), &len, &arr))) {
    for (size_t i = 0; i < len; i++) {
      result.push_back(EndpointDescription(arr[i]));
    }
  }
  UA_Array_delete(arr, len, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION]);
  return result;
}

void Client::connect_to_endpoint(Url const &url) {
  if (status_is_good(UA_Client_connect(m_client.get(), url.c_str()))) {
    // TODO set state?
  }
}

void Client::connect_to_endpoint(EndpointDescription const &endpoint) {
  if (status_is_good(UA_Client_connect(
          m_client.get(),
          endpoint.to_json()["EndpointUrl"].get<std::string>().c_str()))) {
    // TODO set state?
  }
}

std::shared_ptr<Node> Client::node(NodeId const &node_id) {
  return std::make_shared<Node>(node_id, shared_from_this());
}

std::shared_ptr<Client> Client::client() { return shared_from_this(); }

std::shared_ptr<Client> Client::create() {
  return std::shared_ptr<Client>(new Client());
}

LocalizedText Client::read_display_name_attribute(const NodeId &node_id) const {
  UA_LocalizedText out;
  if (status_is_good(UA_Client_readDisplayNameAttribute(
          m_client.get(), node_id.ua_node_id(), &out))) {
    return LocalizedText(out);
  }
  return LocalizedText();
}

QualifiedName::QualifiedName(UA_QualifiedName const &name)
    : m_name{to_std_string(name.name)},
      m_namespace_index{name.namespaceIndex} {}

std::string QualifiedName::name() { return m_name; }

u_int16_t QualifiedName::namespace_index() { return m_namespace_index; }

ExpandedNodeId::ExpandedNodeId(UA_ExpandedNodeId const &expanded_node_id)
    : m_node_id{expanded_node_id.nodeId},
      m_namespace_uri{to_std_string(expanded_node_id.namespaceUri)},
      m_server_index{expanded_node_id.serverIndex} {}

ExpandedNodeId::ExpandedNodeId(NodeId const &node_id) : m_node_id{node_id} {}

ExpandedNodeId::ExpandedNodeId(NodeId const &node_id,
                               std::string const &namespace_uri,
                               u_int32_t server_index)
    : m_node_id{node_id},
      m_namespace_uri{namespace_uri},
      m_server_index{server_index} {}

std::string ExpandedNodeId::namespace_uri() const { return m_namespace_uri; }

NodeId ExpandedNodeId::node_id() const { return m_node_id; }

u_int32_t ExpandedNodeId::server_index() const { return m_server_index; }

json ExpandedNodeId::to_json() const {
  json j;
  j["NodeId"] = node_id().to_json();
  j["NamespaceUri"] = namespace_uri();
  j["SeverIndex"] = server_index();
  return j;
}

ApplicationDescription::ApplicationDescription(
    UA_ApplicationDescription const &application_description)
    : m_application_uri{to_std_string(application_description.applicationUri)},
      m_product_uri{to_std_string(application_description.productUri)},
      m_application_name{
          LocalizedText(application_description.applicationName)},
      m_application_type{
          ApplicationType(application_description.applicationType)},
      m_gateway_server_uri{
          to_std_string(application_description.gatewayServerUri)},
      m_discovery_profile_uri{
          to_std_string(application_description.discoveryProfileUri)} {
  for (size_t i = 0; i < application_description.discoveryUrlsSize; ++i) {
    std::string str = to_std_string(application_description.discoveryUrls[i]);
    m_discovery_urls.push_back(str);
  }
}

std::string ApplicationDescription::application_uri() const {
  return m_application_uri;
}

std::string ApplicationDescription::product_uri() const {
  return m_product_uri;
}

LocalizedText ApplicationDescription::application_name() const {
  return m_application_name;
}

ApplicationType ApplicationDescription::application_type() const {
  return m_application_type;
}

std::string ApplicationDescription::gateway_server_uri() const {
  return m_gateway_server_uri;
}

std::string ApplicationDescription::discovery_profile_uri() const {
  return m_discovery_profile_uri;
}

std::vector<std::string> ApplicationDescription::discovery_urls() const {
  return m_discovery_urls;
}

json ApplicationDescription::to_json() const {
  json j;
  j["ApplicationUri"] = m_application_uri;
  j["ProductUri"] = m_product_uri;
  j["ApplicationName"] = m_application_name.text();
  switch (m_application_type) {
    case ApplicationType::Server:
      j["ApplicationType"] = "Server";
      break;
    case ApplicationType::Client:
      j["ApplicationType"] = "Client";
      break;
    case ApplicationType::ClientAndServer:
      j["ApplicationType"] = "ClientAndServer";
      break;
    case ApplicationType::DiscoveryServer:
      j["ApplicationType"] = "DiscoveryServer";
      break;
  }
  j["GatewayServerUri"] = m_gateway_server_uri;
  j["DiscoveryProfileUri"] = m_discovery_profile_uri;
  j["DiscoveryUrls"] = m_discovery_urls;
  return j;
}

Certificate::Certificate(UA_ByteString const &certificate)
    : m_certificate{to_std_string(certificate)} {}

std::string Certificate::to_string() const { return m_certificate; }

UserTokenPolicy::UserTokenPolicy(UA_UserTokenPolicy user_token_policy)
    : m_policy_id{to_std_string(user_token_policy.policyId)},
      m_token_type{UserTokenType(user_token_policy.tokenType)},
      m_issued_token_type{to_std_string(user_token_policy.issuedTokenType)},
      m_issuer_endpoint_url{to_std_string(user_token_policy.issuerEndpointUrl)},
      m_security_policy_uri{
          to_std_string(user_token_policy.securityPolicyUri)} {}

std::string UserTokenPolicy::policy_id() const { return m_policy_id; }

UserTokenType UserTokenPolicy::token_type() const { return m_token_type; }

std::string UserTokenPolicy::issued_token_type() const {
  return m_issued_token_type;
}

std::string UserTokenPolicy::issuer_endpoint_url() const {
  return m_issuer_endpoint_url;
}

std::string UserTokenPolicy::security_policy_uri() const {
  return m_security_policy_uri;
}

json UserTokenPolicy::to_json() const {
  json j;
  j["PolicyId"] = m_policy_id;
  j["IssuedTokenType"] = m_issued_token_type;
  j["IssuerEndpointUrl"] = m_policy_id;
  j["SecurityPolicyUri"] = m_policy_id;

  switch (m_token_type) {
    case UserTokenType::Anonymous:
      j["UserTokenType"] = "Anonymous";
      break;
    case UserTokenType::UserName:
      j["UserTokenType"] = "UserName";
      break;
    case UserTokenType::Certificate:
      j["UserTokenType"] = "Certificate";
      break;
    case UserTokenType::IssuedToken:
      j["UserTokenType"] = "IssuedToken";
      break;
  }

  return j;
}

};  // namespace open62541
