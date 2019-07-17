#include <iostream>
#include "client.hpp"
//#include "base64.hpp"

using namespace open62541;

int main() {
  std::string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";

  Client client;
  client.connect(url);

  auto endpoints = client.get_endpoints(url);

  for (auto const &ep : endpoints) {
    //      auto b = base64::to_base64(ep.server_certificate());

    //      std::cout << b << '\n';

    std::cout << "Endpoint url: " << ep.endpoint_url();
    std::cout << "Security Mode" << ep.security_mode();
    auto s = ep.server();
    std::cout << "Server application uri: " << s.application_uri() << '\n';
    std::cout << "Server product uri: " << s.product_uri() << '\n';
  }
}
