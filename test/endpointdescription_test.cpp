#define BOOST_TEST_MODULE "open62541_cpp_wrapper"

#include <boost/test/included/unit_test.hpp>

#include <nlohmann/json.hpp>
#include "open62541.h"

#include "parser.hpp"
#include "applicationdescription.hpp"
#include "endpointdescription.hpp"
#include "common.hpp"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;
using namespace nlohmann;

BOOST_AUTO_TEST_CASE(test_endpoint_description) {
//  auto ua_server = common::make_ua_application_description();
//  auto app_desc = parser::from_open62541(ua_server);
//  auto ua_endpoint_desc = common::make_endpoint_description();
//  auto endpoint = parser::from_open62541(ua_endpoint_desc);

    auto a = UA_ApplicationDescription_new();
    UA_ApplicationDescription_init(a);
  auto app_desc = parser::from_open62541(*a);


  BOOST_TEST_MESSAGE("Hello Test");
//  BOOST_TEST_MESSAGE("Endpoint url: " + parser::from_open62541(ua_desc.endpointUrl));
//  auto desc = parser::from_open62541(ua_desc);
//  auto test_tokens = std::vector<UserTokenPolicy>();
//  UA_UserTokenPolicy policy1;
//  test_tokens.push_back(parser::from_open62541(policy1));
//  auto a = parser::from_open62541(common::make_ua_application_description());
//  BOOST_TEST(desc.endpoint_url() == common::endpoint_url);
//  BOOST_TEST(desc.security_policy_uri() == common::security_policy_uri);
//  BOOST_TEST(desc.transport_profile_uri() == common::transport_profile_uri);
////  BOOST_REQUIRE_EQUAL_COLLECTIONS(user_identity_tokens.begin(),
////                                  user_identity_tokens.end(),
////                                  test_tokens.begin(),
////                                  test_tokens.end());

//  BOOST_CHECK_EQUAL(desc.server(), a);
//  BOOST_REQUIRE(desc.security_mode() == MessageSecurityMode::None);
//  BOOST_TEST(desc.security_level() == 'a');
}

BOOST_AUTO_TEST_CASE(test_another_test) {
    BOOST_TEST(true);

}

#pragma clang diagnostic pop
