#include <sstream>

#include "guid.hpp"

namespace open62541 {

class Guid::impl {
  std::string m_string;

 public:
  impl() {}
  impl(uint32_t data1, uint16_t data2, uint16_t data3, int64_t data4) {
    std::stringstream stream;
    stream << std::hex << data1 << "-";
    stream << std::hex << data2 << "-";
    stream << std::hex << data3 << "-";
    stream << std::hex << data4;
    m_string = stream.str();
  }

  impl(std::string const &data) : m_string{data} {}

  std::string str() const { return m_string; }

  bool operator==(impl const &rhs) const { return m_string == rhs.m_string; }

  bool operator!=(impl const &rhs) const { return m_string != rhs.m_string; }
};

Guid::Guid() : d_ptr{std::make_unique<impl>()} {}

Guid::Guid(uint32_t data1, uint16_t data2, uint16_t data3, int64_t data4)
    : d_ptr{std::make_unique<impl>(data1, data2, data3, data4)} {}

Guid::Guid(std::string const &data) : d_ptr{std::make_unique<impl>(data)} {}

Guid::~Guid() = default;

Guid::Guid(Guid const &op) : d_ptr(new impl(*op.d_ptr)) {}

Guid &Guid::operator=(Guid const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

std::string Guid::str() const { return d_ptr->str(); }

bool Guid::operator==(Guid const &rhs) const { return *d_ptr == *rhs.d_ptr; }

bool Guid::operator!=(Guid const &rhs) const { return *d_ptr == *rhs.d_ptr; }

std::ostream &operator<<(std::ostream &out, Guid const &guid) {
  auto s = guid.str();
  out << s;
  return out;
}

}  // namespace open62541
