#define BOOST_TEST_MODULE "open62541_cpp_wrapper"

#include <boost/test/included/unit_test.hpp>

#include <nlohmann/json.hpp>
#include "open62541.h"

#include "applicationdescription.hpp"
#include "parser.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;
using namespace nlohmann;

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

ApplicationDescription make_application_description_1() {
  std::string application_uri = "app:uri:test:123";
  std::string product_uri = "prod:uri:test:456";
  LocalizedText application_name =
      LocalizedText(Locale("en"), Text("app-test-name"));
  ApplicationType application_type = ApplicationType::Client;
  std::string gateway_server_uri = "gateway:server:uri";
  std::string discovery_profile_uri = "discovery:profile:uri";
  std::vector<std::string> discovery_urls = {"url-1", "url-2"};

  return ApplicationDescription(application_uri,
                                product_uri,
                                application_name,
                                application_type,
                                gateway_server_uri,
                                discovery_profile_uri,
                                discovery_urls);
}

BOOST_AUTO_TEST_CASE(test_constructor) {
  auto a = make_application_description_1();

  BOOST_TEST(a.application_uri() == "app:uri:test:123");
  BOOST_TEST(a.product_uri() == "prod:uri:test:456");
  BOOST_TEST(a.application_name() ==
             LocalizedText(Locale("en"), Text("app-test-name")));
  BOOST_TEST(a.application_type() == ApplicationType::Client);
  BOOST_TEST(a.gateway_server_uri() == "gateway:server:uri");
  BOOST_TEST(a.discovery_profile_uri() == "discovery:profile:uri");
  //  BOOST_TEST(a.discovery_urls() == discovery_urls);
  //  "url-1", "url-2";
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {
  std::string application_uri = "app:uri:test:123";
  std::string product_uri = "prod:uri:test:456";
  LocalizedText application_name =
      LocalizedText(Locale("en"), Text("app-test-name"));
  ApplicationType application_type = ApplicationType::Client;
  std::string gateway_server_uri = "gateway:server:uri";
  std::string discovery_profile_uri = "discovery:profile:uri";
  std::vector<std::string> discovery_urls = {"url-1", "url-2"};

  auto a = ApplicationDescription(application_uri,
                                  product_uri,
                                  application_name,
                                  application_type,
                                  gateway_server_uri,
                                  discovery_profile_uri,
                                  discovery_urls);
}

#pragma clang diagnostic pop
