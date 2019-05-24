#ifndef OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H

#include "enums.hpp"
#include "expandednodeid.hpp"
#include "localizedtext.hpp"
#include "nodeid.hpp"
#include "qualifiedname.hpp"

namespace open62541 {

class ReferenceDescription {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  ReferenceDescription();
  ~ReferenceDescription();

  ReferenceDescription(ReferenceDescription &&) noexcept;
  ReferenceDescription &operator=(ReferenceDescription &&) noexcept;
  ReferenceDescription(ReferenceDescription const &);
  ReferenceDescription &operator=(ReferenceDescription const &);

  ReferenceDescription(NodeId const &reference_type_id,
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

  bool operator==(ReferenceDescription const &rhs) const;
  bool operator!=(ReferenceDescription const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_REFERENCE_DESCRIPTION_H
