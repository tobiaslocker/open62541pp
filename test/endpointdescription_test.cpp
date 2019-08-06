#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "endpointdescription.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_CASE(test_move_constructor) {
  EndpointDescription a;
  EndpointDescription b(std::move(a));
}

BOOST_AUTO_TEST_CASE(test_move_assignment) {
  EndpointDescription a;
  EndpointDescription b;
  b = std::move(a);
}

BOOST_AUTO_TEST_CASE(test_copy_constructor) {
  EndpointDescription a;
  EndpointDescription b(a);
}

BOOST_AUTO_TEST_CASE(test_copy_assignment) {
  EndpointDescription a;
  EndpointDescription b;
  b = a;
}

BOOST_AUTO_TEST_CASE(test_default_constructor) {
  EndpointDescription const a;
  BOOST_TEST(a.endpoint_url().empty());
  BOOST_TEST(a.server().empty());
  BOOST_TEST(a.server_certificate().empty());
  BOOST_TEST(a.security_mode() == MessageSecurityMode::None);
  BOOST_TEST(a.security_policy_uri().empty());
  BOOST_TEST(a.user_identity_tokens().empty());
  BOOST_TEST(a.transport_profile_uri().empty());
  BOOST_TEST(a.security_level() == 0);
  BOOST_TEST(a.empty());
}

EndpointDescription make_endpoint_description_1() {
  return EndpointDescription();
}

// EndpointDescription make_application_description_2() {
//  std::string application_uri = "app:uri:test:123:different";
//  std::string product_uri = "prod:uri:test:456:different";
//  LocalizedText application_name =
//      LocalizedText(Locale("de"), Text("app-test-name:different"));
//  EndpointType application_type = EndpointType::Client;
//  std::string gateway_server_uri = "gateway:server:uri:different";
//  std::string discovery_profile_uri = "discovery:profile:uri:different";
//  std::vector<std::string> discovery_urls = {"url-1:different",
//                                             "url-2:different"};

//  return EndpointDescription(application_uri,
//                                product_uri,
//                                application_name,
//                                application_type,
//                                gateway_server_uri,
//                                discovery_profile_uri,
//                                discovery_urls);
//}

BOOST_AUTO_TEST_CASE(test_constructor) {
  //  auto a = make_application_description_1();

  //  BOOST_TEST(!a.empty());
  //  BOOST_TEST(a.application_uri() == "app:uri:test:123");
  //  BOOST_TEST(a.product_uri() == "prod:uri:test:456");
  //  BOOST_TEST(a.application_name() ==
  //             LocalizedText(Locale("en"), Text("app-test-name")));
  //  BOOST_TEST(a.application_type() == EndpointType::Client);
  //  BOOST_TEST(a.gateway_server_uri() == "gateway:server:uri");
  //  BOOST_TEST(a.discovery_profile_uri() == "discovery:profile:uri");
  //  BOOST_TEST(a.discovery_urls().size() == 2U);
  //  BOOST_TEST(a.discovery_urls().at(0) == "url-1");

  //  BOOST_TEST(a.discovery_urls().at(1) != "url-2-not");
  //  BOOST_TEST(a.application_uri() != "app:uri:test:123-not");
  //  BOOST_TEST(a.product_uri() != "prod:uri:test:456-not");
  //  BOOST_TEST(a.application_name() !=
  //             LocalizedText(Locale("en-not"), Text("app-test-name-not")));
  //  BOOST_TEST(a.application_type() != EndpointType::Server);
  //  BOOST_TEST(a.gateway_server_uri() != "gateway:server:uri-not");
  //  BOOST_TEST(a.discovery_profile_uri() != "discovery:profile:uri-not");
  //  BOOST_TEST(a.discovery_urls().size() != 1U);
  //  BOOST_TEST(a.discovery_urls().at(0) != "url-1-not");
  //  BOOST_TEST(a.discovery_urls().at(1) != "url-2-not");
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  //  auto a = make_application_description_1();
  //  auto a1 = make_application_description_1();
  //  auto b = make_application_description_2();
  //  BOOST_TEST(a != b);
  //  BOOST_TEST(a == a1);
}

#pragma clang diagnostic pop
