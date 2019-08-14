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
  //  BOOST_TEST(a.response_header() == common::make_response_header_1());
  //  BOOST_TEST(a.view() == common::make_view_description_1());
  //  BOOST_TEST(a.max_references() == 34U);
  //  BOOST_TEST(a.nodes_to_browse().size() == 2U);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_browse_response_1();
  auto a1 = common::make_browse_response_1();
  auto b = common::make_browse_response_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

#pragma clang diagnostic pop
