#define BOOST_TEST_MODULE VsidCommonTest
#include <boost/test/included/unit_test.hpp>

#include "open62541.hpp"

#include "applicationdescription.hpp"

#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace open62541;

BOOST_AUTO_TEST_SUITE( all )

BOOST_AUTO_TEST_CASE( test_application_description ) {
    const char * PRODUCT_URI = "http://open62541.org";
    const char * APPLICATION_NAME = "open62541-based OPC UA Application";
    const char * APPLICATION_URI = "urn:unconfigured:application";
    const char * DISCOVERY_PROFILE_URI = "urn:unconfigured:profile:uri";
    const char * GATEWAY_SERVER_URI = "urn:unconfigured:gateway:server:uri";

    UA_ApplicationDescription ua_desc;
    ua_desc.productUri = UA_STRING_ALLOC(PRODUCT_URI);
    ua_desc.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", APPLICATION_NAME);
    ua_desc.applicationUri = UA_STRING_ALLOC(APPLICATION_URI);
    ua_desc.applicationType = UA_APPLICATIONTYPE_SERVER;
    ua_desc.gatewayServerUri = UA_STRING_ALLOC(GATEWAY_SERVER_URI);
    ua_desc.discoveryProfileUri = UA_STRING_ALLOC(DISCOVERY_PROFILE_URI);
    ua_desc.discoveryUrlsSize = 0;
    ua_desc.discoveryUrls = nullptr;

    auto desc = ApplicationDescription(ua_desc);
    auto product_uri = desc.product_uri();
    auto application_name_text = desc.application_name().text();
    auto application_name_locale = desc.application_name().locale();
    auto application_type = desc.application_type();
    auto gateway_server_uri = desc.gateway_server_uri();
    auto discovery_profile_uri = desc.discovery_profile_uri();

    BOOST_TEST(product_uri == PRODUCT_URI);
    BOOST_TEST(application_name_text == APPLICATION_NAME);
    BOOST_TEST(application_name_locale == "en");
    BOOST_CHECK(application_type == ApplicationType::Server);
    BOOST_CHECK(application_type != ApplicationType::Client);
    BOOST_TEST(gateway_server_uri == GATEWAY_SERVER_URI);
    BOOST_TEST(discovery_profile_uri == DISCOVERY_PROFILE_URI);
    BOOST_TEST(desc.discovery_urls().size() == 0U);
}

BOOST_AUTO_TEST_CASE( node_id_test ) {
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END()
#pragma clang diagnostic pop
