#include "extensionobject.hpp"

namespace open62541 {

class DataTypeMember::impl {
  std::string m_member_name;
  uint16_t m_member_type_index;
  std::byte m_padding;
  bool m_namespace_zero;
  bool m_is_array;

 public:
  impl();

  ~impl();
};

}  // namespace open62541
