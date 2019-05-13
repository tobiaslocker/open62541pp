#ifndef OPEN62541_CPP_WRAPPER_NODE_H
#define OPEN62541_CPP_WRAPPER_NODE_H

#include "open62541.h"

// STL
#include <memory>
#include <vector>

#include "nodeid.hpp"
#include "referencedescription.hpp"

#include "log.hpp"

namespace open62541 {

class Client;

using namespace logger;

enum class BrowseResultMask : u_int32_t {
  None = 0,
  ReferenceTypeId = 1,
  IsForward = 2,
  NodeClass = 4,
  QualifiedName = 8,
  LocalizedText = 16,
  TypeDefinition = 32,
  All = 63,
  ReferencetypeInfo = 3,
  TargetInfo = 6,
};

enum class ReferenceTypeIdentifier : u_int32_t {
  Unspecified = 0,
  References = 31,
  NonHierarchicalReferences = 32,
  HierarchicalReferences = 33,
  HasChild = 34,
  Organizes = 35,
  HasEventSource = 36,
  HasModellingRule = 37,
  HasEncoding = 38,
  HasDescription = 39,
  HasTypeDefinition = 40,
  GeneratesEvent = 41,
  Aggregates = 44,
  HasSubtype = 45,
  HasProperty = 46,
  HasComponent = 47,
  HasNotifier = 48,
  HasOrderedComponent = 49,
  FromState = 51,
  ToState = 52,
  HasCause = 53,
  HasEffect = 54,
  HasHistoricalConfiguration = 56,
  HasSubStateMachine = 117,
  AlwaysGeneratesEvent = 3065,
  HasTrueSubState = 9004,
  HasFalseSubState = 9005,
  HasCondition = 9006
};

enum class NodeClass : u_int32_t {
  Unspecified = 0,
  Object = 1,
  Variable = 2,
  Method = 4,
  ObjectType = 8,
  VariableType = 16,
  ReferenceType = 32,
  DataType = 64,
  View = 128,
  All = 255
};

inline NodeClass operator|(NodeClass a, NodeClass b) {
  return static_cast<NodeClass>(static_cast<int>(a) | static_cast<int>(b));
}

struct NodeClassMask {
  u_int32_t m_node_class_mask = 0;
  NodeClassMask(NodeClass const &node_class_mask)
      : m_node_class_mask{static_cast<u_int32_t>(node_class_mask)} {}
  operator u_int32_t() const { return m_node_class_mask; }
};

class Node {
  NodeId m_node_id;
  std::shared_ptr<Client> m_client;
  src::severity_channel_logger<severity_level, std::string> m_lg;
  std::string m_channel = "ua_node";

 public:
  explicit Node(NodeId const &node_id, std::shared_ptr<Client> client);
  std::vector<ReferenceDescription> browse_children(
      BrowseResultMask mask,
      NodeClassMask node_class_mask,
      ReferenceTypeIdentifier id);
  NodeId node_id() const;
  friend class Client;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_NODE_H
