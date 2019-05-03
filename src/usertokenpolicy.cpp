#include "usertokenpolicy.hpp"

namespace open62541 {

std::string to_std_string(UA_String const &str) {
  if (str.data) {
    char *arr = reinterpret_cast<char *>(str.data);
    if (arr) {
      return std::string(reinterpret_cast<char *>(str.data), str.length);
    }
  }
  return std::string();
}

UserTokenPolicy::UserTokenPolicy(UA_UserTokenPolicy user_token_policy)
    : m_policy_id{to_std_string(user_token_policy.policyId)},
      m_token_type{UserTokenType(user_token_policy.tokenType)},
      m_issued_token_type{to_std_string(user_token_policy.issuedTokenType)},
      m_issuer_endpoint_url{to_std_string(user_token_policy.issuerEndpointUrl)},
      m_security_policy_uri{
          to_std_string(user_token_policy.securityPolicyUri)} {}

std::string UserTokenPolicy::policy_id() const { return m_policy_id; }

UserTokenType UserTokenPolicy::token_type() const { return m_token_type; }

std::string UserTokenPolicy::issued_token_type() const {
  return m_issued_token_type;
}

std::string UserTokenPolicy::issuer_endpoint_url() const {
  return m_issuer_endpoint_url;
}

std::string UserTokenPolicy::security_policy_uri() const {
  return m_security_policy_uri;
}

json UserTokenPolicy::to_json() const {
  json j;
  j["PolicyId"] = m_policy_id;
  j["IssuedTokenType"] = m_issued_token_type;
  j["IssuerEndpointUrl"] = m_policy_id;
  j["SecurityPolicyUri"] = m_policy_id;

  switch (m_token_type) {
    case UserTokenType::Anonymous:
      j["UserTokenType"] = "Anonymous";
      break;
    case UserTokenType::UserName:
      j["UserTokenType"] = "UserName";
      break;
    case UserTokenType::Certificate:
      j["UserTokenType"] = "Certificate";
      break;
    case UserTokenType::IssuedToken:
      j["UserTokenType"] = "IssuedToken";
      break;
  }

  return j;
}

}  // namespace open62541
