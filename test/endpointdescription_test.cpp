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


//UA_ApplicationDescription make_ua_application_description() {

//  const char *product_uri = "http://open62541.org";
//  const char *application_name = "open62541-based OPC UA Application";
//  const char *application_uri = "urn:unconfigured:application";
//  const char *discovery_profile_uri = "urn:unconfigured:profile:uri";
//  const char *gateway_server_uri = "urn:unconfigured:gateway:server:uri";
//  const char *discovery_url_1 = "opc.tcp://discovery-url-1:0000/Test";
//  const char *discovery_url_2 = "opc.tcp://discovery-url-2:0000/Test";
//  const char *discovery_url_3 = "opc.tcp://discovery-url-3:0000/Test";

//  UA_ApplicationDescription ua_server;
//  ua_server.productUri = UA_STRING_ALLOC(product_uri);
//  ua_server.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", application_name);
//  ua_server.applicationUri = UA_STRING_ALLOC(application_uri);
//  ua_server.applicationType = UA_APPLICATIONTYPE_SERVER;
//  ua_server.gatewayServerUri = UA_STRING_ALLOC(gateway_server_uri);
//  ua_server.discoveryProfileUri = UA_STRING_ALLOC(discovery_profile_uri);
//  UA_String arr[3];
//  arr[0] = UA_STRING_ALLOC(discovery_url_1);
//  arr[1] = UA_STRING_ALLOC(discovery_url_2);
//  arr[2] = UA_STRING_ALLOC(discovery_url_3);
//  ua_server.discoveryUrlsSize = 3;
//  ua_server.discoveryUrls = arr;
//  return ua_server;
//};

BOOST_AUTO_TEST_CASE(test_endpoint_description) {

//  const char *product_uri = "http://open62541.org";
//  const char *application_name = "open62541-based OPC UA Application";
//  const char *application_uri = "urn:unconfigured:application";
//  const char *discovery_profile_uri = "urn:unconfigured:profile:uri";
//  const char *gateway_server_uri = "urn:unconfigured:gateway:server:uri";
//  const char *discovery_url_1 = "opc.tcp://discovery-url-1:0000/Test";
//  const char *discovery_url_2 = "opc.tcp://discovery-url-2:0000/Test";
//  const char *discovery_url_3 = "opc.tcp://discovery-url-3:0000/Test";

//  UA_ApplicationDescription ua_server;
//  ua_server.productUri = UA_STRING_ALLOC(product_uri);
//  ua_server.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", application_name);
//  ua_server.applicationUri = UA_STRING_ALLOC(application_uri);
//  ua_server.applicationType = UA_APPLICATIONTYPE_SERVER;
//  ua_server.gatewayServerUri = UA_STRING_ALLOC(gateway_server_uri);
//  ua_server.discoveryProfileUri = UA_STRING_ALLOC(discovery_profile_uri);
//  UA_String arr[3];
//  arr[0] = UA_STRING_ALLOC(discovery_url_1);
//  arr[1] = UA_STRING_ALLOC(discovery_url_2);
//  arr[2] = UA_STRING_ALLOC(discovery_url_3);
//  ua_server.discoveryUrlsSize = 3;
//  ua_server.discoveryUrls = arr;


    auto ua_server = common::make_ua_application_description();



  auto app_desc = parser::from_open62541(ua_server);

  const char *endpoint_url = "opc.tcp://endpoint-url:0000/Test";
  const char *security_policy_uri =
      "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15";
  const char *transport_profile_uri =
      "http://opcfoundation.org/UA/profiles/transport/wsxmlorbinary";
  const char *server_certificate = "this-is-a-server-cert";
  UA_EndpointDescription res;
  res.server = ua_server;
  res.endpointUrl = UA_STRING_ALLOC(endpoint_url);
  res.securityMode = UA_MESSAGESECURITYMODE_NONE;
  res.securityLevel = 'a';
  res.securityPolicyUri = UA_STRING_ALLOC(security_policy_uri);
  res.userIdentityTokens = nullptr;
  res.userIdentityTokensSize = 0;
  res.transportProfileUri = UA_STRING_ALLOC(transport_profile_uri);
  res.serverCertificate = UA_STRING_ALLOC(server_certificate);

  auto ua_endpoint_desc = common::make_endpoint_description();

//  auto endpoint = parser::from_open62541(ua_endpoint_desc);
  auto endpoint = parser::from_open62541(res);




//  BOOST_TEST_MESSAGE("Hello Test");
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

#pragma clang diagnostic pop
