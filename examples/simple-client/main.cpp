#include "client.hpp"

using namespace open62541;

struct EventHandler : public ClientEventHandler {
  void on_state_changed(ClientState state) override {
    // ...
  }

  void on_subscription_inactivity(u_int32_t id) override {
    // ...
  }

  void on_inactivity(ClientState state) override {
    // ...
  }
};

int main() {
    std::string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";
    auto handler = std::make_unique<EventHandler>();
    Client client(std::move(handler));
    client.connect(url);
    auto endpoints = client.get_endpoints(url);
}
