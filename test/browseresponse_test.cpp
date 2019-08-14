#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "browseresponse.hpp"
#include "common.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  BrowseResponse a;
  BrowseResponse b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  BrowseResponse a;
  BrowseResponse b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  BrowseResponse a;
  BrowseResponse b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  BrowseResponse a;
  BrowseResponse b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  BrowseResponse const a;
  BOOST_TEST(a.empty());
  BOOST_TEST(a.response_header().empty());
  BOOST_TEST(a.results().empty());
  BOOST_TEST(a.diagnostic_infos().empty());
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto a = common::make_browse_response_1();
  BOOST_TEST(!a.empty());
  BOOST_TEST(a.response_header() == common::make_response_header_1());
  BOOST_TEST(a.results().size() == 2U);
  BOOST_TEST(a.results().at(0) == common::make_browse_result_1());
  BOOST_TEST(a.results().at(1) == common::make_browse_result_2());
  BOOST_TEST(a.diagnostic_infos().size() == 2U);
  BOOST_TEST(a.diagnostic_infos().at(0) == common::make_diagnostic_info_1());
  BOOST_TEST(a.diagnostic_infos().at(1) == common::make_diagnostic_info_2());
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_browse_response_1();
  auto a1 = common::make_browse_response_1();
  auto b = common::make_browse_response_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

#pragma clang diagnostic pop
