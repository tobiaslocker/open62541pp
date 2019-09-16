#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "common.hpp"
#include "expandednodeid.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  ExpandedNodeId a;
  ExpandedNodeId b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  ExpandedNodeId a;
  ExpandedNodeId b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  ExpandedNodeId a;
  ExpandedNodeId b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  ExpandedNodeId a;
  ExpandedNodeId b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  ExpandedNodeId const a;
  BOOST_TEST(a.empty());
  BOOST_TEST(a.namespace_uri().empty());
  BOOST_TEST(a.node_id().empty());
  BOOST_TEST(a.server_index() == 0U);
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto e = common::make_expanded_node_id_1();
  BOOST_TEST(!e.empty());
  BOOST_TEST(e.node_id() == common::make_node_id_1());
  BOOST_TEST(e.namespace_uri() == "ns:test:uri:1234");
  BOOST_TEST(e.server_index() == 2U);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_expanded_node_id_1();
  auto a1 = common::make_expanded_node_id_1();
  auto b = common::make_expanded_node_id_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
  auto s =
      "ExpandedNodeId(NodeId(0, 1234, IdentifierType::Numeric), "
      "\"ns:test:uri:1234\", 2)";
  auto a = common::make_expanded_node_id_1();
  std::stringstream ss;
  ss << a;
  BOOST_TEST(s == ss.str());
  auto s_not = "not";
  BOOST_TEST(s_not != ss.str());
}

#pragma clang diagnostic pop
