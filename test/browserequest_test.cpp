#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "browserequest.hpp"
#include "common.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  BrowseRequest a;
  BrowseRequest b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  BrowseRequest a;
  BrowseRequest b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  BrowseRequest a;
  BrowseRequest b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  BrowseRequest a;
  BrowseRequest b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  BrowseRequest const a;
  BOOST_TEST(a.empty());
  BOOST_TEST(a.request_header().empty());
  BOOST_TEST(a.view().empty());
  BOOST_TEST(a.max_references() == 0U);
  BOOST_TEST(a.nodes_to_browse().empty());
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto a = common::make_browse_request_1();
  BOOST_TEST(!a.empty());
  BOOST_TEST(a.request_header() == common::make_request_header_1());
  BOOST_TEST(a.view() == common::make_view_description_1());
  BOOST_TEST(a.max_references() == 34U);
  BOOST_TEST(a.nodes_to_browse().size() == 2U);
  BOOST_TEST(a.nodes_to_browse().at(0) == common::make_browse_description_1());
  BOOST_TEST(a.nodes_to_browse().at(1) == common::make_browse_description_2());

  BOOST_TEST(a.request_header() != common::make_request_header_2());
  BOOST_TEST(a.view() != common::make_view_description_2());
  BOOST_TEST(a.max_references() != 3U);
  BOOST_TEST(a.nodes_to_browse().size() != 22U);
  BOOST_TEST(a.nodes_to_browse().at(0) != common::make_browse_description_2());
  BOOST_TEST(a.nodes_to_browse().at(1) != common::make_browse_description_1());
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_browse_request_1();
  auto a1 = common::make_browse_request_1();
  auto b = common::make_browse_request_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

#pragma clang diagnostic pop
