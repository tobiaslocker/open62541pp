#ifndef OPEN62541_CPP_WRAPPER_USER_TOKEN_POLICY_H
#define OPEN62541_CPP_WRAPPER_USER_TOKEN_POLICY_H

#include "open62541.h"

// STL
#include <string>

// Dependencies
#include <nlohmann/json.hpp>

namespace open62541 {
using namespace nlohmann;

enum class UserTokenType : u_int32_t {
  Anonymous = 0,
  UserName = 1,
  Certificate = 2,
  IssuedToken = 3
};

class UserTokenPolicy {
  std::string m_policy_id;
  UserTokenType m_token_type;
  std::string m_issued_token_type;
  std::string m_issuer_endpoint_url;
  std::string m_security_policy_uri;

 public:
  UserTokenPolicy(UA_UserTokenPolicy const &user_token_policy);
  std::string policy_id() const;
  UserTokenType token_type() const;
  std::string issued_token_type() const;
  std::string issuer_endpoint_url() const;
  std::string security_policy_uri() const;
  json to_json() const;
  bool operator==(UserTokenPolicy const &rhs) const;
  bool operator!=(UserTokenPolicy const &rhs) const;
  friend std::ostream &operator<<(std::ostream &out,
                                  UserTokenPolicy const &user_token_policy);
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_USER_TOKEN_POLICY_H
