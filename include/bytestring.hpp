#ifndef OPEN6541_CPP_WRAPPER_BYTE_STRING_H
#define OPEN6541_CPP_WRAPPER_BYTE_STRING_H

#include <string>

namespace open62541 {

class ByteString {
public:
    static ByteString from_base_64(std::string const &data){}
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_BYTE_STRING_H
