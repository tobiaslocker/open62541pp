#include "extensionobject.hpp"

namespace open62541 {

class DataTypeMember::impl {
  std::string m_member_name;
  uint16_t m_member_type_index;
  std::byte m_padding;
  bool m_namespace_zero;
  bool m_is_array;

 public:
  impl(){}

};

DataTypeMember::DataTypeMember() : d_ptr{std::make_unique<impl>()} {}

DataTypeMember::~DataTypeMember() = default;

DataTypeMember &DataTypeMember::operator=(DataTypeMember &&) noexcept =
    default;

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
