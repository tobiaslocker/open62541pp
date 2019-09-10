#include "localizedtext.hpp"
#include "ostr.hpp"

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

Locale::Locale(std::string const &locale) : m_data{locale} {}

std::string Locale::str() const { return m_data; }

bool Locale::empty() const { return m_empty; }

bool Locale::operator==(Locale const &rhs) const {
  return m_data == rhs.m_data;
}

bool Locale::operator!=(Locale const &rhs) const {
  return m_data != rhs.m_data;
}

std::ostream &operator<<(std::ostream &out, Locale const &op) {
  return out << "Locale(" << std::quoted(op.str()) << ')';
}

Text::Text() : m_empty{true} {}

Text::Text(std::string const &text) : m_data{text} {}

std::string Text::str() const { return m_data; }

bool Text::empty() const { return m_empty; }

bool Text::operator==(Text const &rhs) const { return m_data == rhs.m_data; }

bool Text::operator!=(Text const &rhs) const { return m_data != rhs.m_data; }

std::ostream &operator<<(std::ostream &out, Text const &op) {
  out << "Text(" << std::quoted(op.str()) << ')';
  return out;
}

std::ostream &operator<<(std::ostream &out, LocalizedText const &op) {
  return out << "LocalizedText(" << ostr::fmt(op.locale(), op.text()) << ')';
}

}  // namespace open62541
