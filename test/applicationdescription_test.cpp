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
  std::string application_uri = "app:uri:test:123";
  std::string product_uri = "prod:uri:test:456";
  LocalizedText application_name =
      LocalizedText(Locale("en"), Text("app-test-name"));
  ApplicationType application_type = ApplicationType::Client;
  std::string gateway_server_uri = "gateway:server:uri";
  std::string discovery_profile_uri = "discovery:profile:uri";
  std::vector<std::string> discovery_urls = {"url-1", "url-2"};

  auto ad = ApplicationDescription(application_uri,
                                   product_uri,
                                   application_name,
                                   application_type,
                                   gateway_server_uri,
                                   discovery_profile_uri,
                                   discovery_urls);

  BOOST_TEST(ad.application_uri() == application_uri);
  BOOST_TEST(ad.product_uri() == product_uri);
  BOOST_TEST(ad.application_name() == application_name);
  BOOST_TEST(ad.application_type() == application_type);
  BOOST_TEST(ad.gateway_server_uri() == gateway_server_uri);
  BOOST_TEST(ad.discovery_profile_uri() == discovery_profile_uri);
  BOOST_TEST(ad.discovery_urls() == discovery_urls);
}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {}

#pragma clang diagnostic pop
