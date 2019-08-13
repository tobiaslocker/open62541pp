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
  GOOD = 0x00,
  BADUNEXPECTEDERROR = 0x80010000,
  BADINTERNALERROR = 0x80020000,
  BADOUTOFMEMORY = 0x80030000,
  BADRESOURCEUNAVAILABLE = 0x80040000,
  BADCOMMUNICATIONERROR = 0x80050000,
  BADENCODINGERROR = 0x80060000,
  BADDECODINGERROR = 0x80070000,
  BADENCODINGLIMITSEXCEEDED = 0x80080000,
  BADREQUESTTOOLARGE = 0x80b80000,
  BADRESPONSETOOLARGE = 0x80b90000,
  BADUNKNOWNRESPONSE = 0x80090000,
  BADTIMEOUT = 0x800a0000,
  BADSERVICEUNSUPPORTED = 0x800b0000,
  BADSHUTDOWN = 0x800c0000,
  BADSERVERNOTCONNECTED = 0x800d0000,
  BADSERVERHALTED = 0x800e0000,
  BADNOTHINGTODO = 0x800f0000,
  BADTOOMANYOPERATIONS = 0x80100000,
  BADTOOMANYMONITOREDITEMS = 0x80db0000,
  BADDATATYPEIDUNKNOWN = 0x80110000,
  BADCERTIFICATEINVALID = 0x80120000,
  BADSECURITYCHECKSFAILED = 0x80130000,
  BADCERTIFICATETIMEINVALID = 0x80140000,
  BADCERTIFICATEISSUERTIMEINVALID = 0x80150000,
  BADCERTIFICATEHOSTNAMEINVALID = 0x80160000,
  BADCERTIFICATEURIINVALID = 0x80170000,
  BADCERTIFICATEUSENOTALLOWED = 0x80180000,
  BADCERTIFICATEISSUERUSENOTALLOWED = 0x80190000,
  BADCERTIFICATEUNTRUSTED = 0x801a0000,
  BADCERTIFICATEREVOCATIONUNKNOWN = 0x801b0000,
  BADCERTIFICATEISSUERREVOCATIONUNKNOWN = 0x801c0000,
  BADCERTIFICATEREVOKED = 0x801d0000,
  BADCERTIFICATEISSUERREVOKED = 0x801e0000,
  BADCERTIFICATECHAININCOMPLETE = 0x810d0000,
  BADUSERACCESSDENIED = 0x801f0000,
  BADIDENTITYTOKENINVALID = 0x80200000,
  BADIDENTITYTOKENREJECTED = 0x80210000,
  BADSECURECHANNELIDINVALID = 0x80220000,
  BADINVALIDTIMESTAMP = 0x80230000,
  BADNONCEINVALID = 0x80240000,
  BADSESSIONIDINVALID = 0x80250000,
  BADSESSIONCLOSED = 0x80260000,
  BADSESSIONNOTACTIVATED = 0x80270000,
  BADSUBSCRIPTIONIDINVALID = 0x80280000,
  BADREQUESTHEADERINVALID = 0x802a0000,
  BADTIMESTAMPSTORETURNINVALID = 0x802b0000,
  BADREQUESTCANCELLEDBYCLIENT = 0x802c0000,
  BADTOOMANYARGUMENTS = 0x80e50000,
  BADLICENSEEXPIRED = 0x810E0000,
  BADLICENSELIMITSEXCEEDED = 0x810F0000,
  BADLICENSENOTAVAILABLE = 0x81100000,
  GOODSUBSCRIPTIONTRANSFERRED = 0x002d0000,
  GOODCOMPLETESASYNCHRONOUSLY = 0x002e0000,
  GOODOVERLOAD = 0x002f0000,
  GOODCLAMPED = 0x00300000,
  BADNOCOMMUNICATION = 0x80310000,
  BADWAITINGFORINITIALDATA = 0x80320000,
  BADNODEIDINVALID = 0x80330000,
  BADNODEIDUNKNOWN = 0x80340000,
  BADATTRIBUTEIDINVALID = 0x80350000,
  BADINDEXRANGEINVALID = 0x80360000,
  BADINDEXRANGENODATA = 0x80370000,
  BADDATAENCODINGINVALID = 0x80380000,
  BADDATAENCODINGUNSUPPORTED = 0x80390000,
  BADNOTREADABLE = 0x803a0000,
  BADNOTWRITABLE = 0x803b0000,
  BADOUTOFRANGE = 0x803c0000,
  BADNOTSUPPORTED = 0x803d0000,
  BADNOTFOUND = 0x803e0000,
  BADOBJECTDELETED = 0x803f0000,
  BADNOTIMPLEMENTED = 0x80400000,
  BADMONITORINGMODEINVALID = 0x80410000,
  BADMONITOREDITEMIDINVALID = 0x80420000,
  BADMONITOREDITEMFILTERINVALID = 0x80430000,
  BADMONITOREDITEMFILTERUNSUPPORTED = 0x80440000,
  BADFILTERNOTALLOWED = 0x80450000,
  BADSTRUCTUREMISSING = 0x80460000,
  BADEVENTFILTERINVALID = 0x80470000,
  BADCONTENTFILTERINVALID = 0x80480000,
  BADFILTEROPERATORINVALID = 0x80c10000,
  BADFILTEROPERATORUNSUPPORTED = 0x80c20000,
  BADFILTEROPERANDCOUNTMISMATCH = 0x80c30000,
  BADFILTEROPERANDINVALID = 0x80490000,
  BADFILTERELEMENTINVALID = 0x80c40000,
  BADFILTERLITERALINVALID = 0x80c50000,
  BADCONTINUATIONPOINTINVALID = 0x804a0000,
  BADNOCONTINUATIONPOINTS = 0x804b0000,
  BADREFERENCETYPEIDINVALID = 0x804c0000,
  BADBROWSEDIRECTIONINVALID = 0x804d0000,
  BADNODENOTINVIEW = 0x804e0000,
  BADSERVERURIINVALID = 0x804f0000,
  BADSEMPAHOREFILEMISSING = 0x80520000,
  BADREQUESTTYPEINVALID = 0x80530000,
  BADSECURITYMODEREJECTED = 0x80540000,
  BADSECURITYPOLICYREJECTED = 0x80550000,
  BADTOOMANYSESSIONS = 0x80560000,
  BADUSERSIGNATUREINVALID = 0x80570000,
  BADAPPLICATIONSIGNATUREINVALID = 0x80580000,
  BADNOVALIDCERTIFICATES = 0x80590000,
  BADIDENTITYCHANGENOTSUPPORTED = 0x80c60000,
  BADREQUESTCANCELLEDBYREQUEST = 0x805a0000,
  BADPARENTNODEIDINVALID = 0x805b0000,
  BADREFERENCENOTALLOWED = 0x805c0000,
  BADNODEIDREJECTED = 0x805d0000,
  BADNODEIDEXISTS = 0x805e0000,
  BADNODECLASSINVALID = 0x805f0000,
  BADBROWSENAMEINVALID = 0x80600000,
  BADBROWSENAMEDUPLICATED = 0x80610000,
  BADNODEATTRIBUTESINVALID = 0x80620000,
  BADTYPEDEFINITIONINVALID = 0x80630000,
  BADSOURCENODEIDINVALID = 0x80640000,
  BADTARGETNODEIDINVALID = 0x80650000,
  BADDUPLICATEREFERENCENOTALLOWED = 0x80660000,
  BADINVALIDSELFREFERENCE = 0x80670000,
  BADREFERENCELOCALONLY = 0x80680000,
  BADNODELETERIGHTS = 0x80690000,
  UNCERTAINREFERENCENOTDELETED = 0x40bc0000,
  BADSERVERINDEXINVALID = 0x806a0000,
  BADVIEWIDUNKNOWN = 0x806b0000,
  BADVIEWTIMESTAMPINVALID = 0x80c90000,
  BADVIEWPARAMETERMISMATCH = 0x80ca0000,
  BADVIEWVERSIONINVALID = 0x80cb0000,
  UNCERTAINNOTALLNODESAVAILABLE = 0x40c00000,
  GOODRESULTSMAYBEINCOMPLETE = 0x00ba0000,
  BADNOTTYPEDEFINITION = 0x80c80000,
  UNCERTAINREFERENCEOUTOFSERVER = 0x406c0000,
  BADTOOMANYMATCHES = 0x806d0000,
  BADQUERYTOOCOMPLEX = 0x806e0000,
  BADNOMATCH = 0x806f0000,
  BADMAXAGEINVALID = 0x80700000,
  BADSECURITYMODEINSUFFICIENT = 0x80e60000,
  BADHISTORYOPERATIONINVALID = 0x80710000,
  BADHISTORYOPERATIONUNSUPPORTED = 0x80720000,
  BADINVALIDTIMESTAMPARGUMENT = 0x80bd0000,
  BADWRITENOTSUPPORTED = 0x80730000,
  BADTYPEMISMATCH = 0x80740000,
  BADMETHODINVALID = 0x80750000,
  BADARGUMENTSMISSING = 0x80760000,
  BADTOOMANYSUBSCRIPTIONS = 0x80770000,
  BADTOOMANYPUBLISHREQUESTS = 0x80780000,
  BADNOSUBSCRIPTION = 0x80790000,
  BADSEQUENCENUMBERUNKNOWN = 0x807a0000,
  BADMESSAGENOTAVAILABLE = 0x807b0000,
  BADINSUFFICIENTCLIENTPROFILE = 0x807c0000,
  BADSTATENOTACTIVE = 0x80bf0000,
  BADTCPSERVERTOOBUSY = 0x807d0000,
  BADTCPMESSAGETYPEINVALID = 0x807e0000,
  BADTCPSECURECHANNELUNKNOWN = 0x807f0000,
  BADTCPMESSAGETOOLARGE = 0x80800000,
  BADTCPNOTENOUGHRESOURCES = 0x80810000,
  BADTCPINTERNALERROR = 0x80820000,
  BADTCPENDPOINTURLINVALID = 0x80830000,
  BADREQUESTINTERRUPTED = 0x80840000,
  BADREQUESTTIMEOUT = 0x80850000,
  BADSECURECHANNELCLOSED = 0x80860000,
  BADSECURECHANNELTOKENUNKNOWN = 0x80870000,
  BADSEQUENCENUMBERINVALID = 0x80880000,
  BADPROTOCOLVERSIONUNSUPPORTED = 0x80be0000,
  BADCONFIGURATIONERROR = 0x80890000,
  BADNOTCONNECTED = 0x808a0000,
  BADDEVICEFAILURE = 0x808b0000,
  BADSENSORFAILURE = 0x808c0000,
  BADOUTOFSERVICE = 0x808d0000,
  BADDEADBANDFILTERINVALID = 0x808e0000,
  UNCERTAINNOCOMMUNICATIONLASTUSABLEVALUE = 0x408f0000,
  UNCERTAINLASTUSABLEVALUE = 0x40900000,
  UNCERTAINSUBSTITUTEVALUE = 0x40910000,
  UNCERTAININITIALVALUE = 0x40920000,
  UNCERTAINSENSORNOTACCURATE = 0x40930000,
  UNCERTAINENGINEERINGUNITSEXCEEDED = 0x40940000,
  UNCERTAINSUBNORMAL = 0x40950000,
  GOODLOCALOVERRIDE = 0x00960000,
  BADREFRESHINPROGRESS = 0x80970000,
  BADCONDITIONALREADYDISABLED = 0x80980000,
  BADCONDITIONALREADYENABLED = 0x80cc0000,
  BADCONDITIONDISABLED = 0x80990000,
  BADEVENTIDUNKNOWN = 0x809a0000,
  BADEVENTNOTACKNOWLEDGEABLE = 0x80bb0000,
  BADDIALOGNOTACTIVE = 0x80cd0000,
  BADDIALOGRESPONSEINVALID = 0x80ce0000,
  BADCONDITIONBRANCHALREADYACKED = 0x80cf0000,
  BADCONDITIONBRANCHALREADYCONFIRMED = 0x80d00000,
  BADCONDITIONALREADYSHELVED = 0x80d10000,
  BADCONDITIONNOTSHELVED = 0x80d20000,
  BADSHELVINGTIMEOUTOFRANGE = 0x80d30000,
  BADNODATA = 0x809b0000,
  BADBOUNDNOTFOUND = 0x80d70000,
  BADBOUNDNOTSUPPORTED = 0x80d80000,
  BADDATALOST = 0x809d0000,
  BADDATAUNAVAILABLE = 0x809e0000,
  BADENTRYEXISTS = 0x809f0000,
  BADNOENTRYEXISTS = 0x80a00000,
  BADTIMESTAMPNOTSUPPORTED = 0x80a10000,
  GOODENTRYINSERTED = 0x00a20000,
  GOODENTRYREPLACED = 0x00a30000,
  UNCERTAINDATASUBNORMAL = 0x40a40000,
  GOODNODATA = 0x00a50000,
  GOODMOREDATA = 0x00a60000,
  BADAGGREGATELISTMISMATCH = 0x80d40000,
  BADAGGREGATENOTSUPPORTED = 0x80d50000,
  BADAGGREGATEINVALIDINPUTS = 0x80d60000,
  BADAGGREGATECONFIGURATIONREJECTED = 0x80da0000,
  GOODDATAIGNORED = 0x00d90000,
  BADREQUESTNOTALLOWED = 0x80e40000,
  GOODEDITED = 0x00dc0000,
  GOODPOSTACTIONFAILED = 0x00dd0000,
  UNCERTAINDOMINANTVALUECHANGED = 0x40de0000,
  GOODDEPENDENTVALUECHANGED = 0x00e00000,
  BADDOMINANTVALUECHANGED = 0x80e10000,
  UNCERTAINDEPENDENTVALUECHANGED = 0x40e20000,
  BADDEPENDENTVALUECHANGED = 0x80e30000,
  GOODCOMMUNICATIONEVENT = 0x00a70000,
  GOODSHUTDOWNEVENT = 0x00a80000,
  GOODCALLAGAIN = 0x00a90000,
  GOODNONCRITICALTIMEOUT = 0x00aa0000,
  BADINVALIDARGUMENT = 0x80ab0000,
  BADCONNECTIONREJECTED = 0x80ac0000,
  BADDISCONNECT = 0x80ad0000,
  BADCONNECTIONCLOSED = 0x80ae0000,
  BADINVALIDSTATE = 0x80af0000,
  BADENDOFSTREAM = 0x80b00000,
  BADNODATAAVAILABLE = 0x80b10000,
  BADWAITINGFORRESPONSE = 0x80b20000,
  BADOPERATIONABANDONED = 0x80b30000,
  BADEXPECTEDSTREAMTOBLOCK = 0x80b40000,
  BADWOULDBLOCK = 0x80b50000,
  BADSYNTAXERROR = 0x80b60000,
  BADMAXCONNECTIONSREACHED = 0x80b70000,
  /* These StatusCodes are manually generated. */
  INFOTYPE_DATAVALUE = 0x00000400,
  INFOBITS_OVERFLOW = 0x00000080
};

inline std::ostream &operator<<(std::ostream &out, StatusCode const &op) {
  // TODO
}

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

enum class ExtensionObjectEncoding {
  Nobody = 0,
  ByteString = 1,
  Xml = 2,
  Decoded = 3,
  DecodedNodelete = 4
};

inline std::ostream &operator<<(std::ostream &out, ExtensionObjectEncoding op) {
  switch (op) {
    case ExtensionObjectEncoding::Nobody:
      out << "ExtensionObjectEncoding::Nobody";
      break;
    case ExtensionObjectEncoding::ByteString:
      out << "ExtensionObjectEncoding::ByteString";
      break;
    case ExtensionObjectEncoding::Xml:
      out << "ExtensionObjectEncoding::Xml";
      break;
    case ExtensionObjectEncoding::Decoded:
      out << "ExtensionObjectEncoding::Decoded";
      break;
    case ExtensionObjectEncoding::DecodedNodelete:
      out << "ExtensionObjectEncoding::DecodedNodelete";
      break;
  }
  return out;
}
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_ENUMS_H
