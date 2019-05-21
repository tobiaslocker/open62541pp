#ifndef OPEN62541_CPP_WRAPPER_ENUMS_H
#define OPEN62541_CPP_WRAPPER_ENUMS_H

#include <cstdint>
#include <iostream>

namespace open62541 {

enum class IdentifierType : uint32_t { Numeric, String, Guid, ByteString };

// std::ostream &operator<<(std::ostream &out,
//                         IdentifierType const &identifier_type);

enum class MessageSecurityMode : uint32_t {
  Invalid = 0,
  None = 1,
  Sign = 2,
  SignAndEncrypt = 3
};

enum class ApplicationType : uint32_t {
  Server = 0,
  Client = 1,
  ClientAndServer = 2,
  DiscoveryServer = 3,
};

inline std::ostream &operator<<(std::ostream &out, const ApplicationType &a) {
  switch (a) {
    case ApplicationType::Server:
      out << "Server";
      break;
    case ApplicationType::Client:
      out << "Client";
      break;
    case ApplicationType::ClientAndServer:
      out << "ClientAndServer";
      break;
    case ApplicationType::DiscoveryServer:
      out << "DiscoveryServer";
      break;
  }
  return out;
}

enum class BrowseDirection : uint32_t {
  Forward = 0,
  Inverse = 1,
  Both = 2,
  Invalid = 3,
};

enum class BrowseResultMask : uint32_t {
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

enum class ReferenceTypeIdentifier : uint32_t {
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

enum class NodeClass : uint32_t {
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
  uint32_t m_node_class_mask = 0;
  NodeClassMask(NodeClass const &node_class_mask)
      : m_node_class_mask{static_cast<uint32_t>(node_class_mask)} {}
  operator uint32_t() const { return m_node_class_mask; }
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_ENUMS_H
