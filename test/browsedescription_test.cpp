#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "browsedescription.hpp"
#include "common.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  BrowseDescription a;
  BrowseDescription b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  BrowseDescription a;
  BrowseDescription b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  BrowseDescription a;
  BrowseDescription b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  BrowseDescription a;
  BrowseDescription b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  BrowseDescription const a;
  BOOST_TEST(a.empty());
  BOOST_TEST(a.node_id().empty());
  BOOST_TEST(a.browse_direction() == BrowseDirection::Both);
  BOOST_TEST(a.reference_type_id().empty());
  BOOST_TEST(!a.include_subtypes());
  BOOST_TEST(a.node_class_mask() == 0U);
  BOOST_TEST(a.result_mask() == 0U);
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto a = common::make_browse_description_1();
  BOOST_TEST(!a.empty());
  BOOST_TEST(a.node_id() == common::make_node_id_2());
  BOOST_TEST(a.browse_direction() == BrowseDirection::Forward);
  BOOST_TEST(a.reference_type_id() == common::make_node_id_1());
  BOOST_TEST(a.include_subtypes() == true);
  BOOST_TEST(a.node_class_mask() == 0U);
  BOOST_TEST(a.result_mask() == 0U);

  BOOST_TEST(a.node_id() != common::make_node_id_1());
  BOOST_TEST(a.browse_direction() != BrowseDirection::Inverse);
  BOOST_TEST(a.reference_type_id() != common::make_node_id_2());
  BOOST_TEST(a.include_subtypes() != false);
  BOOST_TEST(a.node_class_mask() != 3U);
  BOOST_TEST(a.result_mask() != 4U);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_browse_description_1();
  auto a1 = common::make_browse_description_1();
  auto b = common::make_browse_description_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
  auto s =
      "BrowseDescription(NodeId(4, \"my-node\", IdentifierType::String), "
      "BrowseDirection::Forward, NodeId(0, 1234, IdentifierType::Numeric), "
      "true, 0, 0)";
  auto a = common::make_browse_description_1();
  std::stringstream ss;
  ss << a;
  BOOST_TEST(s == ss.str());
  auto s_not = "not";
  BOOST_TEST(s_not != ss.str());
}

#pragma clang diagnostic pop
