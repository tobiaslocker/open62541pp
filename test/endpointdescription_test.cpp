#define BOOST_TEST_MODULE "open62541pp"

#include <boost/test/included/unit_test.hpp>

#include "common.hpp"
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

ApplicationDescription make_application_description_1() {
  return ApplicationDescription(
      "app:uri:test:123",
      "prod:uri:test:456",
      LocalizedText(Locale("en"), Text("app-test-name")),
      ApplicationType::Client,
      "gateway:server:uri",
      "discovery:profile:uri",
      {"url-1", "url-2"});
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

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto e = common::make_endpoint_description_1();
  BOOST_TEST(!e.empty());

  auto server = common::make_application_description_1();
  BOOST_TEST(e.endpoint_url() ==
             "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer");
  BOOST_TEST(e.server() == server);
  BOOST_TEST(e.server_certificate() == "cert");
  BOOST_TEST(e.security_mode() == MessageSecurityMode::SignAndEncrypt);
  BOOST_TEST(e.security_policy_uri() ==
             "http://opcfoundation.org/UA/SecurityPolicy#Basic256");
  BOOST_TEST(e.user_identity_tokens() == std::vector<UserTokenPolicy>());
  BOOST_TEST(e.transport_profile_uri() ==
             "http://opcfoundation.org/UA-Profile/Transport/https-uabinary");
  BOOST_TEST(e.security_level() == 0);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  //  auto a = make_application_description_1();
  //  auto a1 = make_application_description_1();
  //  auto b = make_application_description_2();
  //  BOOST_TEST(a != b);
  //  BOOST_TEST(a == a1);
}

#pragma clang diagnostic pop
