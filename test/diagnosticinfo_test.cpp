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
  BOOST_TEST(a_empty.has_symbolic_id() == false);
  BOOST_TEST(a_empty.has_namespace_uri() == false);
  BOOST_TEST(a_empty.has_localized_text() == false);
  BOOST_TEST(a_empty.has_locale() == false);
  BOOST_TEST(a_empty.has_additional_info() == false);
  BOOST_TEST(a_empty.has_inner_status_code() == false);
  BOOST_TEST(a_empty.has_inner_diagnostic_info() == false);
  BOOST_TEST(a_empty.symbolic_id() == 0U);
  BOOST_TEST(a_empty.namespace_uri() == 0U);
  BOOST_TEST(a_empty.localized_text() == 0U);
  BOOST_TEST(a_empty.locale() == 0U);
  BOOST_TEST(a_empty.additional_info().empty());
  BOOST_TEST(a_empty.inner_status_code() == StatusCode::Unitialized);
  BOOST_TEST(a_empty.inner_diagnostic_info() == nullptr);
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto a = common::make_diagnostic_info_1();
  BOOST_TEST(!a.empty());
  BOOST_TEST(a.has_symbolic_id() == true);
  BOOST_TEST(a.has_namespace_uri() == false);
  BOOST_TEST(a.has_localized_text() == true);
  BOOST_TEST(a.has_locale() == false);
  BOOST_TEST(a.has_additional_info() == true);
  BOOST_TEST(a.has_inner_status_code() == false);
  BOOST_TEST(a.has_inner_diagnostic_info() == true);
  BOOST_TEST(a.symbolic_id() == 1U);
  BOOST_TEST(a.namespace_uri() == 2U);
  BOOST_TEST(a.localized_text() == 3U);
  BOOST_TEST(a.locale() == 4U);
  BOOST_TEST(a.additional_info() == "additional-info");
  BOOST_TEST(a.inner_status_code() == StatusCode::Good);
  BOOST_TEST(a.inner_diagnostic_info() == nullptr);

  auto a2 = common::make_diagnostic_info_2();
  BOOST_TEST(*a2.inner_diagnostic_info() == a);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_diagnostic_info_1();
  auto a1 = common::make_diagnostic_info_1();
  auto b = common::make_diagnostic_info_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
  auto s =
      "DiagnosticInfo(true, false, true, false, true, false, 1, 2, 3, 4, "
      "\"additional-info\", StatusCode::Good)";
  auto a = common::make_diagnostic_info_1();
  std::stringstream ss;
  ss << a;
  BOOST_TEST(s == ss.str());
  auto s_not = "not";
  BOOST_TEST(s_not != ss.str());
}

#pragma clang diagnostic pop
