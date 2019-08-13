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

inline std::ostream &operator<<(std::ostream &out, UserTokenType op) {
  switch (op) {
    case UserTokenType::Anonymous:
      out << "UserTokenType::Anonymous";
      break;
    case UserTokenType::UserName:
      out << "UserTokenType::UserName";
      break;
    case UserTokenType::Certificate:
      out << "UserTokenType::Certificate";
      break;
    case UserTokenType::IssuedToken:
      out << "UserTokenType::IssuedToken";
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
  BadSecurityChecksFailed = 0x80130000,
  BadCertificateTimeInvalid = 0x80140000,
  BadCertificateIssuerTimeInvalid = 0x80150000,
  BadCertificateHostnameInvalid = 0x80160000,
  BadCertificateUriInvalid = 0x80170000,
  BadCertificateUseNotAllowed = 0x80180000,
  BadCertificateIssuerUseNotAllowed = 0x80190000,
  BadCertificateUntrusted = 0x801a0000,
  BadCertificateRevocationUnknown = 0x801b0000,
  BadCertificateIssuerRevocationUnknown = 0x801c0000,
  BadCertificateRevoked = 0x801d0000,
  BadCertificateIssuerRevoked = 0x801e0000,
  BadCertificateChainIncomplete = 0x810d0000,
  BadUserAccessDenied = 0x801f0000,
  BadIdentityTokenInvalid = 0x80200000,
  BadIdentityTokenRejected = 0x80210000,
  BadSecureChannelIdInvalid = 0x80220000,
  BadInvalidTimeStamp = 0x80230000,
  BadNonceInvalid = 0x80240000,
  BadSessionIdInvalid = 0x80250000,
  BadSessionClosed = 0x80260000,
  BadSessionNotActivated = 0x80270000,
  BadSubscriptionIdInvalid = 0x80280000,
  BadRequestHeaderInvalid = 0x802a0000,
  BadTimestampStoreTurnInvalid = 0x802b0000,
  BadRequestCancelledByClient = 0x802c0000,
  BadTooManyArguments = 0x80e50000,
  BadLicenseExpired = 0x810E0000,
  BadLicenseLimitsExceeded = 0x810F0000,
  BadLicenseNotAvailable = 0x81100000,
  GoodSubscriptionTransferred = 0x002d0000,
  GoodCompletesAsynchronously = 0x002e0000,
  GoodOverload = 0x002f0000,
  GoodClamped = 0x00300000,
  BadNoCommunication = 0x80310000,
  BadWaitingForInitialData = 0x80320000,
  BadNodeIdInvalid = 0x80330000,
  BadNodeIdUnknown = 0x80340000,
  BadAttributeIdInvalid = 0x80350000,
  BadIndexRangeInvalid = 0x80360000,
  BadIndexRangeNoData = 0x80370000,
  BadDataEncodingInvalid = 0x80380000,
  BadDataEncodingUnsupported = 0x80390000,
  BadNotReadable = 0x803a0000,
  BadNotWritable = 0x803b0000,
  BadOutofRange = 0x803c0000,
  BadNotSupported = 0x803d0000,
  BadNotFound = 0x803e0000,
  BadObjectDeleted = 0x803f0000,
  BadNotImplemented = 0x80400000,
  BadMonitoringModeInvalid = 0x80410000,
  BadMonitoredItemIdInvalid = 0x80420000,
  BadMonitoredItemFilterInvalid = 0x80430000,
  BadMonitoredItemFilterUnsupported = 0x80440000,
  BadFilterNotAllowed = 0x80450000,
  BadStructureMissing = 0x80460000,
  BadEventFilterInvalid = 0x80470000,
  BadContentFilterInvalid = 0x80480000,
  BadFilterOperatorInvalid = 0x80c10000,
  BadFilterOperatorUnsupported = 0x80c20000,
  BadFilterOperandCountMismatch = 0x80c30000,
  BadFilterOperandInvalid = 0x80490000,
  BadFilterElementInvalid = 0x80c40000,
  BadFilterLiteralInvalid = 0x80c50000,
  BadContinuationPointInvalid = 0x804a0000,
  BadNoContinuationPoints = 0x804b0000,
  BadReferenceTypeIdInvalid = 0x804c0000,
  BadBrowseDirectionInvalid = 0x804d0000,
  BadNodeNotInView = 0x804e0000,
  BadServerUriInvalid = 0x804f0000,
  BadSempahoreFileMissing = 0x80520000,
  BadRequestTypeInvalid = 0x80530000,
  BadSecurityModeRejected = 0x80540000,
  BadSecurityPolicyRejected = 0x80550000,
  BadTooManySessions = 0x80560000,
  BadUserSignatureInvalid = 0x80570000,
  BadApplicationSignatureInvalid = 0x80580000,
  BadNoValidCertificates = 0x80590000,
  BadIdentityChangeNotSupported = 0x80c60000,
  BadRequestCancelledByRequest = 0x805a0000,
  BadParentNodeIdInvalid = 0x805b0000,
  BadReferenceNotAllowed = 0x805c0000,
  BadNodeIdRejected = 0x805d0000,
  BadNodeIdExists = 0x805e0000,
  BadNodeClassInvalid = 0x805f0000,
  BadBrowsenameInvalid = 0x80600000,
  BadBrowsenameDuplicated = 0x80610000,
  BadNodeAttributesInvalid = 0x80620000,
  BadTypeDefinitionInvalid = 0x80630000,
  BadSourceNodeidInvalid = 0x80640000,
  BadTargetNodeidInvalid = 0x80650000,
  BadDuplicateReferenceNotAllowed = 0x80660000,
  BadInvalidSelfReference = 0x80670000,
  BadReferenceLocalOnly = 0x80680000,
  BadNoDeleteRights = 0x80690000,
  UncertainReferenceNotDeleted = 0x40bc0000,
  BadServerIndexInvalid = 0x806a0000,
  BadViewIdUnknown = 0x806b0000,
  BadViewTimestampInvalid = 0x80c90000,
  BadViewParameterMismatch = 0x80ca0000,
  BadViewVersionInvalid = 0x80cb0000,
  UncertainNotAllNodesAvailable = 0x40c00000,
  GoodResultsMaybeIncomplete = 0x00ba0000,
  BadNotTypeDefinition = 0x80c80000,
  UncertainReferenceOutOfServer = 0x406c0000,
  BadTooManyMatches = 0x806d0000,
  BadQueryTooComplex = 0x806e0000,
  BadNoMatch = 0x806f0000,
  BadMaxageInvalid = 0x80700000,
  BadSecurityModeInsufficient = 0x80e60000,
  BadHistoryOperationInvalid = 0x80710000,
  BadHistoryOperationUnsupported = 0x80720000,
  BadInvalidTimestampArgument = 0x80bd0000,
  BadWriteNotSupported = 0x80730000,
  BadTypeMismatch = 0x80740000,
  BadMethodInvalid = 0x80750000,
  BadArgumentsMissing = 0x80760000,
  BadTooManySubscriptions = 0x80770000,
  BadTooManyPublishrequests = 0x80780000,
  BadNoSubscription = 0x80790000,
  BadSequenceNumberUnknown = 0x807a0000,
  BadMessageNotAvailable = 0x807b0000,
  BadInsufficientClientProfile = 0x807c0000,
  BadStateNotActive = 0x80bf0000,
  BadTcpServerTooBusy = 0x807d0000,
  BadTcpMessageTypeInvalid = 0x807e0000,
  BadTcpSecureChannelUnknown = 0x807f0000,
  BadTcpMessageTooLarge = 0x80800000,
  BadTcpNotEnoughResources = 0x80810000,
  BadTcpInternalError = 0x80820000,
  BadTcpEndpointUrlInvalid = 0x80830000,
  BadRequestInterrupted = 0x80840000,
  BadRequestTimeout = 0x80850000,
  BadSecureChannelClosed = 0x80860000,
  BadSecureChannelTokenUnknown = 0x80870000,
  BadSequenceNumberInvalid = 0x80880000,
  BadProtocolVersionUnsupported = 0x80be0000,
  BadConfigurationError = 0x80890000,
  BadNotConnected = 0x808a0000,
  BadDeviceFailure = 0x808b0000,
  BadSensorFailure = 0x808c0000,
  BadOutOfService = 0x808d0000,
  BadDeadBandFilterInvalid = 0x808e0000,
  UncertainNoCommunicationLastUsableValue = 0x408f0000,
  UncertainLastUsableValue = 0x40900000,
  UncertainSubstituteValue = 0x40910000,
  UncertainInitialValue = 0x40920000,
  UncertainSensorNotAccurate = 0x40930000,
  UncertainEngineeringUnitsExceeded = 0x40940000,
  UncertainSubnormal = 0x40950000,
  GoodLocalOverride = 0x00960000,
  BadRefreshinProgress = 0x80970000,
  BadConditionalReadyDisabled = 0x80980000,
  BadConditionalReadyEnabled = 0x80cc0000,
  BadConditionDisabled = 0x80990000,
  BadEventIdUnknown = 0x809a0000,
  BadEventNotAcknowledgeable = 0x80bb0000,
  BadDialogNotActive = 0x80cd0000,
  BadDialogResponseInvalid = 0x80ce0000,
  BadConditionBranchAlReadyAcked = 0x80cf0000,
  BadConditionBranchAlReadyConfirmed = 0x80d00000,
  BadConditionalReadyshelved = 0x80d10000,
  BadConditionNotShelved = 0x80d20000,
  BadShelvingTimeOutOfRange = 0x80d30000,
  BadNoData = 0x809b0000,
  BadBoundNotFound = 0x80d70000,
  BadBoundNotSupported = 0x80d80000,
  BadDataLost = 0x809d0000,
  BadDataUnavailable = 0x809e0000,
  BadEntryExists = 0x809f0000,
  BadNoentryExists = 0x80a00000,
  BadTimestampNotSupported = 0x80a10000,
  GoodEntryInserted = 0x00a20000,
  GoodEntryReplaced = 0x00a30000,
  UncertainDataSubnormal = 0x40a40000,
  GoodNoData = 0x00a50000,
  GoodMoreData = 0x00a60000,
  BadAggregateListMismatch = 0x80d40000,
  BadAggregateNotSupported = 0x80d50000,
  BadAggregateInvalidInputs = 0x80d60000,
  BadAggregateConfigurationRejected = 0x80da0000,
  GoodDataIgnored = 0x00d90000,
  BadRequestNotAllowed = 0x80e40000,
  GoodEdited = 0x00dc0000,
  GoodPostActionFailed = 0x00dd0000,
  UncertainDominantValueChanged = 0x40de0000,
  GoodDependentValueChanged = 0x00e00000,
  BadDominantValueChanged = 0x80e10000,
  UncertainDependentValueChanged = 0x40e20000,
  BadDependentValueChanged = 0x80e30000,
  GoodCommunicationEvent = 0x00a70000,
  GoodShutdownEvent = 0x00a80000,
  GoodCallAgain = 0x00a90000,
  GoodNonCriticalTimeout = 0x00aa0000,
  BadInvalidArgument = 0x80ab0000,
  BadConnectionRejected = 0x80ac0000,
  BadDisconnect = 0x80ad0000,
  BadConnectionClosed = 0x80ae0000,
  BadInvalidState = 0x80af0000,
  BadEndofStream = 0x80b00000,
  BadNoDataAvailable = 0x80b10000,
  BadWaitingForResponse = 0x80b20000,
  BadOperationAbandoned = 0x80b30000,
  BadExpectedStreamToBlock = 0x80b40000,
  BadWouldBlock = 0x80b50000,
  BadSyntaxError = 0x80b60000,
  BadMaxConnectionsReached = 0x80b70000,
};

inline std::ostream &operator<<(std::ostream &out, StatusCode op) {
  switch (op) {
    case StatusCode::Good:
      out << "StatusCode::Good";
      break;
    case StatusCode::BadUnexpectedError:
      out << "StatusCode::BadUnexpectedError";
      break;
    case StatusCode::BadInternalError:
      out << "StatusCode::BadInternalError";
      break;
    case StatusCode::BadOutOfMemory:
      out << "StatusCode::BadOutOfMemory";
      break;
    case StatusCode::BadResourceUnavailable:
      out << "StatusCode::BadResourceUnavailable";
      break;
    case StatusCode::BadCommunicationError:
      out << "StatusCode::BadCommunicationError";
      break;
    case StatusCode::BadEncodingError:
      out << "StatusCode::BadEncodingError";
      break;
    case StatusCode::BadDecodingError:
      out << "StatusCode::BadDecodingError";
      break;
    case StatusCode::BadEncodingLimitsExceeded:
      out << "StatusCode::BadEncodingLimitsExceeded";
      break;
    case StatusCode::BadRequestTooLarge:
      out << "StatusCode::BadRequestTooLarge";
      break;
    case StatusCode::BadResponseTooLarge:
      out << "StatusCode::BadResponseTooLarge";
      break;
    case StatusCode::BadUnknownResponse:
      out << "StatusCode::BadUnknownResponse";
      break;
    case StatusCode::BadTimeout:
      out << "StatusCode::BadTimeout";
      break;
    case StatusCode::BadServiceUnsupported:
      out << "StatusCode::BadServiceUnsupported";
      break;
    case StatusCode::BadShutdown:
      out << "StatusCode::BadShutdown";
      break;
    case StatusCode::BadServerNotConnected:
      out << "StatusCode::BadServerNotConnected";
      break;
    case StatusCode::BadServerHalted:
      out << "StatusCode::BadServerHalted";
      break;
    case StatusCode::BadNothingToDo:
      out << "StatusCode::BadNothingToDo";
      break;
    case StatusCode::BadTooManyOperations:
      out << "StatusCode::BadTooManyOperations";
      break;
    case StatusCode::BadTooManyMonitoredItems:
      out << "StatusCode::BadTooManyMonitoredItems";
      break;
    case StatusCode::BadDataTypeIdUnknown:
      out << "StatusCode::BadDataTypeIdUnknown";
      break;
    case StatusCode::BadCertificateInvalid:
      out << "StatusCode::BadCertificateInvalid";
      break;
    case StatusCode::BadSecurityChecksFailed:
      out << "StatusCode::BadSecurityChecksFailed";
      break;
    case StatusCode::BadCertificateTimeInvalid:
      out << "StatusCode::BadCertificateTimeInvalid";
      break;
    case StatusCode::BadCertificateIssuerTimeInvalid:
      out << "StatusCode::BadCertificateIssuerTimeInvalid";
      break;
    case StatusCode::BadCertificateHostnameInvalid:
      out << "StatusCode::BadCertificateHostnameInvalid";
      break;
    case StatusCode::BadCertificateUriInvalid:
      out << "StatusCode::BadCertificateUriInvalid";
      break;
    case StatusCode::BadCertificateUseNotAllowed:
      out << "StatusCode::BadCertificateUseNotAllowed";
      break;
    case StatusCode::BadCertificateIssuerUseNotAllowed:
      out << "StatusCode::BadCertificateIssuerUseNotAllowed";
      break;
    case StatusCode::BadCertificateUntrusted:
      out << "StatusCode::BadCertificateUntrusted";
      break;
    case StatusCode::BadCertificateRevocationUnknown:
      out << "StatusCode::BadCertificateRevocationUnknown";
      break;
    case StatusCode::BadCertificateIssuerRevocationUnknown:
      out << "StatusCode::BadCertificateIssuerRevocationUnknown";
      break;
    case StatusCode::BadCertificateRevoked:
      out << "StatusCode::BadCertificateRevoked";
      break;
    case StatusCode::BadCertificateIssuerRevoked:
      out << "StatusCode::BadCertificateIssuerRevoked";
      break;
    case StatusCode::BadCertificateChainIncomplete:
      out << "StatusCode::BadCertificateChainIncomplete";
      break;
    case StatusCode::BadUserAccessDenied:
      out << "StatusCode::BadUserAccessDenied";
      break;
    case StatusCode::BadIdentityTokenInvalid:
      out << "StatusCode::BadIdentityTokenInvalid";
      break;
    case StatusCode::BadIdentityTokenRejected:
      out << "StatusCode::BadIdentityTokenRejected";
      break;
    case StatusCode::BadSecureChannelIdInvalid:
      out << "StatusCode::BadSecureChannelIdInvalid";
      break;
    case StatusCode::BadInvalidTimeStamp:
      out << "StatusCode::BadInvalidTimeStamp";
      break;
    case StatusCode::BadNonceInvalid:
      out << "StatusCode::BadNonceInvalid";
      break;
    case StatusCode::BadSessionIdInvalid:
      out << "StatusCode::BadSessionIdInvalid";
      break;
    case StatusCode::BadSessionClosed:
      out << "StatusCode::BadSessionClosed";
      break;
    case StatusCode::BadSessionNotActivated:
      out << "StatusCode::BadSessionNotActivated";
      break;
    case StatusCode::BadSubscriptionIdInvalid:
      out << "StatusCode::BadSubscriptionIdInvalid";
      break;
    case StatusCode::BadRequestHeaderInvalid:
      out << "StatusCode::BadRequestHeaderInvalid";
      break;
    case StatusCode::BadTimestampStoreTurnInvalid:
      out << "StatusCode::BadTimestampStoreTurnInvalid";
      break;
    case StatusCode::BadRequestCancelledByClient:
      out << "StatusCode::BadRequestCancelledByClient";
      break;
    case StatusCode::BadTooManyArguments:
      out << "StatusCode::BadTooManyArguments";
      break;
    case StatusCode::BadLicenseExpired:
      out << "StatusCode::BadLicenseExpired";
      break;
    case StatusCode::BadLicenseLimitsExceeded:
      out << "StatusCode::BadLicenseLimitsExceeded";
      break;
    case StatusCode::BadLicenseNotAvailable:
      out << "StatusCode::BadLicenseNotAvailable";
      break;
    case StatusCode::GoodSubscriptionTransferred:
      out << "StatusCode::GoodSubscriptionTransferred";
      break;
    case StatusCode::GoodCompletesAsynchronously:
      out << "StatusCode::GoodCompletesAsynchronously";
      break;
    case StatusCode::GoodOverload:
      out << "StatusCode::GoodOverload";
      break;
    case StatusCode::GoodClamped:
      out << "StatusCode::GoodClamped";
      break;
    case StatusCode::BadNoCommunication:
      out << "StatusCode::BadNoCommunication";
      break;
    case StatusCode::BadWaitingForInitialData:
      out << "StatusCode::BadWaitingForInitialData";
      break;
    case StatusCode::BadNodeIdInvalid:
      out << "StatusCode::BadNodeIdInvalid";
      break;
    case StatusCode::BadNodeIdUnknown:
      out << "StatusCode::BadNodeIdUnknown";
      break;
    case StatusCode::BadAttributeIdInvalid:
      out << "StatusCode::BadAttributeIdInvalid";
      break;
    case StatusCode::BadIndexRangeInvalid:
      out << "StatusCode::BadIndexRangeInvalid";
      break;
    case StatusCode::BadIndexRangeNoData:
      out << "StatusCode::BadIndexRangeNoData";
      break;
    case StatusCode::BadDataEncodingInvalid:
      out << "StatusCode::BadDataEncodingInvalid";
      break;
    case StatusCode::BadDataEncodingUnsupported:
      out << "StatusCode::BadDataEncodingUnsupported";
      break;
    case StatusCode::BadNotReadable:
      out << "StatusCode::BadNotReadable";
      break;
    case StatusCode::BadNotWritable:
      out << "StatusCode::BadNotWritable";
      break;
    case StatusCode::BadOutofRange:
      out << "StatusCode::BadOutofRange";
      break;
    case StatusCode::BadNotSupported:
      out << "StatusCode::BadNotSupported";
      break;
    case StatusCode::BadNotFound:
      out << "StatusCode::BadNotFound";
      break;
    case StatusCode::BadObjectDeleted:
      out << "StatusCode::BadObjectDeleted";
      break;
    case StatusCode::BadNotImplemented:
      out << "StatusCode::BadNotImplemented";
      break;
    case StatusCode::BadMonitoringModeInvalid:
      out << "StatusCode::BadMonitoringModeInvalid";
      break;
    case StatusCode::BadMonitoredItemIdInvalid:
      out << "StatusCode::BadMonitoredItemIdInvalid";
      break;
    case StatusCode::BadMonitoredItemFilterInvalid:
      out << "StatusCode::BadMonitoredItemFilterInvalid";
      break;
    case StatusCode::BadMonitoredItemFilterUnsupported:
      out << "StatusCode::BadMonitoredItemFilterUnsupported";
      break;
    case StatusCode::BadFilterNotAllowed:
      out << "StatusCode::BadFilterNotAllowed";
      break;
    case StatusCode::BadStructureMissing:
      out << "StatusCode::BadStructureMissing";
      break;
    case StatusCode::BadEventFilterInvalid:
      out << "StatusCode::BadEventFilterInvalid";
      break;
    case StatusCode::BadContentFilterInvalid:
      out << "StatusCode::BadContentFilterInvalid";
      break;
    case StatusCode::BadFilterOperatorInvalid:
      out << "StatusCode::BadFilterOperatorInvalid";
      break;
    case StatusCode::BadFilterOperatorUnsupported:
      out << "StatusCode::BadFilterOperatorUnsupported";
      break;
    case StatusCode::BadFilterOperandCountMismatch:
      out << "StatusCode::BadFilterOperandCountMismatch";
      break;
    case StatusCode::BadFilterOperandInvalid:
      out << "StatusCode::BadFilterOperandInvalid";
      break;
    case StatusCode::BadFilterElementInvalid:
      out << "StatusCode::BadFilterElementInvalid";
      break;
    case StatusCode::BadFilterLiteralInvalid:
      out << "StatusCode::BadFilterLiteralInvalid";
      break;
    case StatusCode::BadContinuationPointInvalid:
      out << "StatusCode::BadContinuationPointInvalid";
      break;
    case StatusCode::BadNoContinuationPoints:
      out << "StatusCode::BadNoContinuationPoints";
      break;
    case StatusCode::BadReferenceTypeIdInvalid:
      out << "StatusCode::BadReferenceTypeIdInvalid";
      break;
    case StatusCode::BadBrowseDirectionInvalid:
      out << "StatusCode::BadBrowseDirectionInvalid";
      break;
    case StatusCode::BadNodeNotInView:
      out << "StatusCode::BadNodeNotInView";
      break;
    case StatusCode::BadServerUriInvalid:
      out << "StatusCode::BadServerUriInvalid";
      break;
    case StatusCode::BadSempahoreFileMissing:
      out << "StatusCode::BadSempahoreFileMissing";
      break;
    case StatusCode::BadRequestTypeInvalid:
      out << "StatusCode::BadRequestTypeInvalid";
      break;
    case StatusCode::BadSecurityModeRejected:
      out << "StatusCode::BadSecurityModeRejected";
      break;
    case StatusCode::BadSecurityPolicyRejected:
      out << "StatusCode::BadSecurityPolicyRejected";
      break;
    case StatusCode::BadTooManySessions:
      out << "StatusCode::BadTooManySessions";
      break;
    case StatusCode::BadUserSignatureInvalid:
      out << "StatusCode::BadUserSignatureInvalid";
      break;
    case StatusCode::BadApplicationSignatureInvalid:
      out << "StatusCode::BadApplicationSignatureInvalid";
      break;
    case StatusCode::BadNoValidCertificates:
      out << "StatusCode::BadNoValidCertificates";
      break;
    case StatusCode::BadIdentityChangeNotSupported:
      out << "StatusCode::BadIdentityChangeNotSupported";
      break;
    case StatusCode::BadRequestCancelledByRequest:
      out << "StatusCode::BadRequestCancelledByRequest";
      break;
    case StatusCode::BadParentNodeIdInvalid:
      out << "StatusCode::BadParentNodeIdInvalid";
      break;
    case StatusCode::BadReferenceNotAllowed:
      out << "StatusCode::BadReferenceNotAllowed";
      break;
    case StatusCode::BadNodeIdRejected:
      out << "StatusCode::BadNodeIdRejected";
      break;
    case StatusCode::BadNodeIdExists:
      out << "StatusCode::BadNodeIdExists";
      break;
    case StatusCode::BadNodeClassInvalid:
      out << "StatusCode::BadNodeClassInvalid";
      break;
    case StatusCode::BadBrowsenameInvalid:
      out << "StatusCode::BadBrowsenameInvalid";
      break;
    case StatusCode::BadBrowsenameDuplicated:
      out << "StatusCode::BadBrowsenameDuplicated";
      break;
    case StatusCode::BadNodeAttributesInvalid:
      out << "StatusCode::BadNodeAttributesInvalid";
      break;
    case StatusCode::BadTypeDefinitionInvalid:
      out << "StatusCode::BadTypeDefinitionInvalid";
      break;
    case StatusCode::BadSourceNodeidInvalid:
      out << "StatusCode::BadSourceNodeidInvalid";
      break;
    case StatusCode::BadTargetNodeidInvalid:
      out << "StatusCode::BadTargetNodeidInvalid";
      break;
    case StatusCode::BadDuplicateReferenceNotAllowed:
      out << "StatusCode::BadDuplicateReferenceNotAllowed";
      break;
    case StatusCode::BadInvalidSelfReference:
      out << "StatusCode::BadInvalidSelfReference";
      break;
    case StatusCode::BadReferenceLocalOnly:
      out << "StatusCode::BadReferenceLocalOnly";
      break;
    case StatusCode::BadNoDeleteRights:
      out << "StatusCode::BadNoDeleteRights";
      break;
    case StatusCode::UncertainReferenceNotDeleted:
      out << "StatusCode::UncertainReferenceNotDeleted";
      break;
    case StatusCode::BadServerIndexInvalid:
      out << "StatusCode::BadServerIndexInvalid";
      break;
    case StatusCode::BadViewIdUnknown:
      out << "StatusCode::BadViewIdUnknown";
      break;
    case StatusCode::BadViewTimestampInvalid:
      out << "StatusCode::BadViewTimestampInvalid";
      break;
    case StatusCode::BadViewParameterMismatch:
      out << "StatusCode::BadViewParameterMismatch";
      break;
    case StatusCode::BadViewVersionInvalid:
      out << "StatusCode::BadViewVersionInvalid";
      break;
    case StatusCode::UncertainNotAllNodesAvailable:
      out << "StatusCode::UncertainNotAllNodesAvailable";
      break;
    case StatusCode::GoodResultsMaybeIncomplete:
      out << "StatusCode::GoodResultsMaybeIncomplete";
      break;
    case StatusCode::BadNotTypeDefinition:
      out << "StatusCode::BadNotTypeDefinition";
      break;
    case StatusCode::UncertainReferenceOutOfServer:
      out << "StatusCode::UncertainReferenceOutOfServer";
      break;
    case StatusCode::BadTooManyMatches:
      out << "StatusCode::BadTooManyMatches";
      break;
    case StatusCode::BadQueryTooComplex:
      out << "StatusCode::BadQueryTooComplex";
      break;
    case StatusCode::BadNoMatch:
      out << "StatusCode::BadNoMatch";
      break;
    case StatusCode::BadMaxageInvalid:
      out << "StatusCode::BadMaxageInvalid";
      break;
    case StatusCode::BadSecurityModeInsufficient:
      out << "StatusCode::BadSecurityModeInsufficient";
      break;
    case StatusCode::BadHistoryOperationInvalid:
      out << "StatusCode::BadHistoryOperationInvalid";
      break;
    case StatusCode::BadHistoryOperationUnsupported:
      out << "StatusCode::BadHistoryOperationUnsupported";
      break;
    case StatusCode::BadInvalidTimestampArgument:
      out << "StatusCode::BadInvalidTimestampArgument";
      break;
    case StatusCode::BadWriteNotSupported:
      out << "StatusCode::BadWriteNotSupported";
      break;
    case StatusCode::BadTypeMismatch:
      out << "StatusCode::BadTypeMismatch";
      break;
    case StatusCode::BadMethodInvalid:
      out << "StatusCode::BadMethodInvalid";
      break;
    case StatusCode::BadArgumentsMissing:
      out << "StatusCode::BadArgumentsMissing";
      break;
    case StatusCode::BadTooManySubscriptions:
      out << "StatusCode::BadTooManySubscriptions";
      break;
    case StatusCode::BadTooManyPublishrequests:
      out << "StatusCode::BadTooManyPublishrequests";
      break;
    case StatusCode::BadNoSubscription:
      out << "StatusCode::BadNoSubscription";
      break;
    case StatusCode::BadSequenceNumberUnknown:
      out << "StatusCode::BadSequenceNumberUnknown";
      break;
    case StatusCode::BadMessageNotAvailable:
      out << "StatusCode::BadMessageNotAvailable";
      break;
    case StatusCode::BadInsufficientClientProfile:
      out << "StatusCode::BadInsufficientClientProfile";
      break;
    case StatusCode::BadStateNotActive:
      out << "StatusCode::BadStateNotActive";
      break;
    case StatusCode::BadTcpServerTooBusy:
      out << "StatusCode::BadTcpServerTooBusy";
      break;
    case StatusCode::BadTcpMessageTypeInvalid:
      out << "StatusCode::BadTcpMessageTypeInvalid";
      break;
    case StatusCode::BadTcpSecureChannelUnknown:
      out << "StatusCode::BadTcpSecureChannelUnknown";
      break;
    case StatusCode::BadTcpMessageTooLarge:
      out << "StatusCode::BadTcpMessageTooLarge";
      break;
    case StatusCode::BadTcpNotEnoughResources:
      out << "StatusCode::BadTcpNotEnoughResources";
      break;
    case StatusCode::BadTcpInternalError:
      out << "StatusCode::BadTcpInternalError";
      break;
    case StatusCode::BadTcpEndpointUrlInvalid:
      out << "StatusCode::BadTcpEndpointUrlInvalid";
      break;
    case StatusCode::BadRequestInterrupted:
      out << "StatusCode::BadRequestInterrupted";
      break;
    case StatusCode::BadRequestTimeout:
      out << "StatusCode::BadRequestTimeout";
      break;
    case StatusCode::BadSecureChannelClosed:
      out << "StatusCode::BadSecureChannelClosed";
      break;
    case StatusCode::BadSecureChannelTokenUnknown:
      out << "StatusCode::BadSecureChannelTokenUnknown";
      break;
    case StatusCode::BadSequenceNumberInvalid:
      out << "StatusCode::BadSequenceNumberInvalid";
      break;
    case StatusCode::BadProtocolVersionUnsupported:
      out << "StatusCode::BadProtocolVersionUnsupported";
      break;
    case StatusCode::BadConfigurationError:
      out << "StatusCode::BadConfigurationError";
      break;
    case StatusCode::BadNotConnected:
      out << "StatusCode::BadNotConnected";
      break;
    case StatusCode::BadDeviceFailure:
      out << "StatusCode::BadDeviceFailure";
      break;
    case StatusCode::BadSensorFailure:
      out << "StatusCode::BadSensorFailure";
      break;
    case StatusCode::BadOutOfService:
      out << "StatusCode::BadOutOfService";
      break;
    case StatusCode::BadDeadBandFilterInvalid:
      out << "StatusCode::BadDeadBandFilterInvalid";
      break;
    case StatusCode::UncertainNoCommunicationLastUsableValue:
      out << "StatusCode::UncertainNoCommunicationLastUsableValue";
      break;
    case StatusCode::UncertainLastUsableValue:
      out << "StatusCode::UncertainLastUsableValue";
      break;
    case StatusCode::UncertainSubstituteValue:
      out << "StatusCode::UncertainSubstituteValue";
      break;
    case StatusCode::UncertainInitialValue:
      out << "StatusCode::UncertainInitialValue";
      break;
    case StatusCode::UncertainSensorNotAccurate:
      out << "StatusCode::UncertainSensorNotAccurate";
      break;
    case StatusCode::UncertainEngineeringUnitsExceeded:
      out << "StatusCode::UncertainEngineeringUnitsExceeded";
      break;
    case StatusCode::UncertainSubnormal:
      out << "StatusCode::UncertainSubnormal";
      break;
    case StatusCode::GoodLocalOverride:
      out << "StatusCode::GoodLocalOverride";
      break;
    case StatusCode::BadRefreshinProgress:
      out << "StatusCode::BadRefreshinProgress";
      break;
    case StatusCode::BadConditionalReadyDisabled:
      out << "StatusCode::BadConditionalReadyDisabled";
      break;
    case StatusCode::BadConditionalReadyEnabled:
      out << "StatusCode::BadConditionalReadyEnabled";
      break;
    case StatusCode::BadConditionDisabled:
      out << "StatusCode::BadConditionDisabled";
      break;
    case StatusCode::BadEventIdUnknown:
      out << "StatusCode::BadEventIdUnknown";
      break;
    case StatusCode::BadEventNotAcknowledgeable:
      out << "StatusCode::BadEventNotAcknowledgeable";
      break;
    case StatusCode::BadDialogNotActive:
      out << "StatusCode::BadDialogNotActive";
      break;
    case StatusCode::BadDialogResponseInvalid:
      out << "StatusCode::BadDialogResponseInvalid";
      break;
    case StatusCode::BadConditionBranchAlReadyAcked:
      out << "StatusCode::BadConditionBranchAlReadyAcked";
      break;
    case StatusCode::BadConditionBranchAlReadyConfirmed:
      out << "StatusCode::BadConditionBranchAlReadyConfirmed";
      break;
    case StatusCode::BadConditionalReadyshelved:
      out << "StatusCode::BadConditionalReadyshelved";
      break;
    case StatusCode::BadConditionNotShelved:
      out << "StatusCode::BadConditionNotShelved";
      break;
    case StatusCode::BadShelvingTimeOutOfRange:
      out << "StatusCode::BadShelvingTimeOutOfRange";
      break;
    case StatusCode::BadNoData:
      out << "StatusCode::BadNoData";
      break;
    case StatusCode::BadBoundNotFound:
      out << "StatusCode::BadBoundNotFound";
      break;
    case StatusCode::BadBoundNotSupported:
      out << "StatusCode::BadBoundNotSupported";
      break;
    case StatusCode::BadDataLost:
      out << "StatusCode::BadDataLost";
      break;
    case StatusCode::BadDataUnavailable:
      out << "StatusCode::BadDataUnavailable";
      break;
    case StatusCode::BadEntryExists:
      out << "StatusCode::BadEntryExists";
      break;
    case StatusCode::BadNoentryExists:
      out << "StatusCode::BadNoentryExists";
      break;
    case StatusCode::BadTimestampNotSupported:
      out << "StatusCode::BadTimestampNotSupported";
      break;
    case StatusCode::GoodEntryInserted:
      out << "StatusCode::GoodEntryInserted";
      break;
    case StatusCode::GoodEntryReplaced:
      out << "StatusCode::GoodEntryReplaced";
      break;
    case StatusCode::UncertainDataSubnormal:
      out << "StatusCode::UncertainDataSubnormal";
      break;
    case StatusCode::GoodNoData:
      out << "StatusCode::GoodNoData";
      break;
    case StatusCode::GoodMoreData:
      out << "StatusCode::GoodMoreData";
      break;
    case StatusCode::BadAggregateListMismatch:
      out << "StatusCode::BadAggregateListMismatch";
      break;
    case StatusCode::BadAggregateNotSupported:
      out << "StatusCode::BadAggregateNotSupported";
      break;
    case StatusCode::BadAggregateInvalidInputs:
      out << "StatusCode::BadAggregateInvalidInputs";
      break;
    case StatusCode::BadAggregateConfigurationRejected:
      out << "StatusCode::BadAggregateConfigurationRejected";
      break;
    case StatusCode::GoodDataIgnored:
      out << "StatusCode::GoodDataIgnored";
      break;
    case StatusCode::BadRequestNotAllowed:
      out << "StatusCode::BadRequestNotAllowed";
      break;
    case StatusCode::GoodEdited:
      out << "StatusCode::GoodEdited";
      break;
    case StatusCode::GoodPostActionFailed:
      out << "StatusCode::GoodPostActionFailed";
      break;
    case StatusCode::UncertainDominantValueChanged:
      out << "StatusCode::UncertainDominantValueChanged";
      break;
    case StatusCode::GoodDependentValueChanged:
      out << "StatusCode::GoodDependentValueChanged";
      break;
    case StatusCode::BadDominantValueChanged:
      out << "StatusCode::BadDominantValueChanged";
      break;
    case StatusCode::UncertainDependentValueChanged:
      out << "StatusCode::UncertainDependentValueChanged";
      break;
    case StatusCode::BadDependentValueChanged:
      out << "StatusCode::BadDependentValueChanged";
      break;
    case StatusCode::GoodCommunicationEvent:
      out << "StatusCode::GoodCommunicationEvent";
      break;
    case StatusCode::GoodShutdownEvent:
      out << "StatusCode::GoodShutdownEvent";
      break;
    case StatusCode::GoodCallAgain:
      out << "StatusCode::GoodCallAgain";
      break;
    case StatusCode::GoodNonCriticalTimeout:
      out << "StatusCode::GoodNonCriticalTimeout";
      break;
    case StatusCode::BadInvalidArgument:
      out << "StatusCode::BadInvalidArgument";
      break;
    case StatusCode::BadConnectionRejected:
      out << "StatusCode::BadConnectionRejected";
      break;
    case StatusCode::BadDisconnect:
      out << "StatusCode::BadDisconnect";
      break;
    case StatusCode::BadConnectionClosed:
      out << "StatusCode::BadConnectionClosed";
      break;
    case StatusCode::BadInvalidState:
      out << "StatusCode::BadInvalidState";
      break;
    case StatusCode::BadEndofStream:
      out << "StatusCode::BadEndofStream";
      break;
    case StatusCode::BadNoDataAvailable:
      out << "StatusCode::BadNoDataAvailable";
      break;
    case StatusCode::BadWaitingForResponse:
      out << "StatusCode::BadWaitingForResponse";
      break;
    case StatusCode::BadOperationAbandoned:
      out << "StatusCode::BadOperationAbandoned";
      break;
    case StatusCode::BadExpectedStreamToBlock:
      out << "StatusCode::BadExpectedStreamToBlock";
      break;
    case StatusCode::BadWouldBlock:
      out << "StatusCode::BadWouldBlock";
      break;
    case StatusCode::BadSyntaxError:
      out << "StatusCode::BadSyntaxError";
      break;
    case StatusCode::BadMaxConnectionsReached:
      out << "StatusCode::BadMaxConnectionsReached";
      break;
  }
  return out;
}

enum class IdentifierType : uint32_t { Numeric, String, Guid, ByteString };

inline std::ostream &operator<<(std::ostream &out, IdentifierType op) {
  switch (op) {
    case IdentifierType::Numeric:
      out << "IdentifierType::Numeric";
      break;
    case IdentifierType::String:
      out << "IdentifierType::String";
      break;
    case IdentifierType::Guid:
      out << "IdentifierType::Guid";
      break;
    case IdentifierType::ByteString:
      out << "IdentifierType::ByteString";
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

inline std::ostream &operator<<(std::ostream &out, MessageSecurityMode op) {
  switch (op) {
    case MessageSecurityMode::Invalid:
      out << "MessageSecurityMode::Invalid";
      break;
    case MessageSecurityMode::None:
      out << "MessageSecurityMode::None";
      break;
    case MessageSecurityMode::Sign:
      out << "MessageSecurityMode::Sign";
      break;
    case MessageSecurityMode::SignAndEncrypt:
      out << "MessageSecurityMode::SignAndEncrypt";
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

inline std::ostream &operator<<(std::ostream &out, ApplicationType op) {
  switch (op) {
    case ApplicationType::Server:
      out << "ApplicationType::Server";
      break;
    case ApplicationType::Client:
      out << "ApplicationType::Client";
      break;
    case ApplicationType::ClientAndServer:
      out << "ApplicationType::ClientAndServer";
      break;
    case ApplicationType::DiscoveryServer:
      out << "ApplicationType::DiscoveryServer";
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

inline std::ostream &operator<<(std::ostream &out, BrowseDirection op) {
  switch (op) {
    case BrowseDirection::Forward:
      out << "BrowseDirection::Forward";
      break;
    case BrowseDirection::Inverse:
      out << "BrowseDirection::Inverse";
      break;
    case BrowseDirection::Both:
      out << "BrowseDirection::Both";
      break;
    case BrowseDirection::Invalid:
      out << "BrowseDirection::Invalid";
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

inline std::ostream &operator<<(std::ostream &out, BrowseResultMask op) {
  switch (op) {
    case BrowseResultMask::None:
      out << "BrowseResultMask::None";
      break;
    case BrowseResultMask::ReferenceTypeId:
      out << "BrowseResultMask::ReferenceTypeId";
      break;
    case BrowseResultMask::IsForward:
      out << "BrowseResultMask::IsForward";
      break;
    case BrowseResultMask::NodeClass:
      out << "BrowseResultMask::NodeClass";
      break;
    case BrowseResultMask::QualifiedName:
      out << "BrowseResultMask::QualifiedName";
      break;
    case BrowseResultMask::LocalizedText:
      out << "BrowseResultMask::LocalizedText";
      break;
    case BrowseResultMask::TypeDefinition:
      out << "BrowseResultMask::TypeDefinition";
      break;
    case BrowseResultMask::All:
      out << "BrowseResultMask::All";
      break;
    case BrowseResultMask::ReferencetypeInfo:
      out << "BrowseResultMask::ReferencetypeInfo";
      break;
    case BrowseResultMask::TargetInfo:
      out << "BrowseResultMask::TargetInfo";
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
                                ReferenceTypeIdentifier op) {
  switch (op) {
    case ReferenceTypeIdentifier::Unspecified:
      out << "ReferenceTypeIdentifier::Unspecified";
      break;
    case ReferenceTypeIdentifier::References:
      out << "ReferenceTypeIdentifier::References";
      break;
    case ReferenceTypeIdentifier::NonHierarchicalReferences:
      out << "ReferenceTypeIdentifier::NonHierarchicalReferences";
      break;
    case ReferenceTypeIdentifier::HierarchicalReferences:
      out << "ReferenceTypeIdentifier::HierarchicalReferences";
      break;
    case ReferenceTypeIdentifier::HasChild:
      out << "ReferenceTypeIdentifier::HasChild";
      break;
    case ReferenceTypeIdentifier::Organizes:
      out << "ReferenceTypeIdentifier::Organizes";
      break;
    case ReferenceTypeIdentifier::HasEventSource:
      out << "ReferenceTypeIdentifier::HasEventSource";
      break;
    case ReferenceTypeIdentifier::HasModellingRule:
      out << "ReferenceTypeIdentifier::HasModellingRule";
      break;
    case ReferenceTypeIdentifier::HasEncoding:
      out << "ReferenceTypeIdentifier::HasEncoding";
      break;
    case ReferenceTypeIdentifier::HasDescription:
      out << "ReferenceTypeIdentifier::HasDescription";
      break;
    case ReferenceTypeIdentifier::HasTypeDefinition:
      out << "ReferenceTypeIdentifier::HasTypeDefinition";
      break;
    case ReferenceTypeIdentifier::GeneratesEvent:
      out << "ReferenceTypeIdentifier::GeneratesEvent";
      break;
    case ReferenceTypeIdentifier::Aggregates:
      out << "ReferenceTypeIdentifier::Aggregates";
      break;
    case ReferenceTypeIdentifier::HasSubtype:
      out << "ReferenceTypeIdentifier::HasSubtype";
      break;
    case ReferenceTypeIdentifier::HasProperty:
      out << "ReferenceTypeIdentifier::HasProperty";
      break;
    case ReferenceTypeIdentifier::HasComponent:
      out << "ReferenceTypeIdentifier::HasComponent";
      break;
    case ReferenceTypeIdentifier::HasNotifier:
      out << "ReferenceTypeIdentifier::HasNotifier";
      break;
    case ReferenceTypeIdentifier::HasOrderedComponent:
      out << "ReferenceTypeIdentifier::HasOrderedComponent";
      break;
    case ReferenceTypeIdentifier::FromState:
      out << "ReferenceTypeIdentifier::FromState";
      break;
    case ReferenceTypeIdentifier::ToState:
      out << "ReferenceTypeIdentifier::ToState";
      break;
    case ReferenceTypeIdentifier::HasCause:
      out << "ReferenceTypeIdentifier::HasCause";
      break;
    case ReferenceTypeIdentifier::HasEffect:
      out << "ReferenceTypeIdentifier::HasEffect";
      break;
    case ReferenceTypeIdentifier::HasHistoricalConfiguration:
      out << "ReferenceTypeIdentifier::HasHistoricalConfiguration";
      break;
    case ReferenceTypeIdentifier::HasSubStateMachine:
      out << "ReferenceTypeIdentifier::HasSubStateMachine";
      break;
    case ReferenceTypeIdentifier::AlwaysGeneratesEvent:
      out << "ReferenceTypeIdentifier::AlwaysGeneratesEvent";
      break;
    case ReferenceTypeIdentifier::HasTrueSubState:
      out << "ReferenceTypeIdentifier::HasTrueSubState";
      break;
    case ReferenceTypeIdentifier::HasFalseSubState:
      out << "ReferenceTypeIdentifier::HasFalseSubState";
      break;
    case ReferenceTypeIdentifier::HasCondition:
      out << "ReferenceTypeIdentifier::HasCondition";
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

inline std::ostream &operator<<(std::ostream &out, NodeClass op) {
  switch (op) {
    case NodeClass::Unspecified:
      out << "NodeClass::Unspecified";
      break;
    case NodeClass::Object:
      out << "NodeClass::Object";
      break;
    case NodeClass::Variable:
      out << "NodeClass::Variable";
      break;
    case NodeClass::Method:
      out << "NodeClass::Method";
      break;
    case NodeClass::ObjectType:
      out << "NodeClass::ObjectType";
      break;
    case NodeClass::VariableType:
      out << "NodeClass::VariableType";
      break;
    case NodeClass::ReferenceType:
      out << "NodeClass::ReferenceType";
      break;
    case NodeClass::DataType:
      out << "NodeClass::DataType";
      break;
    case NodeClass::View:
      out << "NodeClass::View";
      break;
    case NodeClass::All:
      out << "NodeClass::All";
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

inline std::ostream &operator<<(std::ostream &out, ClientState op) {
  switch (op) {
    case ClientState::Disconnected:
      out << "ClientState::Disconnected";
      break;
    case ClientState::Connected:
      out << "ClientState::Connected";
      break;
    case ClientState::SecureChannel:
      out << "ClientState::SecureChannel";
      break;
    case ClientState::Session:
      out << "ClientState::Session";
      break;
    case ClientState::SessionRenewed:
      out << "ClientState::SessionRenewed";
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
