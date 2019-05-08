#include "certificate.hpp"

#include <iostream>

namespace open62541 {

Certificate::Certificate(UA_ByteString const &certificate) {
  m_bytes.assign(certificate.data, certificate.data + certificate.length);
}

std::string Certificate::to_string() const { return m_certificate; }

}  // namespace open62541
