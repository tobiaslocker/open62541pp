#include "localizedtext.hpp"

namespace open62541 {

class LocalizedText::impl {
  Text m_text;
  Locale m_locale;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(Text const &text, Locale const &locale)
      : m_text{text}, m_locale{locale} {}

  Text text() const { return m_text; }

  Locale locale() const { return m_locale; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return text() == rhs.text() && locale() == rhs.locale();
  }

  bool operator!=(impl const &rhs) const {
    return text() != rhs.text() && locale() != rhs.locale();
  }
};

LocalizedText::LocalizedText() : d_ptr{std::make_unique<impl>()} {}

LocalizedText::~LocalizedText() = default;

LocalizedText::LocalizedText(LocalizedText const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

LocalizedText &LocalizedText::operator=(LocalizedText const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

LocalizedText::LocalizedText(Text const &text, Locale const &locale)
    : d_ptr{std::make_unique<impl>(text, locale)} {}

Text LocalizedText::text() const { return d_ptr->text(); }

Locale LocalizedText::locale() const { return d_ptr->locale(); }

bool LocalizedText::empty() const { return d_ptr->empty(); }

bool LocalizedText::operator==(LocalizedText const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool LocalizedText::operator!=(LocalizedText const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
