#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "common.hpp"
#include "diagnosticinfo.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  DiagnosticInfo a;
  DiagnosticInfo b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  DiagnosticInfo a;
  DiagnosticInfo b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  DiagnosticInfo a;
  DiagnosticInfo b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  DiagnosticInfo a;
  DiagnosticInfo b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  DiagnosticInfo const a_empty;
  BOOST_TEST(a_empty.empty());
//  BOOST_TEST(a_empty.nano_sec() == 0);
//  BOOST_TEST(a_empty.micro_sec() == 0);
//  BOOST_TEST(a_empty.milli_sec() == 0);
//  BOOST_TEST(a_empty.sec() == 0);
//  BOOST_TEST(a_empty.min() == 0);
//  BOOST_TEST(a_empty.hour() == 0);
//  BOOST_TEST(a_empty.day() == 0);
//  BOOST_TEST(a_empty.month() == 0);
//  BOOST_TEST(a_empty.year() == 0);
//  BOOST_TEST(a_empty.ldap_timestamp() == 0);
}

BOOST_AUTO_TEST_CASE(test_constructor) {
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_diagnostic_info_1();
  auto a1 = common::make_diagnostic_info_1();
  auto b = common::make_diagnostic_info_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
  auto s = "";
  auto a = common::make_date_time_1();
  std::stringstream ss;
  ss << a;
  BOOST_TEST(s == ss.str());
  auto s_not = "not";
  BOOST_TEST(s_not != ss.str());
}

#pragma clang diagnostic pop
