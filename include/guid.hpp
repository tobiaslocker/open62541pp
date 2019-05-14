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
  u_int32_t m_data1 = 0;
  u_int16_t m_data2 = 0;
  u_int16_t m_data3 = 0;
  int64_t m_data4 = 0;

  std::string m_string;

  Guid(UA_Guid const &guid);

 public:
  Guid();
  Guid(std::string const &string);
  std::string str() const;
  bool operator==(Guid const &rhs) const;
  bool operator!=(Guid const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out, Guid const &guid);

  friend class Identifier;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_GUID_H
