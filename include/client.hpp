#ifndef OPEN62541_CPP_WRAPPER_CLIENT_H
#define OPEN62541_CPP_WRAPPER_CLIENT_H

// STL
#include <memory>
#include <string>
#include <vector>

#include "browserequest.hpp"
#include "browseresponse.hpp"
#include "endpointdescription.hpp"
#include "nodeid.hpp"
#include "referencedescription.hpp"

#include "enums.hpp"

namespace open62541 {

class Client {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  Client();
  ~Client();
  Client(Client &&) = default;
  Client(Client const &) = delete;
  Client &operator=(Client &&);
  Client &operator=(Client const &) = delete;
  BrowseResponse browse(BrowseRequest const &request);
  std::vector<EndpointDescription> get_endpoints(std::string const &url);
  void connect(std::string const &url);
  void connect(EndpointDescription const &endpoint);

  LocalizedText read_display_name_attribute(NodeId const &node_id);
  std::vector<ReferenceDescription> get_child_references(
      ReferenceDescription const &reference,
      BrowseResultMask br_mask,
      NodeClassMask nc_mask,
      ReferenceTypeIdentifier id);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_CLIENT_H
