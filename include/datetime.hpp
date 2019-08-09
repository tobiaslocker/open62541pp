#ifndef OPEN6541_CPP_WRAPPER_DATE_TIME_H
#define OPEN6541_CPP_WRAPPER_DATE_TIME_H

// STL
#include <memory>
#include <string>

namespace open62541 {

class DateTime {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  DateTime();
  ~DateTime();

  DateTime(DateTime &&) noexcept;
  DateTime &operator=(DateTime &&) noexcept;
  DateTime(DateTime const &);
  DateTime &operator=(DateTime const &);

  DateTime(int64_t ldap_timestamp);

  DateTime(uint16_t nano_sec,
           uint16_t micro_sec,
           uint16_t milli_sec,
           uint16_t sec,
           uint16_t min,
           uint16_t hour,
           uint16_t day,
           uint16_t month,
           uint16_t year);

  uint16_t nano_sec() const;
  uint16_t micro_sec() const;
  uint16_t milli_sec() const;
  uint16_t sec() const;
  uint16_t min() const;
  uint16_t hour() const;
  uint16_t day() const;
  uint16_t month() const;
  uint16_t year() const;
  int64_t ldap_timestamp() const;

  bool operator==(DateTime const &rhs) const;
  bool operator!=(DateTime const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_DATE_TIME_H
