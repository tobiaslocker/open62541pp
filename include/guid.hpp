#ifndef OPEN62541_CPP_WRAPPER_GUID_H
#define OPEN62541_CPP_WRAPPER_GUID_H

#include <memory>
#include <string>

namespace open62541 {

class Guid {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  Guid();
  ~Guid();

  Guid(Guid &&) noexcept;
  Guid &operator=(Guid &&) noexcept;
  Guid(Guid const &);
  Guid &operator=(Guid const &);

  Guid(std::string const &data);
  Guid(uint32_t data1, uint16_t data2, uint16_t data3, int64_t data4);

  std::string str() const;
  bool operator==(Guid const &rhs) const;
  bool operator!=(Guid const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, Guid const &op);

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_GUID_H
