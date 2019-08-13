#ifndef OPEN62541_CPP_WRAPPER_ENDPOINT_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_ENDPOINT_DESCRIPTION_H

// STL
#include <string>
#include <vector>

#include "applicationdescription.hpp"
#include "bytestring.hpp"
#include "enums.hpp"
#include "localizedtext.hpp"
#include "usertokenpolicy.hpp"

namespace open62541 {

class EndpointDescription {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  EndpointDescription();
  ~EndpointDescription();
  EndpointDescription(EndpointDescription &&) noexcept;
  EndpointDescription &operator=(EndpointDescription &&) noexcept;
  EndpointDescription(EndpointDescription const &);
  EndpointDescription &operator=(EndpointDescription const &);

  explicit EndpointDescription(
      std::string const &endpoint_url,
      ApplicationDescription const &server,
      ByteString const &server_certificate,
      MessageSecurityMode const &security_mode,
      std::string const &security_policy_uri,
      std::vector<UserTokenPolicy> const &user_identity_tokens,
      std::string const &transport_profile_uri,
      unsigned char security_level);

  std::string endpoint_url() const;
  ApplicationDescription server() const;
  ByteString server_certificate() const;
  MessageSecurityMode security_mode() const;
  std::string security_policy_uri() const;
  std::vector<UserTokenPolicy> user_identity_tokens() const;
  std::string transport_profile_uri() const;
  unsigned char security_level() const;

  bool empty() const;

  bool operator==(EndpointDescription const &rhs) const;
  bool operator!=(EndpointDescription const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, EndpointDescription const &op);
}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_ENDPOINT_DESCRIPTION_H
