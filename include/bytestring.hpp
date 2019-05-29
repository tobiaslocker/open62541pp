#ifndef OPEN6541_CPP_WRAPPER_BYTE_STRING_H
#define OPEN6541_CPP_WRAPPER_BYTE_STRING_H

// STL
#include <memory>
#include <string>

namespace open62541 {

using ByteString = std::string;
// class ByteString {
//  class impl;
//  std::unique_ptr<impl> d_ptr;

// public:
//  ByteString();
//  ~ByteString();

//  ByteString(ByteString &&) noexcept;
//  ByteString &operator=(ByteString &&) noexcept;
//  ByteString(ByteString const &);
//  ByteString &operator=(ByteString const &);

//  ByteString(std::string const &data);

//  std::string str() const;

//  bool operator==(ByteString const &rhs) const {return true;}
//  bool operator!=(ByteString const &rhs) const {return false;}
//;
//};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_BYTE_STRING_H
