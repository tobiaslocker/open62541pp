#include "localizedtext.hpp"

namespace open62541 {

class LocalizedText::impl {
  std::string m_text;
  std::string m_locale;

 public:
  impl() {}

  impl(std::string const &text, std::string const &locale)
      : m_text{text}, m_locale{locale} {}

  std::string text() const { return m_text; }

  std::string locale() const { return m_locale; }

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

LocalizedText::LocalizedText(std::string const &text, std::string const &locale)
    : d_ptr{std::make_unique<impl>(text, locale)} {}

std::string LocalizedText::text() const { return d_ptr->text(); }

std::string LocalizedText::locale() const { return d_ptr->locale(); }

bool LocalizedText::operator==(LocalizedText const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool LocalizedText::operator!=(LocalizedText const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
