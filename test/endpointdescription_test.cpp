#define BOOST_TEST_MODULE "open62541_cpp_wrapper"

#include <boost/test/included/unit_test.hpp>

#include <nlohmann/json.hpp>
#include "open62541.h"

#include "parser.hpp"

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
    const char *SECURITY_POLICY_URI =
        "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15";
    const char *TRANSPORT_PROFILE_URI =
        "http://opcfoundation.org/UA/profiles/transport/wsxmlorbinary";
    const char *SERVER_CERTIFICATE = "this-is-a-server-cert";

    UA_ApplicationDescription server_;
    server_.productUri = UA_STRING_ALLOC(PRODUCT_URI);
    server_.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", APPLICATION_NAME);
    server_.applicationUri = UA_STRING_ALLOC(APPLICATION_URI);
    server_.applicationType = UA_APPLICATIONTYPE_SERVER;
    server_.gatewayServerUri = UA_STRING_ALLOC(GATEWAY_SERVER_URI);
    server_.discoveryProfileUri = UA_STRING_ALLOC(DISCOVERY_PROFILE_URI);

    UA_String arr[3];
    arr[0] = UA_STRING_ALLOC(DISCOVERY_URL_1);
    arr[1] = UA_STRING_ALLOC(DISCOVERY_URL_2);
    arr[2] = UA_STRING_ALLOC(DISCOVERY_URL_3);

    server_.discoveryUrlsSize = 3;
    server_.discoveryUrls = arr;

    UA_EndpointDescription ua_desc;
    ua_desc.server = server_;
    ua_desc.endpointUrl = UA_STRING_ALLOC(ENDPOINT_URL);
    ua_desc.securityMode = UA_MESSAGESECURITYMODE_NONE;
    ua_desc.securityLevel = 'a';
    ua_desc.securityPolicyUri = UA_STRING_ALLOC(SECURITY_POLICY_URI);
    ua_desc.userIdentityTokens = nullptr;
    ua_desc.userIdentityTokensSize = 0;
    ua_desc.transportProfileUri = UA_STRING_ALLOC(TRANSPORT_PROFILE_URI);
    ua_desc.serverCertificate = UA_STRING_ALLOC(SERVER_CERTIFICATE);

    auto desc = parser::from_open62541(ua_desc);
    auto endpoint_url = desc.endpoint_url();

    auto server = desc.server();
    auto security_mode = desc.security_mode();
    auto security_level = desc.security_level();
    auto security_policy_uri = desc.security_policy_uri();
    auto user_identity_tokens = desc.user_identity_tokens();
    auto transport_profile_uri = desc.transport_profile_uri();

    auto test_tokens = std::vector<UserTokenPolicy>();

//    UA_UserTokenPolicy policy1;
//    test_tokens.push_back(parser::from_open62541(policy1));

    auto a = parser::from_open62541(server_);

    BOOST_TEST(endpoint_url == ENDPOINT_URL);
    BOOST_TEST(security_policy_uri == SECURITY_POLICY_URI);
    BOOST_TEST(transport_profile_uri == TRANSPORT_PROFILE_URI);
//    BOOST_REQUIRE_EQUAL_COLLECTIONS(user_identity_tokens.begin(),
//                                    user_identity_tokens.end(),
//                                    test_tokens.begin(),
//                                    test_tokens.end());


    BOOST_TEST_MESSAGE("Huuuuu Huuuuuuu");
    BOOST_CHECK_EQUAL(server, a);
    BOOST_REQUIRE(security_mode == MessageSecurityMode::None);
    BOOST_TEST(security_level == 'a');
}

#pragma clang diagnostic pop
