#include "localizedtext.hpp"

#include <iomanip>

namespace open62541 {

class LocalizedText::impl {
  Text m_text;
  Locale m_locale;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(Locale const &locale, Text const &text)
      : m_text{text}, m_locale{locale} {}

  Text text() const { return m_text; }

  Locale locale() const { return m_locale; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return text() == rhs.text() && locale() == rhs.locale();
  }

  bool operator!=(impl const &rhs) const {
    return text() != rhs.text() || locale() != rhs.locale();
  }
};

LocalizedText::LocalizedText() : d_ptr{std::make_unique<impl>()} {}

LocalizedText &LocalizedText::operator=(LocalizedText &&) noexcept = default;

LocalizedText::LocalizedText(LocalizedText &&) noexcept = default;

LocalizedText::~LocalizedText() = default;

LocalizedText::LocalizedText(LocalizedText const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

LocalizedText &LocalizedText::operator=(LocalizedText const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

LocalizedText::LocalizedText(Locale const &locale, Text const &text)
    : d_ptr{std::make_unique<impl>(locale, text)} {}

Text LocalizedText::text() const { return d_ptr->text(); }

Locale LocalizedText::locale() const { return d_ptr->locale(); }

bool LocalizedText::empty() const { return d_ptr->empty(); }

bool LocalizedText::operator==(LocalizedText const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool LocalizedText::operator!=(LocalizedText const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

Locale::Locale() : m_empty{true} {}

Locale::Locale(const std::string &locale) : m_data{locale} {}

std::string Locale::str() const { return m_data; }

bool Locale::empty() const { return m_empty; }

bool Locale::operator==(const Locale &rhs) const {
  return m_data == rhs.m_data;
}

bool Locale::operator!=(const Locale &rhs) const {
  return m_data != rhs.m_data;
}

std::ostream &operator<<(std::ostream &out, const Locale &op) {
  out << "Locale(" << std::quoted(op.str()) << ')';
  return out;
}

Text::Text() : m_empty{true} {}

Text::Text(const std::string &text) : m_data{text} {}

std::string Text::str() const { return m_data; }

bool Text::empty() const { return m_empty; }

bool Text::operator==(const Text &rhs) const { return m_data == rhs.m_data; }

bool Text::operator!=(const Text &rhs) const { return m_data != rhs.m_data; }

std::ostream &operator<<(std::ostream &out, const Text &op) {
  out << "Text(" << std::quoted(op.str()) << ')';
  return out;
}

std::ostream &operator<<(std::ostream &out, const LocalizedText &op) {
  out << "LocalizedText(" << op.locale() << ", " << op.text() << ')';
  return out;
}

}  // namespace open62541
