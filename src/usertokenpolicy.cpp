#include "usertokenpolicy.hpp"

namespace open62541 {

UserTokenPolicy::UserTokenPolicy(UA_UserTokenPolicy user_token_policy)
    : m_token_type{UserTokenType(user_token_policy.tokenType)} {
  if (auto c = reinterpret_cast<char *>(user_token_policy.policyId.data)) {
    m_policy_id = std::string(c);
  }
  if (auto c =
          reinterpret_cast<char *>(user_token_policy.issuedTokenType.data)) {
    m_issued_token_type = std::string(c);
  }
  if (auto c =
          reinterpret_cast<char *>(user_token_policy.issuerEndpointUrl.data)) {
    m_issuer_endpoint_url = std::string(c);
  }
  if (auto c =
          reinterpret_cast<char *>(user_token_policy.securityPolicyUri.data)) {
    m_security_policy_uri = std::string(c);
  }
}

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
  json policy;
  policy["PolicyId"] = m_policy_id;
  policy["IssuedTokenType"] = m_issued_token_type;
  policy["IssuerEndpointUrl"] = m_policy_id;
  policy["SecurityPolicyUri"] = m_policy_id;
  switch (m_token_type) {
    case UserTokenType::Anonymous:
      policy["UserTokenType"] = "Anonymous";
      break;
    case UserTokenType::UserName:
      policy["UserTokenType"] = "UserName";
      break;
    case UserTokenType::Certificate:
      policy["UserTokenType"] = "Certificate";
      break;
    case UserTokenType::IssuedToken:
      policy["UserTokenType"] = "IssuedToken";
      break;
  }
  return policy;
}

}  // namespace open62541
