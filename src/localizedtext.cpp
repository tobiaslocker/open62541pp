#include "localizedtext.hpp"

namespace open62541 {

LocalizedText::LocalizedText(UA_LocalizedText const &display_name) {
  m_text.assign(display_name.text.data,
                display_name.text.data + display_name.text.length);
  m_locale.assign(display_name.locale.data,
                  display_name.locale.data + display_name.locale.length);
}

LocalizedText::LocalizedText() : m_is_empty{true} {}

std::string LocalizedText::text() const { return m_text; }

std::string LocalizedText::locale() const { return m_locale; }

bool LocalizedText::is_empty() const { return m_is_empty; }

bool LocalizedText::operator==(const LocalizedText &rhs) const {
  return text() == rhs.text() && locale() == rhs.locale();
}

bool LocalizedText::operator!=(const LocalizedText &rhs) const {
  return text() != rhs.text() && locale() != rhs.locale();
}

}  // namespace open62541
