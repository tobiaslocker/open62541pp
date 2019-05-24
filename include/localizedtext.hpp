#ifndef OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
#define OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H

// STL
#include <memory>
#include <string>

namespace open62541 {

class LocalizedText {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  LocalizedText();
  ~LocalizedText();

  LocalizedText(LocalizedText &&) noexcept;
  LocalizedText &operator=(LocalizedText &&) noexcept;
  LocalizedText(LocalizedText const &);
  LocalizedText &operator=(LocalizedText const &);

  LocalizedText(std::string const &text, std::string const &locale);

  std::string text() const;
  std::string locale() const;

  bool operator==(LocalizedText const &rhs) const;
  bool operator!=(LocalizedText const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
