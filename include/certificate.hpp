#ifndef OPEN62541_CPP_WRAPPER_CERTIFICATE_H
#define OPEN62541_CPP_WRAPPER_CERTIFICATE_H

#include "open62541.h"

// STL
#include <string>

namespace open62541 {

class Certificate {
  std::string m_certificate;

 public:
  Certificate() {}
  Certificate(UA_ByteString const &certificate);
  std::string to_string() const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_CERTIFICATE_H
