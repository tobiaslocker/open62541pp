#ifndef OPEN62541_CPP_WRAPPER_QUALIFIED_NAME_H
#define OPEN62541_CPP_WRAPPER_QUALIFIED_NAME_H

#include "open62541.h"

// STL
#include <string>

namespace open62541 {

class QualifiedName {
  std::string m_name;
  u_int16_t m_namespace_index;

 public:
  QualifiedName(UA_QualifiedName const &name);
  std::string name();
  u_int16_t namespace_index();
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_QUALIFIED_NAME_H
