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
  json ref_description;
  ref_description["DisplayName"] = display_name().text();
  ref_description["BrowseName"] = browse_name().name();
  ref_description["NodeId"] = node_id().to_json();
  ref_description["TypeDefinition"] = type_definition().to_json();
  return ref_description;
}

bool ReferenceDescription::operator==(const ReferenceDescription &rhs) const {
  return node_id() == rhs.node_id() && display_name() == rhs.display_name() &&
         browse_name() == rhs.browse_name() &&
         type_definition() == rhs.type_definition();
}

bool ReferenceDescription::operator!=(const ReferenceDescription &rhs) const {
  return node_id() != rhs.node_id() && display_name() != rhs.display_name() &&
         browse_name() != rhs.browse_name() &&
         type_definition() != rhs.type_definition();
}

std::ostream &operator<<(std::ostream &out,
                         const ReferenceDescription &ref_description) {
  auto j = ref_description.to_json();
  out << j;
  return out;
}

ExpandedNodeId ReferenceDescription::type_definition() const {
  return m_type_definition;
}

}  // namespace open62541
