#ifndef OPEN6541_CPP_WRAPPER_EXTENSION_OBJECT_H
#define OPEN6541_CPP_WRAPPER_EXTENSION_OBJECT_H

// STL
#include <cstddef>
#include <string>
#include <vector>

#include "nodeid.hpp"

namespace open62541 {

struct DataTypeMember {
  std::string m_member_name;
  uint16_t m_member_type_index;
  std::byte m_padding;
  bool m_namespace_zero;
  bool m_is_array;
};

struct DataType {
  std::string m_type_name;
  NodeId m_type_id;
  uint16_t m_mem_size;
  uint16_t m_type_index;
  std::byte m_members_size;
  bool m_builtin;
  bool m_pointerFree;
  bool m_overlayable;
  uint16_t m_binary_encoding_id;
  // uint16_t  xml_encoding_id;  /* NodeId of datatype when encoded as XML */
  std::vector<DataTypeMember> m_members;
};

class ExtensionObject {
 public:
  bool operator==(ExtensionObject const &rhs) const { return true; }
  bool operator!=(ExtensionObject const &rhs) const { return false; }
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
