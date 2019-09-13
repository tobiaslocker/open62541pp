#include "datetime.hpp"

#include <chrono>
#include <ctime>
#include <iostream>

namespace open62541 {

class DateTime::impl {
  uint16_t m_nano_sec = 0;
  uint16_t m_micro_sec = 0;
  uint16_t m_milli_sec = 0;
  uint16_t m_sec = 0;
  uint16_t m_min = 0;
  uint16_t m_hour = 0;
  uint16_t m_day = 0;
  uint16_t m_month = 0;
  uint16_t m_year = 0;
  int64_t m_ldap_timestamp = 0;

  bool m_empty = false;

 public:
  impl() : m_empty{true} {}

  impl(int64_t ldap_timestamp) : m_ldap_timestamp{ldap_timestamp} {
    m_nano_sec = static_cast<uint16_t>((ldap_timestamp % 10) * 100);
    m_micro_sec = static_cast<uint16_t>((ldap_timestamp % 10000) / 10);
    m_milli_sec = static_cast<uint16_t>((ldap_timestamp % 10000000) / 10000);
    time_t secs_since_epoch = ldap_timestamp / 10000000LL - 11644473600LL;
    auto lt = localtime(&secs_since_epoch);
    m_year = static_cast<uint16_t>(lt->tm_year + 1900);
    m_month = static_cast<uint16_t>(lt->tm_mon + 1);
    m_sec = static_cast<uint16_t>(lt->tm_sec);
    m_min = static_cast<uint16_t>(lt->tm_min);
    m_hour = static_cast<uint16_t>(lt->tm_hour);
    m_day = static_cast<uint16_t>(lt->tm_mday);
  }

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
        m_year{year} {
    time_t t;
    struct tm tm;
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = min;
    tm.tm_sec = sec;
    t = timegm(&tm);
    m_ldap_timestamp = (t + 11644473600LL) * 10000000LL;
    m_ldap_timestamp += nano_sec / 100 + micro_sec * 10 + milli_sec * 10000;
  }

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

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return nano_sec() == rhs.nano_sec() && micro_sec() == rhs.micro_sec() &&
           milli_sec() == rhs.milli_sec() && sec() == rhs.sec() &&
           min() == rhs.min() && hour() == rhs.hour() && day() == rhs.day() &&
           month() == rhs.month() && year() == rhs.year() &&
           ldap_timestamp() == rhs.ldap_timestamp();
  }

  bool operator!=(impl const &rhs) const {
    return nano_sec() != rhs.nano_sec() || micro_sec() != rhs.micro_sec() ||
           milli_sec() != rhs.milli_sec() || sec() != rhs.sec() ||
           min() != rhs.min() || hour() != rhs.hour() || day() != rhs.day() ||
           month() != rhs.month() || year() != rhs.year() ||
           ldap_timestamp() != rhs.ldap_timestamp();
  }
};

DateTime::~DateTime() = default;

DateTime::DateTime(DateTime const &op) : d_ptr(new impl(*op.d_ptr)) {}

DateTime::DateTime(DateTime &&) noexcept = default;

DateTime &DateTime::operator=(DateTime &&) noexcept = default;

DateTime::DateTime() : d_ptr{std::make_unique<impl>()} {}

DateTime &DateTime::operator=(DateTime const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

DateTime::DateTime(int64_t ldap_timestamp)
    : d_ptr{std::make_unique<impl>(ldap_timestamp)} {}

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

bool DateTime::empty() const { return d_ptr->empty(); }

bool DateTime::operator==(DateTime const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool DateTime::operator!=(DateTime const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const DateTime &op) {
  return out << "DateTime(" << op.ldap_timestamp() << ')';
}

}  // namespace open62541
