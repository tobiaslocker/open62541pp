#include "localizedtext.hpp"

namespace open62541 {

LocalizedText::LocalizedText(UA_LocalizedText const &display_name) {
  if (auto c = reinterpret_cast<char *>(display_name.text.data)) {
    m_text = std::string(c, display_name.text.length);
  }
  if (auto c = reinterpret_cast<char *>(display_name.locale.data)) {
    m_locale = std::string(c, display_name.locale.length);
  }
}

LocalizedText::LocalizedText() : m_is_empty{true} {}

std::string LocalizedText::text() const { return m_text; }

std::string LocalizedText::locale() const { return m_locale; }

bool LocalizedText::is_empty() const { return m_is_empty; }

bool LocalizedText::operator==(const LocalizedText &rhs) {
  return text() == rhs.text() && locale() == rhs.locale();
}

bool LocalizedText::operator!=(const LocalizedText &rhs) {
  return text() != rhs.text() && locale() != rhs.locale();
}

}  // namespace open62541
