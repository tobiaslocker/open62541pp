#include "referencedescription.hpp"

namespace open62541 {

ReferenceDescription::ReferenceDescription(UA_ReferenceDescription const &ref)
    : m_ref{ref},
      m_node_id{NodeId(ref.nodeId.nodeId)},
      m_display_name{LocalizedText(ref.displayName)},
      m_browse_name{QualifiedName(ref.browseName)},
      m_type_definition{ExpandedNodeId(ref.typeDefinition)} {}

NodeId ReferenceDescription::node_id() const { return m_node_id; }

LocalizedText ReferenceDescription::display_name() const {
  return m_display_name;
}

QualifiedName ReferenceDescription::browse_name() const {
  return m_browse_name;
}

json ReferenceDescription::to_json() const {
  json j;
  j["DisplayName"] = display_name().text();
  j["BrowseName"] = browse_name().name();
  j["NodeId"] = node_id().to_json();
  j["TypeDefinition"] = type_definition().to_json();
  return j;
}

ExpandedNodeId ReferenceDescription::type_definition() const {
  return m_type_definition;
}

}  // namespace open62541
