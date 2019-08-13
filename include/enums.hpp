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
  Good = 0x00,
  BadUnexpectedError = 0x80010000,
  BadInternalError = 0x80020000,
  BadOutOfMemory = 0x80030000,
  BadResourceUnavailable = 0x80040000,
  BadCommunicationError = 0x80050000,
  BadEncodingError = 0x80060000,
  BadDecodingError = 0x80070000,
  BadEncodingLimitsExceeded = 0x80080000,
  BadRequestTooLarge = 0x80b80000,
  BadResponseTooLarge = 0x80b90000,
  BadUnknownResponse = 0x80090000,
  BadTimeout = 0x800a0000,
  BadServiceUnsupported = 0x800b0000,
  BadShutdown = 0x800c0000,
  BadServerNotConnected = 0x800d0000,
  BadServerHalted = 0x800e0000,
  BadNothingToDo = 0x800f0000,
  BadTooManyOperations = 0x80100000,
  BadTooManyMonitoredItems = 0x80db0000,
  BadDataTypeIdUnknown = 0x80110000,
  BadCertificateInvalid = 0x80120000,
  BadSecurityCHECKSFAILED = 0x80130000,
  BadCertificateTIMEInvalid = 0x80140000,
  BadCertificateISSUERTIMEInvalid = 0x80150000,
  BadCertificateHOSTNAMEInvalid = 0x80160000,
  BadCertificateURIInvalid = 0x80170000,
  BadCertificateUSENOTALLOWED = 0x80180000,
  BadCertificateISSUERUSENOTALLOWED = 0x80190000,
  BadCertificateUNTRUSTED = 0x801a0000,
  BadCertificateREVOCATIONUnknown = 0x801b0000,
  BadCertificateISSUERREVOCATIONUnknown = 0x801c0000,
  BadCertificateREVOKED = 0x801d0000,
  BadCertificateISSUERREVOKED = 0x801e0000,
  BadCertificateCHAININCOMPLETE = 0x810d0000,
  BadUSERACCESSDENIED = 0x801f0000,
  BadIDENTITYTOKENInvalid = 0x80200000,
  BadIDENTITYTOKENREJECTED = 0x80210000,
  BadSECURECHANNELIDInvalid = 0x80220000,
  BadInvalidTIMESTAMP = 0x80230000,
  BadNONCEInvalid = 0x80240000,
  BadSESSIONIDInvalid = 0x80250000,
  BadSESSIONCLOSED = 0x80260000,
  BadSESSIONNOTACTIVATED = 0x80270000,
  BadSUBSCRIPTIONIDInvalid = 0x80280000,
  BadREQUESTHEADERInvalid = 0x802a0000,
  BadTIMESTAMPSTORETURNInvalid = 0x802b0000,
  BadREQUESTCANCELLEDBYCLIENT = 0x802c0000,
  BadTooManyARGUMENTS = 0x80e50000,
  BadLICENSEEXPIRED = 0x810E0000,
  BadLICENSELIMITSEXCEEDED = 0x810F0000,
  BadLICENSENOTAVAILABLE = 0x81100000,
  GoodSUBSCRIPTIONTRANSFERRED = 0x002d0000,
  GoodCOMPLETESASYNCHRONOUSLY = 0x002e0000,
  GoodOVERLOAD = 0x002f0000,
  GoodCLAMPED = 0x00300000,
  BadNOCOMMUNICATION = 0x80310000,
  BadWAITINGFORINITIALDATA = 0x80320000,
  BadNodeIdInvalid = 0x80330000,
  BadNodeIdUnknown = 0x80340000,
  BadATTRIBUTEIDInvalid = 0x80350000,
  BadINDEXRANGEInvalid = 0x80360000,
  BadINDEXRANGENODATA = 0x80370000,
  BadDATAENCODINGInvalid = 0x80380000,
  BadDATAENCODINGUNSUPPORTED = 0x80390000,
  BadNOTREADABLE = 0x803a0000,
  BadNOTWRITABLE = 0x803b0000,
  BadOUTOFRANGE = 0x803c0000,
  BadNOTSUPPORTED = 0x803d0000,
  BadNOTFOUND = 0x803e0000,
  BadOBJECTDELETED = 0x803f0000,
  BadNOTIMPLEMENTED = 0x80400000,
  BadMONITORINGMODEInvalid = 0x80410000,
  BadMONITOREDITEMIDInvalid = 0x80420000,
  BadMONITOREDITEMFilterInvalid = 0x80430000,
  BadMONITOREDITEMFilterUNSUPPORTED = 0x80440000,
  BadFilterNOTALLOWED = 0x80450000,
  BadSTRUCTUREMISSING = 0x80460000,
  BadEVENTFilterInvalid = 0x80470000,
  BadCONTENTFilterInvalid = 0x80480000,
  BadFilterOPERATORInvalid = 0x80c10000,
  BadFilterOPERATORUNSUPPORTED = 0x80c20000,
  BadFilterOPERANDCOUNTMISMATCH = 0x80c30000,
  BadFilterOPERANDInvalid = 0x80490000,
  BadFilterELEMENTInvalid = 0x80c40000,
  BadFilterLITERALInvalid = 0x80c50000,
  BadCONTINUATIONPOINTInvalid = 0x804a0000,
  BadNOCONTINUATIONPOINTS = 0x804b0000,
  BadREFERENCETYPEIDInvalid = 0x804c0000,
  BadBROWSEDIRECTIONInvalid = 0x804d0000,
  BadNODENOTINVIEW = 0x804e0000,
  BadSERVERURIInvalid = 0x804f0000,
  BadSEMPAHOREFILEMISSING = 0x80520000,
  BadREQUESTTYPEInvalid = 0x80530000,
  BadSecurityMODEREJECTED = 0x80540000,
  BadSecurityPOLICYREJECTED = 0x80550000,
  BadTooManySESSIONS = 0x80560000,
  BadUSERSIGNATUREInvalid = 0x80570000,
  BadAPPLICATIONSIGNATUREInvalid = 0x80580000,
  BadNOVALIDCertificates = 0x80590000,
  BadIDENTITYCHANGENOTSUPPORTED = 0x80c60000,
  BadREQUESTCANCELLEDBYREQUEST = 0x805a0000,
  BadPARENTNodeIdInvalid = 0x805b0000,
  BadREFERENCENOTALLOWED = 0x805c0000,
  BadNodeIdREJECTED = 0x805d0000,
  BadNodeIdEXISTS = 0x805e0000,
  BadNODECLASSInvalid = 0x805f0000,
  BadBROWSENAMEInvalid = 0x80600000,
  BadBROWSENAMEDUPLICATED = 0x80610000,
  BadNODEATTRIBUTESInvalid = 0x80620000,
  BadTYPEDEFINITIONInvalid = 0x80630000,
  BadSOURCENodeIdInvalid = 0x80640000,
  BadTARGETNodeIdInvalid = 0x80650000,
  BadDUPLICATEREFERENCENOTALLOWED = 0x80660000,
  BadInvalidSELFREFERENCE = 0x80670000,
  BadREFERENCELOCALONLY = 0x80680000,
  BadNODELETERIGHTS = 0x80690000,
  UncertainREFERENCENOTDELETED = 0x40bc0000,
  BadSERVERINDEXInvalid = 0x806a0000,
  BadVIEWIDUnknown = 0x806b0000,
  BadVIEWTIMESTAMPInvalid = 0x80c90000,
  BadVIEWPARAMETERMISMATCH = 0x80ca0000,
  BadVIEWVERSIONInvalid = 0x80cb0000,
  UncertainNOTALLNODESAVAILABLE = 0x40c00000,
  GoodRESULTSMAYBEINCOMPLETE = 0x00ba0000,
  BadNOTTYPEDEFINITION = 0x80c80000,
  UncertainREFERENCEOUTOFSERVER = 0x406c0000,
  BadTooManyMATCHES = 0x806d0000,
  BadQUERYTOOCOMPLEX = 0x806e0000,
  BadNOMATCH = 0x806f0000,
  BadMAXAGEInvalid = 0x80700000,
  BadSecurityMODEINSUFFICIENT = 0x80e60000,
  BadHISTORYOPERATIONInvalid = 0x80710000,
  BadHISTORYOPERATIONUNSUPPORTED = 0x80720000,
  BadInvalidTIMESTAMPARGUMENT = 0x80bd0000,
  BadWRITENOTSUPPORTED = 0x80730000,
  BadTYPEMISMATCH = 0x80740000,
  BadMETHODInvalid = 0x80750000,
  BadARGUMENTSMISSING = 0x80760000,
  BadTooManySUBSCRIPTIONS = 0x80770000,
  BadTooManyPUBLISHREQUESTS = 0x80780000,
  BadNOSUBSCRIPTION = 0x80790000,
  BadSEQUENCENUMBERUnknown = 0x807a0000,
  BadMESSAGENOTAVAILABLE = 0x807b0000,
  BadINSUFFICIENTCLIENTPROFILE = 0x807c0000,
  BadSTATENOTACTIVE = 0x80bf0000,
  BadTCPSERVERTOOBUSY = 0x807d0000,
  BadTCPMESSAGETYPEInvalid = 0x807e0000,
  BadTCPSECURECHANNELUnknown = 0x807f0000,
  BadTCPMESSAGETOOLARGE = 0x80800000,
  BadTCPNOTENOUGHRESOURCES = 0x80810000,
  BadTCPINTERNALError = 0x80820000,
  BadTCPENDPOINTURLInvalid = 0x80830000,
  BadREQUESTINTERRUPTED = 0x80840000,
  BadREQUESTTIMEOUT = 0x80850000,
  BadSECURECHANNELCLOSED = 0x80860000,
  BadSECURECHANNELTOKENUnknown = 0x80870000,
  BadSEQUENCENUMBERInvalid = 0x80880000,
  BadPROTOCOLVERSIONUNSUPPORTED = 0x80be0000,
  BadCONFIGURATIONError = 0x80890000,
  BadNOTCONNECTED = 0x808a0000,
  BadDEVICEFAILURE = 0x808b0000,
  BadSENSORFAILURE = 0x808c0000,
  BadOUTOFSERVICE = 0x808d0000,
  BadDEADBANDFilterInvalid = 0x808e0000,
  UncertainNOCOMMUNICATIONLASTUSABLEVALUE = 0x408f0000,
  UncertainLASTUSABLEVALUE = 0x40900000,
  UncertainSUBSTITUTEVALUE = 0x40910000,
  UncertainINITIALVALUE = 0x40920000,
  UncertainSENSORNOTACCURATE = 0x40930000,
  UncertainENGINEERINGUNITSEXCEEDED = 0x40940000,
  UncertainSUBNORMAL = 0x40950000,
  GoodLOCALOVERRIDE = 0x00960000,
  BadREFRESHINPROGRESS = 0x80970000,
  BadCONDITIONALREADYDISABLED = 0x80980000,
  BadCONDITIONALREADYENABLED = 0x80cc0000,
  BadCONDITIONDISABLED = 0x80990000,
  BadEVENTIDUnknown = 0x809a0000,
  BadEVENTNOTACKNOWLEDGEABLE = 0x80bb0000,
  BadDIALOGNOTACTIVE = 0x80cd0000,
  BadDIALOGResponseInvalid = 0x80ce0000,
  BadConditionBranchAlreadyACKED = 0x80cf0000,
  BadConditionBranchAlreadyCONFIRMED = 0x80d00000,
  BadCONDITIONALREADYSHELVED = 0x80d10000,
  BadCONDITIONNOTSHELVED = 0x80d20000,
  BadSHELVINGTIMEOUTOFRANGE = 0x80d30000,
  BadNODATA = 0x809b0000,
  BadBOUNDNOTFOUND = 0x80d70000,
  BadBOUNDNOTSUPPORTED = 0x80d80000,
  BadDATALOST = 0x809d0000,
  BadDATAUNAVAILABLE = 0x809e0000,
  BadENTRYEXISTS = 0x809f0000,
  BadNOENTRYEXISTS = 0x80a00000,
  BadTIMESTAMPNOTSUPPORTED = 0x80a10000,
  GoodENTRYINSERTED = 0x00a20000,
  GoodENTRYREPLACED = 0x00a30000,
  UncertainDATASUBNORMAL = 0x40a40000,
  GoodNODATA = 0x00a50000,
  GoodMOREDATA = 0x00a60000,
  BadAggregateLISTMISMATCH = 0x80d40000,
  BadAggregateNOTSUPPORTED = 0x80d50000,
  BadAggregateInvalidINPUTS = 0x80d60000,
  BadAggregateCONFIGURATIONREJECTED = 0x80da0000,
  GoodDATAIGNORED = 0x00d90000,
  BadREQUESTNOTALLOWED = 0x80e40000,
  GoodEDITED = 0x00dc0000,
  GoodPOSTACTIONFAILED = 0x00dd0000,
  UncertainDOMINANTVALUECHANGED = 0x40de0000,
  GoodDEPENDENTVALUECHANGED = 0x00e00000,
  BadDOMINANTVALUECHANGED = 0x80e10000,
  UncertainDEPENDENTVALUECHANGED = 0x40e20000,
  BadDEPENDENTVALUECHANGED = 0x80e30000,
  GoodCOMMUNICATIONEVENT = 0x00a70000,
  GoodSHUTDOWNEVENT = 0x00a80000,
  GoodCALLAGAIN = 0x00a90000,
  GoodNONCRITICALTIMEOUT = 0x00aa0000,
  BadInvalidARGUMENT = 0x80ab0000,
  BadCONNECTIONREJECTED = 0x80ac0000,
  BadDISCONNECT = 0x80ad0000,
  BadCONNECTIONCLOSED = 0x80ae0000,
  BadInvalidSTATE = 0x80af0000,
  BadENDOFSTREAM = 0x80b00000,
  BadNODATAAVAILABLE = 0x80b10000,
  BadWAITINGFORResponse = 0x80b20000,
  BadOPERATIONABANDONED = 0x80b30000,
  BadEXPECTEDSTREAMTOBLOCK = 0x80b40000,
  BadWOULDBLOCK = 0x80b50000,
  BadSYNTAXError = 0x80b60000,
  BadMAXCONNECTIONSREACHED = 0x80b70000,
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
