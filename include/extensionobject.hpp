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

  bool empty() const;

  bool operator==(DataTypeMember const &rhs) const;
  bool operator!=(DataTypeMember const &rhs) const;
};

class DataType {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  DataType();
  ~DataType();

  DataType(DataType &&) noexcept;
  DataType &operator=(DataType &&) noexcept;
  DataType(DataType const &);
  DataType &operator=(DataType const &);

  DataType(std::string const &type_name,
           NodeId const &type_id,
           uint16_t mem_size,
           uint16_t type_index,
           std::byte const &members_size,
           bool builtin,
           bool pointer_free,
           bool overlayable,
           uint16_t binary_encoding_id,
           std::vector<DataTypeMember> const &members);

  std::string type_name() const;
  NodeId type_id() const;
  uint16_t mem_size() const;
  uint16_t type_index() const;
  std::byte members_size() const;
  bool builtin() const;
  bool pointer_free() const;
  bool overlayable() const;
  uint16_t binary_encoding_id() const;
  // uint16_t  xml_encoding_id() const;
  std::vector<DataTypeMember> members() const;

  bool empty() const;

  bool operator==(DataType const &rhs) const;
  bool operator!=(DataType const &rhs) const;
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
