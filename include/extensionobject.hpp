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

class DataTypeMember {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  DataTypeMember();
  ~DataTypeMember();

  DataTypeMember(DataTypeMember &&) noexcept;
  DataTypeMember &operator=(DataTypeMember &&) noexcept;
  DataTypeMember(DataTypeMember const &);
  DataTypeMember &operator=(DataTypeMember const &);

  DataTypeMember(std::string const &member_name,
                 uint16_t member_type_index,
                 std::byte const &padding,
                 bool namespace_zero,
                 bool is_array);

  std::string member_name() const;
  uint16_t member_type_index() const;
  std::byte padding() const;
  bool namespace_zero() const;
  bool is_array() const;
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
  bool operator==(DataType const &rhs) const { return true; }
  bool operator!=(DataType const &rhs) const { return false; }
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
  using decoded_t = std::pair<DataType, std::shared_ptr<void>>;

  encoded_t m_encoded;
  decoded_t m_decoded;

  bool decoded = false;

  ExtensionObjectEncoding m_encoding;

 public:
  ExtensionObject() = default;
  ExtensionObject(std::pair<NodeId, ByteString> encoded,
                  ExtensionObjectEncoding encoding)
      : m_encoded{encoded}, m_encoding{encoding} {}
  ExtensionObject(std::pair<DataType, std::shared_ptr<void>> decoded,
                  ExtensionObjectEncoding encoding)
      : m_decoded{decoded}, decoded{true}, m_encoding{encoding} {}

  ExtensionObjectEncoding encoding() const { return m_encoding; }

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
