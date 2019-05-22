#ifndef OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H

#include "open62541.h"

#include "enums.hpp"
#include "expandednodeid.hpp"
#include "localizedtext.hpp"
#include "nodeid.hpp"
#include "qualifiedname.hpp"

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {
using namespace nlohmann;

class ReferenceDescription {
  NodeId m_reference_type_id;
  bool m_is_forward;
  ExpandedNodeId m_node_id;
  QualifiedName m_browse_name;
  LocalizedText m_display_name;
  NodeClass m_node_class;
  ExpandedNodeId m_type_definition;

 public:
  explicit ReferenceDescription(NodeId const &reference_type_id,
                                bool is_forward,
                                ExpandedNodeId const &node_id,
                                QualifiedName const &browse_name,
                                LocalizedText const &display_name,
                                NodeClass const &node_class,
                                ExpandedNodeId const &type_definition);

  NodeId reference_type_id() const;
  bool is_forward() const;
  ExpandedNodeId node_id() const;
  QualifiedName browse_name() const;
  LocalizedText display_name() const;
  NodeClass node_class() const;
  ExpandedNodeId type_definition() const;
//  json to_json() const;

  bool operator==(ReferenceDescription const &rhs) const;
  bool operator!=(ReferenceDescription const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  ReferenceDescription const &ref_description);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H
