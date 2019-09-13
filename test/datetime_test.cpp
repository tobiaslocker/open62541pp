#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "common.hpp"
#include "datetime.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  DateTime a;
  DateTime b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  DateTime a;
  DateTime b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  DateTime a;
  DateTime b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  DateTime a;
  DateTime b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  DateTime const a_empty;
  BOOST_TEST(a_empty.empty());
  BOOST_TEST(a_empty.nano_sec() == 0);
  BOOST_TEST(a_empty.micro_sec() == 0);
  BOOST_TEST(a_empty.milli_sec() == 0);
  BOOST_TEST(a_empty.sec() == 0);
  BOOST_TEST(a_empty.min() == 0);
  BOOST_TEST(a_empty.hour() == 0);
  BOOST_TEST(a_empty.day() == 0);
  BOOST_TEST(a_empty.month() == 0);
  BOOST_TEST(a_empty.year() == 0);
  BOOST_TEST(a_empty.ldap_timestamp() == 0);
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  uint16_t nano_sec = 0;
  uint16_t micro_sec = 0;
  uint16_t milli_sec = 0;
  uint16_t sec = 35;
  uint16_t min = 26;
  uint16_t hour = 19;
  uint16_t day = 8;
  uint16_t month = 8;
  uint16_t year = 2019;
  int64_t ldap_timestamp = 132097659950000000;
  auto d = common::make_date_time_1();
  auto d2 = common::make_date_time_1_1();

  BOOST_TEST(d.nano_sec() == nano_sec);
  BOOST_TEST(d.micro_sec() == micro_sec);
  BOOST_TEST(d.milli_sec() == milli_sec);
  BOOST_TEST(d.sec() == sec);
  BOOST_TEST(d.min() == min);
  BOOST_TEST(d.hour() == hour);
  BOOST_TEST(d.day() == day);
  BOOST_TEST(d.month() == month);
  BOOST_TEST(d.year() == year);
  BOOST_TEST(d.ldap_timestamp() == ldap_timestamp);

  BOOST_TEST(d2.nano_sec() == nano_sec);
  BOOST_TEST(d2.micro_sec() == micro_sec);
  BOOST_TEST(d2.milli_sec() == milli_sec);
  BOOST_TEST(d2.sec() == sec);
  BOOST_TEST(d2.min() == min);
  BOOST_TEST(d2.hour() == hour);
  BOOST_TEST(d2.day() == day);
  BOOST_TEST(d2.month() == month);
  BOOST_TEST(d2.year() == year);
  BOOST_TEST(d2.ldap_timestamp() == ldap_timestamp);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_date_time_1();
  auto a1 = common::make_date_time_1();
  auto b = common::make_date_time_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
  auto s = "DateTime(132097659950000000)";
  auto a = common::make_date_time_1();
  std::stringstream ss;
  ss << a;
  BOOST_TEST(s == ss.str());
  auto s_not = "not";
  BOOST_TEST(s_not != ss.str());
}

#pragma clang diagnostic pop
