#ifndef OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H
#define OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H

namespace open62541 {

class ResponseHeader {

public:
  bool operator==(ResponseHeader const &rhs) const {return true;}
  bool operator!=(ResponseHeader const &rhs) const {return false;}
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_RESPONSE_HEADER_H
