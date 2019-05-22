#include "guid.hpp"

namespace open62541 {

Guid::Guid() {}

Guid::Guid(uint32_t data1, uint16_t data2, uint16_t data3, int64_t data4) {
  std::stringstream stream;
  stream << std::hex << data1 << "-";
  stream << std::hex << data2 << "-";
  stream << std::hex << data3 << "-";
  stream << std::hex << data4;
  m_string = stream.str();
}

Guid::Guid(const std::string &string) : m_string(string) {}

std::string Guid::str() const { return m_string; }

bool Guid::operator==(const Guid &rhs) const {
  return m_string == rhs.m_string;
}

bool Guid::operator!=(const Guid &rhs) const {
  return m_string != rhs.m_string;
}

std::ostream &operator<<(std::ostream &out, const Guid &guid) {
  auto s = guid.str();
  out << s;
  return out;
}

}  // namespace open62541
