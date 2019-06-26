#ifndef OPEN6541_CPP_WRAPPER_EXTENSION_OBJECT_H
#define OPEN6541_CPP_WRAPPER_EXTENSION_OBJECT_H

namespace open62541 {

class ExtensionObject {
 public:
  bool operator==(ExtensionObject const &rhs) const { return true; }
  bool operator!=(ExtensionObject const &rhs) const { return false; }
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
