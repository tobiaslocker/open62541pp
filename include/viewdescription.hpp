#ifndef OPEN6541_CPP_WRAPPER_VIEW_DESCRIPTION_H
#define OPEN6541_CPP_WRAPPER_VIEW_DESCRIPTION_H

namespace open62541 {

class ViewDescription {

public:
  bool operator==(ViewDescription const &rhs) const {return true;}
  bool operator!=(ViewDescription const &rhs) const {return false;}
};

}  // namespace open62541

#endif  // OPEN6541_CPP_WRAPPER_VIEW_DESCRIPTION_H
