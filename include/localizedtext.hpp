#ifndef OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
#define OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H

#include "open62541.h"

// STL
#include <string>

namespace open62541 {

class LocalizedText {
  std::string m_text;
  std::string m_locale;
  bool m_is_empty;
  explicit LocalizedText(UA_LocalizedText const &display_name);

 public:
  LocalizedText();
  std::string text() const;
  std::string locale() const;
  bool is_empty() const;
  bool operator==(LocalizedText const &rhs) const;
  bool operator!=(LocalizedText const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  LocalizedText const &localized_text);
  friend class ApplicationDescription;
  friend class ReferenceDescription;
  friend class Client;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_LOCALIZED_TEXT_H
