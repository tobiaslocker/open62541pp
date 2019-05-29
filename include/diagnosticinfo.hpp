#ifndef OPEN6541_CPP_WRAPPER_DIAGNOSTIC_INFO_H
#define OPEN6541_CPP_WRAPPER_DIAGNOSTIC_INFO_H

namespace open62541 {

class DiagnosticInfo {

public:
  bool operator==(DiagnosticInfo const &rhs) const {return true;}
  bool operator!=(DiagnosticInfo const &rhs) const {return false;}
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_DIAGNOSTIC_INFO_H
