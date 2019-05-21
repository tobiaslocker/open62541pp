#ifndef OPEN62541_CPP_WRAPPER_GUID_H
#define OPEN62541_CPP_WRAPPER_GUID_H

#include "open62541.h"

// STL
#include <sstream>

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {
using namespace nlohmann;
class Guid {
  uint32_t m_data1 = 0;
  uint16_t m_data2 = 0;
  uint16_t m_data3 = 0;
  int64_t m_data4 = 0;
  //  std::string m_string;

 public:
  Guid();
  //  Guid(std::string const &string);
  Guid(uint32_t data1, uint16_t data2, uint16_t data3, int64_t data4);
  std::string str() const;
  bool operator==(Guid const &rhs) const;
  bool operator!=(Guid const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out, Guid const &guid);

  friend class Identifier;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_GUID_H
