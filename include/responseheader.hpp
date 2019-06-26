#ifndef OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H
#define OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H

// STL
#include <memory>
#include <string>
#include <vector>

#include "datetime.hpp"
#include "diagnosticinfo.hpp"
#include "enums.hpp"
#include "extensionobject.hpp"

namespace open62541 {

class ResponseHeader {
  DateTime timestamp;
  uint32_t requestHandle;
  StatusCode serviceResult;
  DiagnosticInfo serviceDiagnostics;
  std::vector<std::string> stringTable;
  ExtensionObject additionalHeader;

 public:
  bool operator==(ResponseHeader const &rhs) const { return true; }
  bool operator!=(ResponseHeader const &rhs) const { return false; }
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H
