#include <iomanip>
#include <iostream>
#include "client.hpp"

using namespace open62541;
using namespace std;

struct EventHandler : public ClientEventHandler {
  void on_state_changed(ClientState state) override {
    cout << "Hello from Handler!\n";
  }

  void on_subscription_inactivity(u_int32_t id) override {
    cout << "Hello from Handler!\n";
  }

  void on_inactivity(ClientState state) override {
    cout << "Hello from Handler!\n";
  }
};

int main() {
  string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";
  auto handler = std::make_unique<EventHandler>();
  Client client(std::move(handler));
  client.connect(url);
  auto endpoints = client.get_endpoints(url);
}
