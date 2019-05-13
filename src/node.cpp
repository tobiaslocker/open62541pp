#include "node.hpp"
#include "client.hpp"

namespace open62541 {

Node::Node(const NodeId &node_id, std::shared_ptr<Client> client)
    : m_node_id{node_id}, m_client{client} {
  BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Creating node";
}

std::vector<ReferenceDescription> Node::browse_children(
    BrowseResultMask mask,
    NodeClassMask node_class_mask,
    ReferenceTypeIdentifier id) {
  BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, debug) << "Browsing children";
  std::vector<ReferenceDescription> children;
  UA_BrowseRequest browse_req;
  UA_BrowseRequest_init(&browse_req);
  std::shared_ptr<UA_BrowseDescription> browse_desc(new UA_BrowseDescription);
  UA_BrowseDescription_init(browse_desc.get());
  browse_desc->nodeClassMask = node_class_mask;
  browse_req.requestedMaxReferencesPerNode = 0;
  browse_req.nodesToBrowse = browse_desc.get();
  browse_req.nodesToBrowseSize = 1;
  browse_req.nodesToBrowse[0].nodeId = m_node_id.ua_node_id();
  browse_req.nodesToBrowse[0].resultMask = static_cast<u_int32_t>(mask);
  browse_req.nodesToBrowse[0].referenceTypeId =
      UA_NODEID_NUMERIC(0, static_cast<u_int32_t>(id));
  browse_req.nodesToBrowse[0].includeSubtypes = true;

  UA_BrowseResponse browse_response = m_client->browse(browse_req);

  for (size_t i = 0; i < browse_response.resultsSize; ++i) {
    for (size_t j = 0; j < browse_response.results[i].referencesSize; ++j) {
      auto ref = ReferenceDescription(browse_response.results[i].references[j]);
      children.push_back(ref);
    }
  }
  UA_BrowseResponse_deleteMembers(&browse_response);
  return children;
}

NodeId Node::node_id() const { return NodeId(m_node_id); }

}  // namespace open62541
