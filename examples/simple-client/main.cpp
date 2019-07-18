#include <iomanip>
#include <iostream>
#include "client.hpp"

using namespace open62541;
using namespace std;

int main() {
  string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";

  Client client;
  client.connect(url);

  auto endpoints = client.get_endpoints(url);

  //  for (auto const &ep : endpoints) {
  //    cout << left << setw(25) << "Endpoint url: " << ep.endpoint_url() <<
  //    '\n'; cout << left << setw(25) << "Security mode: " <<
  //    ep.security_mode() << '\n'; cout << left << setw(25)
  //         << "Security policy uri: " << ep.security_policy_uri() << '\n';
  //    auto s = ep.server();
  //    cout << left << setw(25)
  //         << "Server application uri: " << s.application_uri() << '\n';
  //    cout << left << setw(25) << "Server product uri: " << s.product_uri()
  //         << '\n';
  //    cout << '\n';
  //  }
}
