#ifndef OPEN62541_CPP_WRAPPER_ENUMS_H
#define OPEN62541_CPP_WRAPPER_ENUMS_H

#include <cstdint>
#include <iostream>

namespace open62541 {

enum class UserTokenType : uint32_t {
  Anonymous = 0,
  UserName = 1,
  Certificate = 2,
  IssuedToken = 3
};

inline std::ostream &operator<<(std::ostream &out, UserTokenType const &op) {
  switch (op) {
    case UserTokenType::Anonymous:
      out << "Anonymous";
      break;
    case UserTokenType::UserName:
      out << "UserName";
      break;
    case UserTokenType::Certificate:
      out << "Certificate";
      break;
    case UserTokenType::IssuedToken:
      out << "IssuedToken";
      break;
  }
  return out;
}

enum class StatusCode : uint32_t {
  // TODO
};

enum class IdentifierType : uint32_t { Numeric, String, Guid, ByteString };

inline std::ostream &operator<<(std::ostream &out, IdentifierType const &op) {
  switch (op) {
    case IdentifierType::Numeric:
      out << "Numeric";
      break;
    case IdentifierType::String:
      out << "String";
      break;
    case IdentifierType::Guid:
      out << "Guid";
      break;
    case IdentifierType::ByteString:
      out << "ByteString";
      break;
  }
  return out;
}

enum class MessageSecurityMode : uint32_t {
  Invalid = 0,
  None = 1,
  Sign = 2,
  SignAndEncrypt = 3
};

inline std::ostream &operator<<(std::ostream &out,
                                MessageSecurityMode const &op) {
  switch (op) {
    case MessageSecurityMode::Invalid:
      out << "Invalid";
      break;
    case MessageSecurityMode::None:
      out << "None";
      break;
    case MessageSecurityMode::Sign:
      out << "Sign";
      break;
    case MessageSecurityMode::SignAndEncrypt:
      out << "SignAndEncrypt";
      break;
  }
  return out;
}
enum class ApplicationType : uint32_t {
  Server = 0,
  Client = 1,
  ClientAndServer = 2,
  DiscoveryServer = 3,
};

inline std::ostream &operator<<(std::ostream &out, const ApplicationType &op) {
  switch (op) {
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

inline std::ostream &operator<<(std::ostream &out, BrowseDirection const &op) {
  switch (op) {
    case BrowseDirection::Forward:
      out << "Forward";
      break;
    case BrowseDirection::Inverse:
      out << "Inverse";
      break;
    case BrowseDirection::Both:
      out << "Both";
      break;
    case BrowseDirection::Invalid:
      out << "Invalid";
      break;
  }
  return out;
}

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

inline std::ostream &operator<<(std::ostream &out, BrowseResultMask const &op) {
  switch (op) {
    case BrowseResultMask::None:
      out << "None";
      break;
    case BrowseResultMask::ReferenceTypeId:
      out << "ReferenceTypeId";
      break;
    case BrowseResultMask::IsForward:
      out << "IsForward";
      break;
    case BrowseResultMask::NodeClass:
      out << "NodeClass";
      break;
    case BrowseResultMask::QualifiedName:
      out << "QualifiedName";
      break;
    case BrowseResultMask::LocalizedText:
      out << "LocalizedText ";
      break;
    case BrowseResultMask::TypeDefinition:
      out << "TypeDefinition ";
      break;
    case BrowseResultMask::All:
      out << "All ";
      break;
    case BrowseResultMask::ReferencetypeInfo:
      out << "ReferencetypeInfo";
      break;
    case BrowseResultMask::TargetInfo:
      out << "TargetInfo";
      break;
  }
  return out;
}

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

inline std::ostream &operator<<(std::ostream &out,
                                ReferenceTypeIdentifier const &op) {
  switch (op) {
    case ReferenceTypeIdentifier::Unspecified:
      out << "Unspecified";
      break;
    case ReferenceTypeIdentifier::References:
      out << "References ";
      break;
    case ReferenceTypeIdentifier::NonHierarchicalReferences:
      out << "NonHierarchicalReferences";
      break;
    case ReferenceTypeIdentifier::HierarchicalReferences:
      out << "HierarchicalReferences";
      break;
    case ReferenceTypeIdentifier::HasChild:
      out << "HasChild";
      break;
    case ReferenceTypeIdentifier::Organizes:
      out << "Organizes";
      break;
    case ReferenceTypeIdentifier::HasEventSource:
      out << "HasEventSource";
      break;
    case ReferenceTypeIdentifier::HasModellingRule:
      out << "HasModellingRule";
      break;
    case ReferenceTypeIdentifier::HasEncoding:
      out << "HasEncoding";
      break;
    case ReferenceTypeIdentifier::HasDescription:
      out << "HasDescription";
      break;
    case ReferenceTypeIdentifier::HasTypeDefinition:
      out << "HasTypeDefinition";
      break;
    case ReferenceTypeIdentifier::GeneratesEvent:
      out << "GeneratesEvent";
      break;
    case ReferenceTypeIdentifier::Aggregates:
      out << "Aggregates";
      break;
    case ReferenceTypeIdentifier::HasSubtype:
      out << "HasSubtype";
      break;
    case ReferenceTypeIdentifier::HasProperty:
      out << "HasProperty";
      break;
    case ReferenceTypeIdentifier::HasComponent:
      out << "HasComponent";
      break;
    case ReferenceTypeIdentifier::HasNotifier:
      out << "HasNotifier";
      break;
    case ReferenceTypeIdentifier::HasOrderedComponent:
      out << "HasOrderedComponent";
      break;
    case ReferenceTypeIdentifier::FromState:
      out << "FromState";
      break;
    case ReferenceTypeIdentifier::ToState:
      out << "ToState";
      break;
    case ReferenceTypeIdentifier::HasCause:
      out << "HasCause";
      break;
    case ReferenceTypeIdentifier::HasEffect:
      out << "HasEffect";
      break;
    case ReferenceTypeIdentifier::HasHistoricalConfiguration:
      out << "HasHistoricalConfiguration";
      break;
    case ReferenceTypeIdentifier::HasSubStateMachine:
      out << "HasSubStateMachine";
      break;
    case ReferenceTypeIdentifier::AlwaysGeneratesEvent:
      out << "AlwaysGeneratesEvent";
      break;
    case ReferenceTypeIdentifier::HasTrueSubState:
      out << "HasTrueSubState";
      break;
    case ReferenceTypeIdentifier::HasFalseSubState:
      out << "HasFalseSubState";
      break;
    case ReferenceTypeIdentifier::HasCondition:
      out << "HasCondition";
      break;
  }
  return out;
}

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

inline std::ostream &operator<<(std::ostream &out, NodeClass const &op) {
  switch (op) {
    case NodeClass::Unspecified:
      out << "Unspecified";
      break;
    case NodeClass::Object:
      out << "Object";
      break;
    case NodeClass::Variable:
      out << "Variable";
      break;
    case NodeClass::Method:
      out << "Method";
      break;
    case NodeClass::ObjectType:
      out << "ObjectType";
      break;
    case NodeClass::VariableType:
      out << "VariableType";
      break;
    case NodeClass::ReferenceType:
      out << "ReferenceType";
      break;
    case NodeClass::DataType:
      out << "DataType";
      break;
    case NodeClass::View:
      out << "View";
      break;
    case NodeClass::All:
      out << "All";
      break;
  }
  return out;
}

enum class ClientState : uint32_t {
  Disconnected = 0,
  Connected = 1,
  SecureChannel = 2,
  Session = 3,
  SessionRenewed = 4
};

inline std::ostream &operator<<(std::ostream &out, ClientState const &op) {
  switch (op) {
    case ClientState::Disconnected:
      out << "Disconnected";
      break;
    case ClientState::Connected:
      out << "Connected";
      break;
    case ClientState::SecureChannel:
      out << "SecureChannel";
      break;
    case ClientState::Session:
      out << "Session";
      break;
    case ClientState::SessionRenewed:
      out << "SessionRenewed";
      break;
  }
  return out;
}

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_ENUMS_H
