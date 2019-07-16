#ifndef OPEN62541_CPP_WRAPPER_PARSER_H
#define OPEN62541_CPP_WRAPPER_PARSER_H

#include "open62541.h"

#include "applicationdescription.hpp"
#include "datetime.hpp"
#include "endpointdescription.hpp"
#include "referencedescription.hpp"

#include <nlohmann/json.hpp>

namespace open62541 {

namespace parser {
using namespace nlohmann;

inline std::string from_open62541(UA_String const &str) {
  return std::string(str.data, str.data + str.length);
}

inline LocalizedText from_open62541(UA_LocalizedText const &lt) {
  return LocalizedText(from_open62541(lt.text), from_open62541(lt.locale));
}

inline ApplicationDescription from_open62541(
    UA_ApplicationDescription const &ad) {
  std::vector<std::string> discovery_urls;
  if (ad.discoveryUrls) {
    for (size_t i = 0; i < ad.discoveryUrlsSize; ++i) {
      discovery_urls.push_back(from_open62541(ad.discoveryUrls[i]));
    }
  }
  return ApplicationDescription{from_open62541(ad.applicationUri),
                                from_open62541(ad.productUri),
                                from_open62541(ad.applicationName),
                                ApplicationType{ad.applicationType},
                                from_open62541(ad.gatewayServerUri),
                                from_open62541(ad.discoveryProfileUri),
                                discovery_urls};
}

inline UserTokenPolicy from_open62541(UA_UserTokenPolicy const &up) {
  return UserTokenPolicy{from_open62541(up.policyId),
                         UserTokenType{up.tokenType},
                         from_open62541(up.issuedTokenType),
                         from_open62541(up.issuerEndpointUrl),
                         from_open62541(up.securityPolicyUri)};
}

inline EndpointDescription from_open62541(UA_EndpointDescription const &ed) {
  std::vector<UserTokenPolicy> user_identity_tokens;
  for (size_t i = 0; i < ed.userIdentityTokensSize; ++i) {
    auto policy = from_open62541(ed.userIdentityTokens[i]);
    user_identity_tokens.push_back(policy);
  }
  return EndpointDescription{from_open62541(ed.endpointUrl),
                             from_open62541(ed.server),
                             from_open62541(ed.serverCertificate),
                             MessageSecurityMode{ed.securityMode},
                             from_open62541(ed.securityPolicyUri),
                             user_identity_tokens,
                             from_open62541(ed.transportProfileUri),
                             ed.securityLevel};
}

inline Guid from_open62541(UA_Guid const &g) {
  return Guid{g.data1,
              g.data2,
              g.data3,
              g.data4[0] | g.data4[1] << 1 | g.data4[2] << 2 | g.data4[3] << 3 |
                  g.data4[4] << 4 | g.data4[5] << 5 | g.data4[6] << 6 |
                  g.data4[7] << 7};
}

inline NodeId from_open62541(UA_NodeId const &ni) {
  switch (ni.identifierType) {
    case UA_NODEIDTYPE_NUMERIC:
      return NodeId(ni.namespaceIndex,
                    Identifier(ni.identifier.numeric),
                    IdentifierType{ni.identifierType});
    case UA_NODEIDTYPE_STRING:
      return NodeId(ni.namespaceIndex,
                    Identifier(from_open62541(ni.identifier.string)),
                    IdentifierType{ni.identifierType});
    case UA_NODEIDTYPE_GUID:
      return NodeId(ni.namespaceIndex,
                    Identifier(from_open62541(ni.identifier.guid)),
                    IdentifierType{ni.identifierType});
    case UA_NODEIDTYPE_BYTESTRING:
      return NodeId(ni.namespaceIndex,
                    Identifier(from_open62541(ni.identifier.byteString)),
                    IdentifierType{ni.identifierType});
  }
  return NodeId();
}

inline QualifiedName from_open62541(UA_QualifiedName const &qn) {
  return QualifiedName{from_open62541(qn.name), qn.namespaceIndex};
}

inline ExpandedNodeId from_open62541(UA_ExpandedNodeId const &en) {
  return ExpandedNodeId{from_open62541(en.nodeId),
                        from_open62541(en.namespaceUri),
                        en.serverIndex};
}

inline ReferenceDescription from_open62541(UA_ReferenceDescription const &rd) {
  return ReferenceDescription{from_open62541(rd.referenceTypeId),
                              rd.isForward,
                              from_open62541(rd.nodeId),
                              from_open62541(rd.browseName),
                              from_open62541(rd.displayName),
                              NodeClass{rd.nodeClass},
                              from_open62541(rd.typeDefinition)

  };
}

inline DateTime from_open62541(UA_DateTime const &d) { return DateTime(d); }



inline UA_NodeId to_open62541(NodeId const &ni) {
  UA_NodeId id;
  id.identifierType = static_cast<UA_NodeIdType>(ni.identifier_type());
  switch (ni.identifier_type()) {
    case IdentifierType::Guid:
      id.identifierType = UA_NODEIDTYPE_GUID;
      break;
    case IdentifierType::String:
      id.identifierType = UA_NODEIDTYPE_STRING;
      break;
    case IdentifierType::Numeric:
      id.identifierType = UA_NODEIDTYPE_NUMERIC;
      break;
    case IdentifierType::ByteString:
      id.identifierType = UA_NODEIDTYPE_BYTESTRING;
      break;
  }
  return id;
}

inline UA_ExpandedNodeId to_open62541(ExpandedNodeId const &ni) {
  UA_ExpandedNodeId id;
  id.nodeId = to_open62541(ni.node_id());
  id.serverIndex = ni.server_index();
  id.namespaceUri = UA_STRING_ALLOC(ni.namespace_uri().c_str());
  return id;
}

template <typename T>
inline T from_json(json const &j);

template <>
inline NodeId from_json<NodeId>(json const &j) {
  /*
   * The IdentifierType encoded as a JSON number.
   * Allowed values are:
   * 0 - UInt32 Identifier encoded as a JSON number.
   * 1 - A String Identifier encoded as a JSON string.
   * 2 - A Guid Identifier encoded as described in 5.4.2.7.
   * 3 - A ByteString Identifier encoded as described in 5.4.2.8.
   * This field is omitted for UInt32 identifiers.
   */

  auto id = j["Id"];
  auto id_type = j["IdType"].get<int>();
  switch (id_type) {
    case 0:
      return NodeId(j["Namespace"],
                    Identifier(id.get<uint32_t>()),
                    IdentifierType::Numeric);
    case 1:
      return NodeId(j["Namespace"],
                    Identifier(id.get<std::string>()),
                    IdentifierType::String);
    case 2:
      return NodeId(j["Namespace"],
                    Identifier(Guid(id.get<std::string>())),
                    IdentifierType::Guid);
    case 3:
      return NodeId(j["Namespace"],
                    Identifier(ByteString(id.get<std::string>())),
                    IdentifierType::ByteString);
  }
  return NodeId();
}

inline json to_json(NodeId const &ni) {
  json j;
  j["Namespace"] = ni.namespace_index();
  j["IdType"] = ni.identifier_type();
  switch (ni.identifier_type()) {
    case IdentifierType::Guid:
      j["Identifier"] = ni.identifier().guid().str();
      break;
    case IdentifierType::String:
      j["Identifier"] = ni.identifier().string();
      break;
    case IdentifierType::Numeric:
      j["Identifier"] = ni.identifier().numeric();
      break;
    case IdentifierType::ByteString:
      j["Identifier"] = ni.identifier().byte_string();
      break;
  }
  return j;
}
inline json to_json(ApplicationDescription const &ad) {
  json app_description;
  app_description["ApplicationUri"] = ad.application_uri();
  app_description["ProductUri"] = ad.product_uri();
  app_description["ApplicationName"] = ad.application_name().text();
  switch (ad.application_type()) {
    case ApplicationType::Server:
      app_description["ApplicationType"] = "Server";
      break;
    case ApplicationType::Client:
      app_description["ApplicationType"] = "Client";
      break;
    case ApplicationType::ClientAndServer:
      app_description["ApplicationType"] = "ClientAndServer";
      break;
    case ApplicationType::DiscoveryServer:
      app_description["ApplicationType"] = "DiscoveryServer";
      break;
  }
  app_description["GatewayServerUri"] = ad.gateway_server_uri();
  app_description["DiscoveryProfileUri"] = ad.discovery_profile_uri();
  app_description["DiscoveryUrls"] = ad.discovery_urls();
  return app_description;
}

inline json to_json(UserTokenPolicy const &up) {}

inline json to_json(EndpointDescription const &ed) {
  json endpoint_desc;
  endpoint_desc["EndpointUrl"] = ed.endpoint_url();
  //  endpoint_desc["Server"] = ed.server.to_json();
  //  endpoint_desc["Certificate"] = ed.server_certificate.str();

  switch (ed.security_mode()) {
    case MessageSecurityMode::Invalid:
      endpoint_desc["SecurityMode"] = "Invalid";
      break;
    case MessageSecurityMode::None:
      endpoint_desc["SecurityMode"] = "None";
      break;
    case MessageSecurityMode::Sign:
      endpoint_desc["SecurityMode"] = "Sign";
      break;
    case MessageSecurityMode::SignAndEncrypt:
      endpoint_desc["SecurityMode"] = "SignAndEncrypt";
      break;
  }

  endpoint_desc["SecurityPolicyUri"] = ed.security_policy_uri();
  endpoint_desc["TransportProfileUri"] = ed.transport_profile_uri();
  endpoint_desc["SecurityLevel"] = ed.security_level();

  json policies;
  std::for_each(
      ed.user_identity_tokens().begin(),
      ed.user_identity_tokens().end(),
      [&](UserTokenPolicy const &p) { policies.push_back(to_json(p)); });
  endpoint_desc["UserIdentityTokens"] = policies;
  return endpoint_desc;
}

inline json to_json(ExpandedNodeId const &en) {
  json exp_node_id;
  exp_node_id["NodeId"] = to_json(en.node_id());
  exp_node_id["NamespaceUri"] = en.namespace_uri();
  exp_node_id["SeverIndex"] = en.server_index();
  return exp_node_id;
}

// json UserTokenPolicy::to_json() const {
//  json policy;
//  policy["PolicyId"] = m_policy_id;
//  policy["IssuedTokenType"] = m_issued_token_type;
//  policy["IssuerEndpointUrl"] = m_policy_id;
//  policy["SecurityPolicyUri"] = m_policy_id;
//  switch (m_token_type) {
//    case UserTokenType::Anonymous:
//      policy["UserTokenType"] = "Anonymous";
//      break;
//    case UserTokenType::UserName:
//      policy["UserTokenType"] = "UserName";
//      break;
//    case UserTokenType::Certificate:
//      policy["UserTokenType"] = "Certificate";
//      break;
//    case UserTokenType::IssuedToken:
//      policy["UserTokenType"] = "IssuedToken";
//      break;
//  }
//  return policy;
//}

}  // namespace parser

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_PARSER_H
