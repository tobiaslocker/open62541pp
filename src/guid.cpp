#include "guid.hpp"

namespace open62541 {

Guid::Guid() {}

Guid::Guid(uint32_t data1, uint16_t data2, uint16_t data3, int64_t data4)
    : m_data1{data1}, m_data2{data2}, m_data3{data3}, m_data4{data4} {}

// Guid::Guid(const std::string &string) : m_string(string) {}

std::string Guid::str() const {
  std::stringstream stream;
  stream << std::hex << m_data1 << "-";
  stream << std::hex << m_data2 << "-";
  stream << std::hex << m_data3 << "-";
  stream << std::hex << m_data4;
  return stream.str();
}

bool Guid::operator==(const Guid &rhs) const {
  return m_data1 == rhs.m_data1 && m_data2 == rhs.m_data2 &&
         m_data3 == rhs.m_data3 && m_data4 == rhs.m_data4;
}

bool Guid::operator!=(const Guid &rhs) const {
  return m_data1 != rhs.m_data1 && m_data2 != rhs.m_data2 &&
         m_data3 != rhs.m_data3 && m_data4 != rhs.m_data4;
}

std::ostream &operator<<(std::ostream &out, const Guid &guid) {
  auto s = guid.str();
  out << s;
  return out;
}

}  // namespace open62541
