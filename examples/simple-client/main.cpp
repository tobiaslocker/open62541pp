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
  //  std::string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";
  //  auto handler = std::make_unique<EventHandler>();
  //  Client client(std::move(handler));
  ////  client.connect(url);
  //  auto endpoints = client.get_endpoints(url);

  auto a =
      ApplicationDescription("app:uri:test:123",
                             "prod:uri:test:456",
                             LocalizedText(Locale("en"), Text("app-test-name")),
                             ApplicationType::Client,
                             "gateway:server:uri",
                             "discovery:profile:uri",
                             {"url-1", "url-2"});

  std::cout << a << '\n';
}
