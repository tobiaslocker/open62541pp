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

  BOOST_TEST(a.response_header() != common::make_response_header_2());
  BOOST_TEST(a.results().size() != 0U);
  BOOST_TEST(a.results().at(0) != common::make_browse_result_2());
  BOOST_TEST(a.results().at(1) != common::make_browse_result_1());
  BOOST_TEST(a.diagnostic_infos().size() != 4U);
  BOOST_TEST(a.diagnostic_infos().at(0) != common::make_diagnostic_info_2());
  BOOST_TEST(a.diagnostic_infos().at(1) != common::make_diagnostic_info_1());
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_browse_response_1();
  auto a1 = common::make_browse_response_1();
  auto b = common::make_browse_response_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

BOOST_AUTO_TEST_CASE(test_stream_operator) {
  //  auto s =
  //      "BrowseResponse(ResponseHeader(DateTime(0), 31, "
  //      "[\"string-table-entry-1\", \"string-table-entry-2\"], "
  //      "ExtensionObject(ExtensionObjectEncoding::Nobody, NodeId(0, 1234, "
  //      "IdentifierType::Numeric), \"this-is-byte-string-content\")), "
  //      "[BrowseResult(StatusCode::BadShutdown, \"xyz-1234\", "
  //      "[ReferenceDescription(NodeId(0, Guid(\"\"), IdentifierType::Guid), "
  //      "false, ExpandedNodeId(NodeId(0, Guid(\"\"), IdentifierType::Guid), "
  //      "\"\", 0), QualifiedName(\"\", 0), LocalizedText(Locale(\"\"), "
  //      "Text(\"\")), NodeClass::Unspecified, ExpandedNodeId(NodeId(0, "
  //      "Guid(\"\"), IdentifierType::Guid), \"\", 0)), "
  //      "ReferenceDescription(NodeId(0, Guid(\"\"), IdentifierType::Guid), "
  //      "false, ExpandedNodeId(NodeId(0, Guid(\"\"), IdentifierType::Guid), "
  //      "\"\", 0), QualifiedName(\"\", 0), LocalizedText(Locale(\"\"), "
  //      "Text(\"\")), NodeClass::Unspecified, ExpandedNodeId(NodeId(0, "
  //      "Guid(\"\"), IdentifierType::Guid), \"\", 0))]), "
  //      "BrowseResult(StatusCode::GoodNoData, \"adbcd\", "
  //      "[ReferenceDescription(NodeId(0, Guid(\"\"), IdentifierType::Guid), "
  //      "false, ExpandedNodeId(NodeId(0, Guid(\"\"), IdentifierType::Guid), "
  //      "\"\", 0), QualifiedName(\"\", 0), LocalizedText(Locale(\"\"), "
  //      "Text(\"\")), NodeClass::Unspecified, ExpandedNodeId(NodeId(0, "
  //      "Guid(\"\"), IdentifierType::Guid), \"\", 0))])],
  //      [DiagnosticInfo(true, " "false, true, false, true, false, 1, 2, 3, 4,
  //      \"additional-info\", " "StatusCode::Good), DiagnosticInfo(true, true,
  //      false, true, false, true, " "1, 22, 33, 44, \"more-additional-info\",
  //      StatusCode::Good)])";

  auto s =
      "BrowseResponse(ResponseHeader(DateTime(0), 31, "
      "[\"string-table-entry-1\", \"string-table-entry-2\"], "
      "ExtensionObject(ExtensionObjectEncoding::Nobody, NodeId(0, 1234, "
      "IdentifierType::Numeric), \"this-is-byte-string-content\")), "
      "[BrowseResult(StatusCode::BadShutdown, \"xyz-1234\", "
      "[ReferenceDescription(NodeId(0, 1234, IdentifierType::Numeric), true, "
      "ExpandedNodeId(NodeId(0, 1234, IdentifierType::Numeric), "
      "\"ns:test:uri:1234\", 2), QualifiedName(\"qualified-name-1\", 3), "
      "LocalizedText(Locale(\"en\"), Text(\"text-en\")), NodeClass::Variable, "
      "ExpandedNodeId(NodeId(4, \"my-node\", IdentifierType::String), "
      "\"ns:test:uri:5678\", 3)), ReferenceDescription(NodeId(4, \"my-node\", "
      "IdentifierType::String), false, ExpandedNodeId(NodeId(4, \"my-node\", "
      "IdentifierType::String), \"ns:test:uri:5678\", 3), "
      "QualifiedName(\"qualified-name-2\", 1), LocalizedText(Locale(\"de\"), "
      "Text(\"text-de\")), NodeClass::Method, ExpandedNodeId(NodeId(0, 1234, "
      "IdentifierType::Numeric), \"ns:test:uri:1234\", 2))]), "
      "BrowseResult(StatusCode::GoodNoData, \"adbcd\", "
      "[ReferenceDescription(NodeId(4, \"my-node\", IdentifierType::String), "
      "false, ExpandedNodeId(NodeId(4, \"my-node\", IdentifierType::String), "
      "\"ns:test:uri:5678\", 3), QualifiedName(\"qualified-name-2\", 1), "
      "LocalizedText(Locale(\"de\"), Text(\"text-de\")), NodeClass::Method, "
      "ExpandedNodeId(NodeId(0, 1234, IdentifierType::Numeric), "
      "\"ns:test:uri:1234\", 2))])], [DiagnosticInfo(true, false, true, false, "
      "true, false, 1, 2, 3, 4, \"additional-info\", StatusCode::Good), "
      "DiagnosticInfo(true, true, false, true, false, true, 1, 22, 33, 44, "
      "\"more-additional-info\", StatusCode::Good)])";

  auto a = common::make_browse_response_1();
  std::stringstream ss;
  ss << a;
  BOOST_TEST(s == ss.str());
  auto s_not = "not";
  BOOST_TEST(s_not != ss.str());
}

#pragma clang diagnostic pop
