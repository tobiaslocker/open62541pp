#ifndef OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
#define OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H

namespace open62541 {

class RequestHeader {

public:
  bool operator==(RequestHeader const &rhs) const {return true;}
  bool operator!=(RequestHeader const &rhs) const {return false;}
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_REQUEST_HEADER_H
