#include "extensionobject.hpp"

namespace open62541 {

class DataTypeMember::impl {
  std::string m_member_name;
  uint16_t m_member_type_index = 0;
  std::byte m_padding;
  bool m_namespace_zero = false;
  bool m_is_array = false;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}
  impl(std::string const &member_name,
       uint16_t member_type_index,
       std::byte const &padding,
       bool namespace_zero,
       bool is_array)
      : m_member_name{member_name},
        m_member_type_index{member_type_index},
        m_padding{padding},
        m_namespace_zero{namespace_zero},
        m_is_array{is_array} {}

  std::string member_name() const { return m_member_name; }

  uint16_t member_type_index() const { return m_member_type_index; }

  std::byte padding() const { return m_padding; }

  bool namespace_zero() const { return m_namespace_zero; }

  bool is_array() const { return m_is_array; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return member_name() == rhs.member_name() &&
           member_type_index() == rhs.member_type_index() &&
           padding() == rhs.padding() &&
           namespace_zero() == rhs.namespace_zero() &&
           is_array() == rhs.is_array();
  }
  bool operator!=(impl const &rhs) const {
    return member_name() != rhs.member_name() ||
           member_type_index() != rhs.member_type_index() ||
           padding() != rhs.padding() ||
           namespace_zero() != rhs.namespace_zero() ||
           is_array() != rhs.is_array();
  }
};

DataTypeMember::DataTypeMember() : d_ptr{std::make_unique<impl>()} {}

DataTypeMember::DataTypeMember(std::string const &member_name,
                               uint16_t member_type_index,
                               std::byte const &padding,
                               bool namespace_zero,
                               bool is_array)
    : d_ptr{std::make_unique<impl>(
          member_name, member_type_index, padding, namespace_zero, is_array)} {}

DataTypeMember::~DataTypeMember() = default;

DataTypeMember &DataTypeMember::operator=(DataTypeMember &&) noexcept = default;

DataTypeMember::DataTypeMember(DataTypeMember &&) noexcept = default;

DataTypeMember::DataTypeMember(DataTypeMember const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

DataTypeMember &DataTypeMember::operator=(DataTypeMember const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

std::string DataTypeMember::member_name() const { return d_ptr->member_name(); }

uint16_t DataTypeMember::member_type_index() const {
  return d_ptr->member_type_index();
}

std::byte DataTypeMember::padding() const { return d_ptr->padding(); }

bool DataTypeMember::namespace_zero() const { return d_ptr->namespace_zero(); }

bool DataTypeMember::is_array() const { return d_ptr->is_array(); }

bool DataTypeMember::empty() const { return d_ptr->empty(); }

bool DataTypeMember::operator==(DataTypeMember const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool DataTypeMember::operator!=(DataTypeMember const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

class DataType::impl {
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

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(std::string const &type_name,
       NodeId const &type_id,
       uint16_t mem_size,
       uint16_t type_index,
       std::byte const &members_size,
       bool builtin,
       bool pointer_free,
       bool overlayable,
       uint16_t binary_encoding_id,
       std::vector<DataTypeMember> const &members)
      : m_type_name{type_name},
        m_type_id{type_id},
        m_mem_size{mem_size},
        m_type_index{type_index},
        m_members_size{members_size},
        m_builtin{builtin},
        m_pointer_free{pointer_free},
        m_overlayable{overlayable},
        m_binary_encoding_id{binary_encoding_id},
        m_members{members} {}

  std::string type_name() const { return m_type_name; }

  NodeId type_id() const { return m_type_id; }

  uint16_t mem_size() const { return m_mem_size; }

  uint16_t type_index() const { return m_type_index; }

  std::byte members_size() const { return m_members_size; }

  bool builtin() const { return m_builtin; }

  bool pointer_free() const { return m_pointer_free; }

  bool overlayable() const { return m_overlayable; }

  uint16_t binary_encoding_id() const { return m_binary_encoding_id; }

  std::vector<DataTypeMember> members() const { return m_members; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return type_name() == rhs.type_name() && type_id() == rhs.type_id() &&
           mem_size() == rhs.mem_size() && type_index() == rhs.type_index() &&
           members_size() == rhs.members_size() && builtin() == rhs.builtin() &&
           pointer_free() == rhs.pointer_free() &&
           overlayable() == rhs.overlayable() &&
           binary_encoding_id() == rhs.binary_encoding_id() &&
           members() == rhs.members();
  }

  bool operator!=(impl const &rhs) const {
    return type_name() != rhs.type_name() || type_id() != rhs.type_id() ||
           mem_size() != rhs.mem_size() || type_index() != rhs.type_index() ||
           members_size() != rhs.members_size() || builtin() != rhs.builtin() ||
           pointer_free() != rhs.pointer_free() ||
           overlayable() != rhs.overlayable() ||
           binary_encoding_id() != rhs.binary_encoding_id() ||
           members() != rhs.members();
  }
};

DataType::DataType(std::string const &type_name,
                   NodeId const &type_id,
                   uint16_t mem_size,
                   uint16_t type_index,
                   std::byte const &members_size,
                   bool builtin,
                   bool pointer_free,
                   bool overlayable,
                   uint16_t binary_encoding_id,
                   std::vector<DataTypeMember> const &members)
    : d_ptr{std::make_unique<impl>(type_name,
                                   type_id,
                                   mem_size,
                                   type_index,
                                   members_size,
                                   builtin,
                                   pointer_free,
                                   overlayable,
                                   binary_encoding_id,
                                   members)} {}

DataType::DataType() : d_ptr{std::make_unique<impl>()} {}

DataType::~DataType() = default;

DataType &DataType::operator=(DataType &&) noexcept = default;

DataType::DataType(DataType &&) noexcept = default;

DataType::DataType(DataType const &op) : d_ptr(new impl(*op.d_ptr)) {}

DataType &DataType::operator=(DataType const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

bool DataType::empty() const { return d_ptr->empty(); }

bool DataType::operator==(DataType const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool DataType::operator!=(DataType const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
