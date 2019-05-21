#ifndef OPEN62541_CPP_WRAPPER_PARSER_H
#define OPEN62541_CPP_WRAPPER_PARSER_H

#include "open62541.h"

#include "applicationdescription.hpp"
#include "endpointdescription.hpp"
#include "referencedescription.hpp"

namespace open62541 {

namespace parser {

std::string from_open62541(UA_String const &str) {
  return std::string(str.data, str.data + str.length);
}

LocalizedText from_open62541(UA_LocalizedText const &lt) {
  return LocalizedText(from_open62541(lt.text), from_open62541(lt.locale));
}

ApplicationDescription from_open62541(UA_ApplicationDescription const &ad) {
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

EndpointDescription from_open62541(UA_EndpointDescription const &ed) {
  std::vector<UserTokenPolicy> user_identity_tokens;
  for (size_t i = 0; i < ed.userIdentityTokensSize; ++i) {
    auto policy = UserTokenPolicy(ed.userIdentityTokens[i]);
    user_identity_tokens.push_back(policy);
  }
  return EndpointDescription{from_open62541(ed.endpointUrl),
                             from_open62541(ed.server),
                             Certificate(from_open62541(ed.serverCertificate)),
                             MessageSecurityMode{ed.securityMode},
                             from_open62541(ed.securityPolicyUri),
                             user_identity_tokens,
                             from_open62541(ed.transportProfileUri),
                             ed.securityLevel};
}

Guid from_open62541(UA_Guid const &g) {
  return Guid{g.data1,
              g.data2,
              g.data3,
              g.data4[0] | g.data4[1] << 1 | g.data4[2] << 2 | g.data4[3] << 3 |
                  g.data4[4] << 4 | g.data4[5] << 5 | g.data4[6] << 6 |
                  g.data4[7] << 7};
}

NodeId from_open62541(UA_NodeId const &ni) {
  switch (ni.identifierType) {
    case UA_NODEIDTYPE_NUMERIC:
      return NodeId(ni.namespaceIndex, Identifier(ni.identifier.numeric));
    case UA_NODEIDTYPE_STRING:
      return NodeId(ni.namespaceIndex,
                    Identifier(from_open62541(ni.identifier.string)));
    case UA_NODEIDTYPE_GUID:
      return NodeId(ni.namespaceIndex,
                    Identifier(from_open62541(ni.identifier.guid)));
    case UA_NODEIDTYPE_BYTESTRING:
      return NodeId(ni.namespaceIndex,
                    Identifier(from_open62541(ni.identifier.byteString)));
  }
  return NodeId();
}

QualifiedName from_open62541(UA_QualifiedName const &qn) {
  return QualifiedName{from_open62541(qn.name), qn.namespaceIndex};
}

ExpandedNodeId from_open62541(UA_ExpandedNodeId const &en) {
  return ExpandedNodeId{from_open62541(en.nodeId),
                        from_open62541(en.namespaceUri),
                        en.serverIndex};
}

ReferenceDescription from_open62541(UA_ReferenceDescription const &rd) {
  return ReferenceDescription{from_open62541(rd.referenceTypeId),
                              rd.isForward,
                              from_open62541(rd.nodeId),
                              from_open62541(rd.browseName),
                              from_open62541(rd.displayName),
                              NodeClass{rd.nodeClass},
                              from_open62541(rd.typeDefinition)

  };
}

UA_NodeId to_open62541(NodeId const &ni) {}

UA_ExpandedNodeId to_open62541(ExpandedNodeId const &ni) {}

template <typename T>
T from_json(json const &j);

template <>
NodeId from_json<NodeId>(json const &j) {}

// NodeId::NodeId(json const &node_id) : m_namespace_index{node_id["Namespace"]}
// {
//  /*
//   * The IdentifierType encoded as a JSON number.
//   * Allowed values are:
//   * 0 - UInt32 Identifier encoded as a JSON number.
//   * 1 - A String Identifier encoded as a JSON string.
//   * 2 - A Guid Identifier encoded as described in 5.4.2.7.
//   * 3 - A ByteString Identifier encoded as described in 5.4.2.8.
//   * This field is omitted for UInt32 identifiers.
//   */

////  if (node_id["IdType"].is_number()) {
////    auto id = node_id["Id"];
////    auto id_type = node_id["IdType"].get<int>();
////    switch (id_type) {
////      case 0:
////        m_identifier = Identifier(id.get<uint32_t>());
////        break;
////      case 1:
////        m_identifier = Identifier(id.get<std::string>());
////        break;
////      case 2:
////        m_identifier = Identifier(Guid(id.get<std::string>()));
////        break;
////      case 3:
////        m_identifier =
////            Identifier(ByteString::from_base_64(id.get<std::string>()));
////        break;
////      default:
////        // TODO: handle error case
////        break;
////    }
////  } else {
////  }
//}

};  // namespace parser

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_PARSER_H
