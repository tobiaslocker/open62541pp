#ifndef OPEN6541_CPP_WRAPPER_DATE_TIME_H
#define OPEN6541_CPP_WRAPPER_DATE_TIME_H

namespace open62541 {

class DateTime {
 public:
  bool operator==(DateTime const &rhs) const { return true; }
  bool operator!=(DateTime const &rhs) const { return false; }
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_DATE_TIME_H
