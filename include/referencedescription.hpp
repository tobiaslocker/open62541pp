#ifndef OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H

#include "open62541.h"

#include "expandednodeid.hpp"
#include "localizedtext.hpp"
#include "nodeid.hpp"
#include "qualifiedname.hpp"

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {
using namespace nlohmann;

class ReferenceDescription {
  UA_ReferenceDescription m_ref;
  NodeId m_node_id;
  LocalizedText m_display_name;
  QualifiedName m_browse_name;
  ExpandedNodeId m_type_definition;
  explicit ReferenceDescription(UA_ReferenceDescription const &ref);

 public:
  NodeId node_id() const;
  LocalizedText display_name() const;
  QualifiedName browse_name() const;
  ExpandedNodeId type_definition() const;

  json to_json() const;

  bool operator==(ReferenceDescription const &rhs) const;
  bool operator!=(ReferenceDescription const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  ReferenceDescription const &ref_description);

  friend class Node;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H
