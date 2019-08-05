#ifndef OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
#define OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H

// STL
#include <memory>
#include <string>

namespace open62541 {

class Locale {
  std::string m_data;
  bool m_empty = false;

 public:
  Locale();
  explicit Locale(std::string const &locale);
  std::string str() const;
  bool empty() const;
  bool operator==(Locale const &rhs) const;
  bool operator!=(Locale const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, Locale const &op);

class Text {
  std::string m_data;
  bool m_empty = false;

 public:
  Text();
  explicit Text(std::string const &text);
  std::string str() const;
  bool empty() const;
  bool operator==(Text const &rhs) const;
  bool operator!=(Text const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, Text const &op);

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

  LocalizedText(Locale const &locale, Text const &text);

  Text text() const;
  Locale locale() const;
  bool empty() const;

  bool operator==(LocalizedText const &rhs) const;
  bool operator!=(LocalizedText const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, LocalizedText const &op);
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
