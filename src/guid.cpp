#include "guid.hpp"

namespace open62541 {

Guid::Guid() {}

Guid::Guid(const UA_Guid &guid)
    : m_data1{guid.data1}, m_data2{guid.data2}, m_data3{guid.data3} {
  m_data4 = guid.data4[0] | guid.data4[1] << 1 | guid.data4[2] << 2 |
            guid.data4[3] << 3 | guid.data4[4] << 4 | guid.data4[5] << 5 |
            guid.data4[6] << 6 | guid.data4[7] << 7;
}

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
