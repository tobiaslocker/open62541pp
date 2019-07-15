#include "datetime.hpp"

namespace open62541 {

class DateTime::impl {
  uint16_t m_nano_sec;
  uint16_t m_micro_sec;
  uint16_t m_milli_sec;
  uint16_t m_sec;
  uint16_t m_min;
  uint16_t m_hour;
  uint16_t m_day;
  uint16_t m_month;
  uint16_t m_year;
  int64_t m_ldap_timestamp;

 public:
  impl() {}

  impl(uint16_t nano_sec,
       uint16_t micro_sec,
       uint16_t milli_sec,
       uint16_t sec,
       uint16_t min,
       uint16_t hour,
       uint16_t day,
       uint16_t month,
       uint16_t year)
      : m_nano_sec{nano_sec},
        m_micro_sec{micro_sec},
        m_milli_sec{milli_sec},
        m_sec{sec},
        m_min{min},
        m_hour{hour},
        m_day{day},
        m_month{month},
        m_year{year} {}

  uint16_t nano_sec() const { return m_nano_sec; }

  uint16_t micro_sec() const { return m_micro_sec; }

  uint16_t milli_sec() const { return m_milli_sec; }

  uint16_t sec() const { return m_sec; }

  uint16_t min() const { return m_min; }

  uint16_t hour() const { return m_hour; }

  uint16_t day() const { return m_day; }

  uint16_t month() const { return m_month; }

  uint16_t year() const { return m_year; }

  int64_t ldap_timestamp() const { return m_ldap_timestamp; }

  bool operator==(impl const &rhs) const {
    return nano_sec() == rhs.nano_sec() && micro_sec() == rhs.micro_sec() &&
           milli_sec() == rhs.milli_sec() && sec() == rhs.sec() &&
           min() == rhs.min() && hour() == rhs.hour() && day() == rhs.day() &&
           month() == rhs.month() && year() == rhs.year() &&
           ldap_timestamp() == rhs.ldap_timestamp();
  }

  bool operator!=(impl const &rhs) const {
    return nano_sec() != rhs.nano_sec() && micro_sec() != rhs.micro_sec() &&
           milli_sec() != rhs.milli_sec() && sec() != rhs.sec() &&
           min() != rhs.min() && hour() != rhs.hour() && day() != rhs.day() &&
           month() != rhs.month() && year() != rhs.year() &&
           ldap_timestamp() != rhs.ldap_timestamp();
  }
};

DateTime::DateTime(DateTime &&) noexcept = default;

DateTime::~DateTime() = default;

DateTime::DateTime(DateTime const &op) : d_ptr(new impl(*op.d_ptr)) {}

DateTime &DateTime::operator=(DateTime const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

DateTime::DateTime() : d_ptr{std::make_unique<impl>()} {}

DateTime::DateTime(uint16_t nano_sec,
                   uint16_t micro_sec,
                   uint16_t milli_sec,
                   uint16_t sec,
                   uint16_t min,
                   uint16_t hour,
                   uint16_t day,
                   uint16_t month,
                   uint16_t year)
    : d_ptr{std::make_unique<impl>(
          nano_sec, micro_sec, milli_sec, sec, min, hour, day, month, year)} {}

uint16_t DateTime::nano_sec() const { return d_ptr->nano_sec(); }

uint16_t DateTime::micro_sec() const { return d_ptr->micro_sec(); }

uint16_t DateTime::milli_sec() const { return d_ptr->milli_sec(); }

uint16_t DateTime::sec() const { return d_ptr->sec(); }

uint16_t DateTime::min() const { return d_ptr->min(); }

uint16_t DateTime::hour() const { return d_ptr->hour(); }

uint16_t DateTime::day() const { return d_ptr->day(); }

uint16_t DateTime::month() const { return d_ptr->month(); }

uint16_t DateTime::year() const { return d_ptr->year(); }

int64_t DateTime::ldap_timestamp() const { return d_ptr->ldap_timestamp(); }

bool DateTime::operator==(DateTime const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool DateTime::operator!=(DateTime const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
