#include "certificate.hpp"

#include <iostream>

namespace open62541 {

Certificate::Certificate(const std::string &certificate) {
  //  m_bytes.assign(certificate.data, certificate.data + certificate.length);
  //  m_certificate.assign(certificate.data, certificate.data +
  //  certificate.length);
}

std::string Certificate::str() const { return m_certificate; }

bool Certificate::operator==(const Certificate &rhs) const { return true; }

bool Certificate::operator!=(const Certificate &rhs) const { return true; }

}  // namespace open62541
