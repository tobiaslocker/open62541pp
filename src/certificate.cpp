#include "certificate.hpp"

#include <iostream>

namespace open62541 {

Certificate::Certificate(UA_ByteString const &certificate) {
  m_bytes.assign(certificate.data, certificate.data + certificate.length);

  m_certificate.assign(certificate.data, certificate.data + certificate.length);

  if (auto c = reinterpret_cast<char *>(certificate.data)) {
    m_certificate = std::string(c);
  }
}

std::string Certificate::to_string() const { return m_certificate; }

}  // namespace open62541
