# A wrapper for open62541 in modern C++

This is a wrapper that covers some of [open62541's](https://github.com/open62541/open62541)
functionality. Currently it is based on the v0.3.0 single-file-distribution.

## Building

```console
git submodule update --init --recursive
./scripts/build.sh
```

## Building the example

```console
cd examples/simple-client/
./build.sh
```
or
```console
cd examples/simple-client/
./run.sh
```

## Examples

```C++
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
```

