#include "client.hpp"
#include <iostream>

using namespace open62541;
   
int main(int argc, char *argv[]) {

    std::string url = "opc.tcp://opcua.demo-this.com:51210/UA/SampleServer";

    Client client;
    client.connect(url);
}
