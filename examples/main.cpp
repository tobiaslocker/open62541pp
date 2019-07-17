#include "client.hpp"
#include <iostream>

#include "open62541.h"

using namespace open62541;
   
int main(int argc, char *argv[]) {

    std::string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";

    Client client;
    client.connect(url);

    auto root_node = NodeId(0, Identifier(UA_NS0ID_ROOTFOLDER), IdentifierType::Numeric);
    //auto node = client->node(root_node);

    // Get json representation of root node's nodeid
    //auto json = node->node_id().to_json();
    //std::cerr << json << '\n';

    //auto endpoints = client.get_endpoints(url);
    //std::for_each(
        //endpoints.begin(), endpoints.end(), [&](EndpointDescription const &endpoint) {
            //std::cerr << endpoint.endpoint_url() << '\n';
        //});
}
