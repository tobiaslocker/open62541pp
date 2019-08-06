#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "common.hpp"
#include "applicationdescription.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  ApplicationDescription a;
  ApplicationDescription b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  ApplicationDescription a;
  ApplicationDescription b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  ApplicationDescription a;
  ApplicationDescription b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  ApplicationDescription a;
  ApplicationDescription b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  ApplicationDescription const a_empty;
  BOOST_TEST(a_empty.empty());
  BOOST_TEST(a_empty.application_uri().empty());
  BOOST_TEST(a_empty.product_uri().empty());
  BOOST_TEST(a_empty.application_name().empty());
  BOOST_TEST(a_empty.application_type() == ApplicationType::Server);
  BOOST_TEST(a_empty.gateway_server_uri().empty());
  BOOST_TEST(a_empty.discovery_profile_uri().empty());
  BOOST_TEST(a_empty.discovery_urls().empty());
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto a = common::make_application_description_1();

  BOOST_TEST(!a.empty());
  BOOST_TEST(a.application_uri() == "app:uri:test:123");
  BOOST_TEST(a.product_uri() == "prod:uri:test:456");
  BOOST_TEST(a.application_name() ==
             LocalizedText(Locale("en"), Text("app-test-name")));
  BOOST_TEST(a.application_type() == ApplicationType::Client);
  BOOST_TEST(a.gateway_server_uri() == "gateway:server:uri");
  BOOST_TEST(a.discovery_profile_uri() == "discovery:profile:uri");
  BOOST_TEST(a.discovery_urls().size() == 2U);
  BOOST_TEST(a.discovery_urls().at(0) == "url-1");

  BOOST_TEST(a.discovery_urls().at(1) != "url-2-not");
  BOOST_TEST(a.application_uri() != "app:uri:test:123-not");
  BOOST_TEST(a.product_uri() != "prod:uri:test:456-not");
  BOOST_TEST(a.application_name() !=
             LocalizedText(Locale("en-not"), Text("app-test-name-not")));
  BOOST_TEST(a.application_type() != ApplicationType::Server);
  BOOST_TEST(a.gateway_server_uri() != "gateway:server:uri-not");
  BOOST_TEST(a.discovery_profile_uri() != "discovery:profile:uri-not");
  BOOST_TEST(a.discovery_urls().size() != 1U);
  BOOST_TEST(a.discovery_urls().at(0) != "url-1-not");
  BOOST_TEST(a.discovery_urls().at(1) != "url-2-not");
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  auto a = common::make_application_description_1();
  auto a1 = common::make_application_description_1();
  auto b = common::make_application_description_2();
  BOOST_TEST(a != b);
  BOOST_TEST(a == a1);
}

#pragma clang diagnostic pop
