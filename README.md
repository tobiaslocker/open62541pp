# A wrapper for open62541 in modern C++

This is a wrapper that covers some of [open62541's](https://github.com/open62541/open62541)
functionality. Currently it is based on the v0.3.0 single-file-distribution.

## Usage

To create a client and connect to a server:

```c++
auto client = Client::create();
client->connect_to_endpoint("opc.tcp://opcua.demo-this.com:51210/UA/SampleServer");

```
