#define BOOST_TEST_MODULE "open62541_cpp_wrapper"

#include <boost/test/included/unit_test.hpp>

#include <nlohmann/json.hpp>
#include "open62541.hpp"

#include "applicationdescription.hpp"
#include "endpointdescription.hpp"

#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;
using namespace nlohmann;


BOOST_AUTO_TEST_CASE(test_endpoint_description) {
  const char *PRODUCT_URI = "http://open62541.org";
  const char *APPLICATION_NAME = "open62541-based OPC UA Application";
  const char *APPLICATION_URI = "urn:unconfigured:application";
  const char *DISCOVERY_PROFILE_URI = "urn:unconfigured:profile:uri";
  const char *GATEWAY_SERVER_URI = "urn:unconfigured:gateway:server:uri";
  const char *DISCOVERY_URL_1 = "opc.tcp://discovery-url-1:0000/Test";
  const char *DISCOVERY_URL_2 = "opc.tcp://discovery-url-2:0000/Test";
  const char *DISCOVERY_URL_3 = "opc.tcp://discovery-url-3:0000/Test";
  const char *ENDPOINT_URL = "opc.tcp://endpoint-url:0000/Test";
  const char *SECURITY_POLICY_URI = "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15";
  const char *TRANSPORT_PROFILE_URI = "http://opcfoundation.org/UA/profiles/transport/wsxmlorbinary";

  UA_ApplicationDescription server;
  server.productUri = UA_STRING_ALLOC(PRODUCT_URI);
  server.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", APPLICATION_NAME);
  server.applicationUri = UA_STRING_ALLOC(APPLICATION_URI);
  server.applicationType = UA_APPLICATIONTYPE_SERVER;
  server.gatewayServerUri = UA_STRING_ALLOC(GATEWAY_SERVER_URI);
  server.discoveryProfileUri = UA_STRING_ALLOC(DISCOVERY_PROFILE_URI);

  UA_String arr[3];
  arr[0] = UA_STRING_ALLOC(DISCOVERY_URL_1);
  arr[1] = UA_STRING_ALLOC(DISCOVERY_URL_2);
  arr[2] = UA_STRING_ALLOC(DISCOVERY_URL_3);

  server.discoveryUrlsSize = 3;
  server.discoveryUrls = arr;

  UA_EndpointDescription ua_desc;
  ua_desc.server = server;
  ua_desc.endpointUrl = UA_STRING_ALLOC(ENDPOINT_URL);
  ua_desc.securityMode = UA_MESSAGESECURITYMODE_NONE;
  ua_desc.securityLevel = 'a';
  ua_desc.securityPolicyUri = UA_STRING_ALLOC(SECURITY_POLICY_URI);
  ua_desc.userIdentityTokens = nullptr;
  ua_desc.userIdentityTokensSize = 0;
  ua_desc.transportProfileUri = UA_STRING_ALLOC(TRANSPORT_PROFILE_URI);

  auto desc = EndpointDescription(ua_desc);
  auto endpoint_url = desc.endpoint_url();

  desc.server();
  desc.security_mode();
  desc.security_level();
  desc.security_policy_uri();
  desc.user_identity_tokens();
  desc.transport_profile_uri();



  BOOST_TEST(endpoint_url == ENDPOINT_URL);
//  BOOST_TEST(true);
}

//BOOST_AUTO_TEST_CASE(node_id_test) { BOOST_TEST(true); }

#pragma clang diagnostic pop
