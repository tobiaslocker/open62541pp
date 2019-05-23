#include "referencedescription.hpp"

namespace open62541 {

ReferenceDescription::ReferenceDescription(
    const NodeId &reference_type_id,
    bool is_forward,
    const ExpandedNodeId &node_id,
    QualifiedName const &browse_name,
    LocalizedText const &display_name,
    const NodeClass &node_class,
    ExpandedNodeId const &type_definition)
    : m_reference_type_id{reference_type_id},
      m_is_forward{is_forward},
      m_node_id{node_id},
      m_browse_name{browse_name},
      m_display_name{display_name},
      m_node_class{node_class},
      m_type_definition{type_definition} {}

NodeId ReferenceDescription::reference_type_id() const {
  return m_reference_type_id;
}

bool ReferenceDescription::is_forward() const { return m_is_forward; }

ExpandedNodeId ReferenceDescription::node_id() const { return m_node_id; }

LocalizedText ReferenceDescription::display_name() const {
  return m_display_name;
}

NodeClass ReferenceDescription::node_class() const { return m_node_class; }

QualifiedName ReferenceDescription::browse_name() const {
  return m_browse_name;
}

// json ReferenceDescription::to_json() const {
//  json ref_description;
//  ref_description["DisplayName"] = display_name().text();
//  ref_description["BrowseName"] = browse_name().name();
//  ref_description["NodeId"] = node_id().to_json();
//  ref_description["TypeDefinition"] = type_definition().to_json();
//  return ref_description;
//}

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
  //  auto j = ref_description.to_json();
  //  out << j;
  return out;
}

ExpandedNodeId ReferenceDescription::type_definition() const {
  return m_type_definition;
}

}  // namespace open62541
