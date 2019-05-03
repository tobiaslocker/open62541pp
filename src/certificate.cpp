#include "certificate.hpp"

namespace open62541 {

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

Certificate::Certificate(UA_ByteString const &certificate)
    : m_certificate{to_std_string(certificate)} {}

std::string Certificate::to_string() const { return m_certificate; }

}  // namespace open62541
