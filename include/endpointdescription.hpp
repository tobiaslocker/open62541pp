#ifndef OPEN62541_CPP_WRAPPER_ENDPOINT_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_ENDPOINT_DESCRIPTION_H

#include "open62541.h"

// STL
#include <string>
#include <vector>

// Dependencies
#include <nlohmann/json.hpp>

#include "applicationdescription.hpp"
#include "certificate.hpp"
#include "localizedtext.hpp"
#include "log.hpp"
#include "usertokenpolicy.hpp"

namespace open62541 {

using namespace logger;
using namespace nlohmann;

enum class MessageSecurityMode {
  Invalid = 0,
  None = 1,
  Sign = 2,
  SignAndEncrypt = 3
};

class EndpointDescription {
  std::string m_endpoint_url;
  ApplicationDescription m_server;
  Certificate m_server_certificate;
  MessageSecurityMode m_security_mode;
  std::string m_security_policy_uri;
  size_t m_user_identity_tokens_size;
  std::vector<UserTokenPolicy> m_user_identity_tokens;
  std::string m_transport_profile_uri;
  unsigned char m_security_level;

 public:
  EndpointDescription();
  explicit EndpointDescription(UA_EndpointDescription const &url);
  std::string endpoint_url() const;
  ApplicationDescription server() const;
  Certificate server_certificate() const;
  MessageSecurityMode security_mode() const;
  std::string security_policy_uri() const;
  std::vector<UserTokenPolicy> user_identity_tokens() const;
  std::string transport_profile_uri() const;
  unsigned char security_level() const;

  json to_json() const;

  bool operator==(EndpointDescription const &rhs);
  bool operator!=(EndpointDescription const &rhs);
  friend std::ostream &operator<<(
      std::ostream &out, EndpointDescription const &endpoint_description);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_ENDPOINT_DESCRIPTION_H
