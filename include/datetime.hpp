#ifndef OPEN6541_CPP_WRAPPER_DATE_TIME_H
#define OPEN6541_CPP_WRAPPER_DATE_TIME_H

// STL
#include <string>

namespace open62541 {

class DateTime {
  uint16_t m_nano_sec;
  uint16_t m_micro_sec;
  uint16_t m_milli_sec;
  uint16_t m_sec;
  uint16_t m_min;
  uint16_t m_hour;
  uint16_t m_day;
  uint16_t m_month;
  uint16_t m_year;
  int64_t m_number_of_100_nanoseconds_since_jan_1_1601;

 public:
  DateTime(int64_t number_of_100_nanoseconds_since_jan_1_1601);

  DateTime(uint16_t nano_sec,
           uint16_t micro_sec,
           uint16_t milli_sec,
           uint16_t sec,
           uint16_t min,
           uint16_t hour,
           uint16_t day,
           uint16_t month,
           uint16_t year,
           int64_t number_of_100_nanoseconds_since_jan_1_1601);

  uint16_t nano_sec() const;
  uint16_t micro_sec() const;
  uint16_t milli_sec() const;
  uint16_t sec() const;
  uint16_t min() const;
  uint16_t hour() const;
  uint16_t day() const;
  uint16_t month() const;
  uint16_t year() const;
  int64_t number_of_100_nanoseconds_since_jan_1_1601() const;

  bool operator==(DateTime const &rhs) const { return true; }
  bool operator!=(DateTime const &rhs) const { return false; }
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_DATE_TIME_H
