#ifndef OPEN6541_CPP_WRAPPER_EXTENSION_OBJECT_H
#define OPEN6541_CPP_WRAPPER_EXTENSION_OBJECT_H

// STL
#include <any>
#include <cstddef>
#include <string>
#include <variant>
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
  bool m_pointer_free;
  bool m_overlayable;
  uint16_t m_binary_encoding_id;
  // uint16_t  xml_encoding_id;  /* NodeId of datatype when encoded as XML */
  std::vector<DataTypeMember> m_members;
};

enum class ExtensionObjectEncoding {
  Nobody = 0,
  ByteString = 1,
  Xml = 2,
  Decoded = 3,
  DecodedNodelete = 4
};

class ExtensionObject {
  using encoded_t = std::pair<NodeId, ByteString>;
  using decoded_t = std::pair<DataType, std::any>;

  encoded_t m_encoded;
  decoded_t m_decoded;

  bool decoded = false;

  ExtensionObjectEncoding m_encoding;

 public:
  ExtensionObject(std::pair<NodeId, ByteString> encoded,
                  ExtensionObjectEncoding encoding)
      : m_encoded{encoded}, m_encoding{encoding} {}
  ExtensionObject(std::pair<DataType, std::any> decoded,
                  ExtensionObjectEncoding encoding)
      : m_decoded{decoded}, decoded{true}, m_encoding{encoding} {}

  std::variant<encoded_t, decoded_t> content() const {
    if (decoded) {
      return m_decoded;
    }
    return m_encoded;
  }

  bool operator==(ExtensionObject const &rhs) const {
    return content() == rhs.content();
  }
  bool operator!=(ExtensionObject const &rhs) const {
    return content() == rhs.content();
  }
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
