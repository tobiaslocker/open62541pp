#ifndef COMMON_H
#define COMMON_H

#include "applicationdescription.hpp"
#include "endpointdescription.hpp"

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

EndpointDescription make_endpoint_description_1() {
  auto server = make_application_description_1();
  return EndpointDescription(
      "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer",
      server,
      "cert",
      MessageSecurityMode::SignAndEncrypt,
      "http://opcfoundation.org/UA/SecurityPolicy#Basic256",
      std::vector<UserTokenPolicy>(),
      "http://opcfoundation.org/UA-Profile/Transport/https-uabinary",
      0);
}

}  // namespace common

#endif  // COMMON_H
