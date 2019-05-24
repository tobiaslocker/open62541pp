#ifndef OPEN62541_CPP_WRAPPER_QUALIFIED_NAME_H
#define OPEN62541_CPP_WRAPPER_QUALIFIED_NAME_H

// STL
#include <memory>
#include <string>

namespace open62541 {

class QualifiedName {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  QualifiedName();
  ~QualifiedName();

  QualifiedName(QualifiedName &&) noexcept;
  QualifiedName &operator=(QualifiedName &&) noexcept;
  QualifiedName(QualifiedName const &);
  QualifiedName &operator=(QualifiedName const &);

  QualifiedName(std::string const &name, uint16_t namespace_index);
  std::string name() const;
  uint16_t namespace_index() const;

  bool operator==(QualifiedName const &rhs) const;
  bool operator!=(QualifiedName const &rhs) const;

  friend std::ostream &operator<<(std::ostream &out, QualifiedName const &name);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_QUALIFIED_NAME_H
