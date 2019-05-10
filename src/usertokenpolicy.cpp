#include "usertokenpolicy.hpp"

namespace open62541 {

UserTokenPolicy::UserTokenPolicy(const UA_UserTokenPolicy &user_token_policy)
    : m_token_type{UserTokenType(user_token_policy.tokenType)} {
  m_policy_id.assign(
      user_token_policy.policyId.data,
      user_token_policy.policyId.data + user_token_policy.policyId.length);
  m_issued_token_type.assign(user_token_policy.issuedTokenType.data,
                             user_token_policy.issuedTokenType.data +
                                 user_token_policy.issuedTokenType.length);
  m_issuer_endpoint_url.assign(user_token_policy.issuerEndpointUrl.data,
                               user_token_policy.issuerEndpointUrl.data +
                                   user_token_policy.issuerEndpointUrl.length);
  m_security_policy_uri.assign(user_token_policy.securityPolicyUri.data,
                               user_token_policy.securityPolicyUri.data +
                                   user_token_policy.securityPolicyUri.length);
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

bool UserTokenPolicy::operator==(const UserTokenPolicy &rhs) const {
  return policy_id() == rhs.policy_id() && token_type() == rhs.token_type() &&
         issued_token_type() == rhs.issued_token_type() &&
         issuer_endpoint_url() == rhs.issuer_endpoint_url() &&
         security_policy_uri() == rhs.security_policy_uri();
}

bool UserTokenPolicy::operator!=(const UserTokenPolicy &rhs) const {
  return policy_id() != rhs.policy_id() && token_type() != rhs.token_type() &&
         issued_token_type() != rhs.issued_token_type() &&
         issuer_endpoint_url() != rhs.issuer_endpoint_url() &&
         security_policy_uri() != rhs.security_policy_uri();
}

std::ostream &operator<<(std::ostream &out,
                         const UserTokenPolicy &user_token_policy) {
  auto j = user_token_policy.to_json();
  out << j;
  return out;
}

}  // namespace open62541
