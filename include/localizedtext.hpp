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
    Locale() : m_empty{true} {}
    Locale(std::string const &locale) : m_data {locale} {}
    std::string str() const { return m_data; }
    bool empty() const {return m_empty; }
    bool operator==(Locale const &rhs) const { return m_data == rhs.m_data; }
  bool operator!=(Locale const &rhs) const { return m_data != rhs.m_data; }
};

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

  // TODO make types for text & locale
//  LocalizedText(std::string const &text, std::string const &locale);
  LocalizedText(std::string const &text, Locale const &locale);

  std::string text() const;
  Locale locale() const;
  bool empty() const;

  bool operator==(LocalizedText const &rhs) const;
  bool operator!=(LocalizedText const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
