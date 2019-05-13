#ifndef OPEN62541_CPP_WRAPPER_CLIENT_H
#define OPEN62541_CPP_WRAPPER_CLIENT_H

#include "open62541.h"

// STL
#include <memory>
#include <string>
#include <vector>

#include "endpointdescription.hpp"
#include "log.hpp"
#include "nodeid.hpp"

namespace open62541 {

class Node;

using namespace logger;

class Client : public std::enable_shared_from_this<Client> {
  src::severity_channel_logger<severity_level, std::string> m_lg;
  std::string m_channel = "ua_client";
  std::shared_ptr<UA_Client> m_client;
  Client();
  UA_BrowseResponse browse(UA_BrowseRequest const &request);

 public:
  std::vector<EndpointDescription> get_endpoints(std::string const &url);
  void connect(std::string const &url);
  void connect(EndpointDescription const &endpoint);
  std::shared_ptr<Node> node(NodeId const &node_id);
  LocalizedText read_display_name_attribute(NodeId const &node_id);
  std::shared_ptr<Client> client();
  static std::shared_ptr<Client> create();

  friend class Node;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_CLIENT_H
