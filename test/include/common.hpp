#ifndef COMMON_H
#define COMMON_H

#include "applicationdescription.hpp"
#include "browsedescription.hpp"
#include "browserequest.hpp"
#include "datetime.hpp"
#include "endpointdescription.hpp"
#include "nodeid.hpp"
#include "requestheader.hpp"
#include "viewdescription.hpp"

namespace common {

using namespace open62541;

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

ApplicationDescription make_application_description_2() {
  return ApplicationDescription(
      "app:uri:test:123:different",
      "prod:uri:test:456:different",
      LocalizedText(Locale("de"), Text("app-test-name:different")),
      ApplicationType::Client,
      "gateway:server:uri:different",
      "discovery:profile:uri:different",
      {"url-1:different", "url-2:different"});
}

UserTokenPolicy make_user_token_policy_1() {
  return UserTokenPolicy("1",
                         UserTokenType::Anonymous,
                         "issued-token-type-1",
                         "opc.tcp://issuer-endpoint.com:51210/url",
                         "http://opcfoundation.org/UA/SecurityPolicy#None");
}

UserTokenPolicy make_user_token_policy_2() {
  return UserTokenPolicy("2",
                         UserTokenType::Certificate,
                         "issued-token-type-2",
                         "opc.tcp://issuer-endpoint.com:51210/url-2",
                         "http://opcfoundation.org/UA/SecurityPolicy#Basic256");
}

EndpointDescription make_endpoint_description_1() {
  auto server = make_application_description_1();
  return EndpointDescription(
      "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer",
      server,
      "cert",
      MessageSecurityMode::SignAndEncrypt,
      "http://opcfoundation.org/UA/SecurityPolicy#Basic256",
      std::vector<UserTokenPolicy>(
          {make_user_token_policy_1(), make_user_token_policy_2()}),
      "http://opcfoundation.org/UA-Profile/Transport/https-uabinary",
      0);
}

EndpointDescription make_endpoint_description_2() {
  auto server = make_application_description_2();
  return EndpointDescription(
      "opc.tcp://opcua.demo-this.com:51210/UA/SampleServerDifferent",
      server,
      "cert-different",
      MessageSecurityMode::SignAndEncrypt,
      "http://opcfoundation.org/UA/SecurityPolicy#Basic128",
      std::vector<UserTokenPolicy>({make_user_token_policy_2()}),
      "http://opcfoundation.org/UA-Profile/Transport/https-uabinary-different",
      2);
}

NodeId make_node_id_1() {
  return NodeId(0, Identifier(1234), IdentifierType::Numeric);
}

NodeId make_node_id_2() {
  return NodeId(4, Identifier("my-node"), IdentifierType::String);
}

BrowseDescription make_browse_description_1() {
  return BrowseDescription(
      make_node_id_2(), BrowseDirection::Forward, make_node_id_1(), true, 0, 0);
}

BrowseDescription make_browse_description_2() {
  return BrowseDescription(
      make_node_id_1(), BrowseDirection::Inverse, make_node_id_2(), true, 3, 4);
}

DateTime make_date_time_1() {
  // Date and time (GMT): Thursday, August 8, 2019 7:26:35 PM
  int64_t t = 132097659950000000;
  return DateTime(t);
}

ViewDescription make_view_desccription_1() {
  return ViewDescription(make_node_id_1(), make_date_time_1(), 42);
}

RequestHeader make_request_header_1() {
  return RequestHeader(
      make_node_id_1(), make_date_time_1(), 7, 13, "this-audit-entry", 1888)
}

//(NodeId const &authentication_token,
//               DateTime const &timestamp,
//               uint32_t const &request_handle,}
//               uint32_t const &return_diagnostics,
//               std::string const &audit_entry_id,
//               uint32_t const &timeout_hint,
//               ExtensionObject const &additional_header);

}  // namespace common

#endif  // COMMON_H
