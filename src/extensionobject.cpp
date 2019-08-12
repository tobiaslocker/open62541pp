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

}  // namespace open62541
