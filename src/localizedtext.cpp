#include "localizedtext.hpp"

namespace open62541 {

LocalizedText::LocalizedText(std::string const &text, std::string const &locale)
    : m_text{text}, m_locale{locale} {}

LocalizedText::LocalizedText() : m_is_empty{true} {}

std::string LocalizedText::text() const { return m_text; }

std::string LocalizedText::locale() const { return m_locale; }

bool LocalizedText::is_empty() const { return m_is_empty; }

bool LocalizedText::operator==(LocalizedText const &rhs) const {
  return text() == rhs.text() && locale() == rhs.locale();
}

bool LocalizedText::operator!=(LocalizedText const &rhs) const {
  return text() != rhs.text() && locale() != rhs.locale();
}

std::ostream &operator<<(std::ostream &out,
                         LocalizedText const &localized_text) {
  std::string s = localized_text.text() + " " + localized_text.locale();
  out << s;
  return out;
}

}  // namespace open62541
