# A wrapper for open62541 in modern C++

This is a wrapper that covers some of [open62541's](https://github.com/open62541/open62541)
functionality. Currently it is based on the v0.3.0 single-file-distribution.

## Example

```c++
#include "client.hpp"
#include "node.hpp"
#include <iostream>

using namespace open62541;

int main(int argc, char *argv[]) {
    // For decent logging format...
    logger::init();

    std::string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";

    auto client = Client::create();
    client->connect(url);

    auto root_node = NodeId(0, Identifier(UA_NS0ID_ROOTFOLDER));
    auto node = client->node(root_node);

    // Get json representation of root node's nodeid
    auto json = node->node_id().to_json();
    std::cerr << json << '\n';

    auto endpoints = client->get_endpoints(url);
    std::for_each(
        endpoints.begin(), endpoints.end(), [&](EndpointDescription const &endpoint) {
            std::cerr << endpoint.to_json() << '\n';
        });
}
```
