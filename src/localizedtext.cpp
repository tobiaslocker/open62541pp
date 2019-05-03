#include "localizedtext.hpp"

namespace open62541 {

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

LocalizedText::LocalizedText(UA_LocalizedText const &display_name)
    : m_text{to_std_string(display_name.text)},
      m_locale{to_std_string(display_name.locale)} {}

LocalizedText::LocalizedText() : m_is_empty{true} {}

std::string LocalizedText::text() const { return m_text; }

std::string LocalizedText::locale() const { return m_locale; }

bool LocalizedText::is_empty() const { return m_is_empty; }

}  // namespace open62541
