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
  std::string m_product_uri = "prod:uri:test:456";
  LocalizedText m_application_name = LocalizedText("en", "app-test-name");
  ApplicationType m_application_type;
  std::string m_gateway_server_uri;
  std::string m_discovery_profile_uri;
  std::vector<std::string> m_discovery_urls;

}

BOOST_AUTO_TEST_CASE(test_comparison_operators) {

}



#pragma clang diagnostic pop
