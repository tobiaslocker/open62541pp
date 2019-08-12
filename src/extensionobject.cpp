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
};

DataTypeMember::DataTypeMember() : d_ptr{std::make_unique<impl>()} {}

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

}  // namespace open62541
