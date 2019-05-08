#ifndef OPEN62541_CPP_WRAPPER_CERTIFICATE_H
#define OPEN62541_CPP_WRAPPER_CERTIFICATE_H

#include "open62541.h"

// STL
#include <string>
#include <vector>

namespace open62541 {

class Certificate {
  std::string m_certificate;
  std::vector<unsigned char> m_bytes;

 public:
  Certificate() {}
  Certificate(UA_ByteString const &certificate);
  std::string to_string() const;

  bool operator==(Certificate const &rhs);
  bool operator!=(Certificate const &rhs);
//  friend std::ostream &operator<<(
//      std::ostream &out, Certificate const &endpoint_description);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_CERTIFICATE_H
