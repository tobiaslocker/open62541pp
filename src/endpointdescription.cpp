#include "endpointdescription.hpp"

namespace open62541 {

EndpointDescription::EndpointDescription() {}

EndpointDescription::EndpointDescription(
    const UA_EndpointDescription &endpoint_description)
    : m_server{endpoint_description.server},
      m_server_certificate{endpoint_description.serverCertificate},
      m_security_mode{MessageSecurityMode(endpoint_description.securityMode)},
      m_security_level{endpoint_description.securityLevel} {
  for (size_t i = 0; i < endpoint_description.userIdentityTokensSize; ++i) {
    auto policy = UserTokenPolicy(endpoint_description.userIdentityTokens[i]);
    m_user_identity_tokens.push_back(policy);
  }
  m_endpoint_url.assign(endpoint_description.endpointUrl.data,
                        endpoint_description.endpointUrl.data +
                            endpoint_description.endpointUrl.length);
  m_security_policy_uri.assign(
      endpoint_description.securityPolicyUri.data,
      endpoint_description.securityPolicyUri.data +
          endpoint_description.securityPolicyUri.length);
  m_transport_profile_uri.assign(
      endpoint_description.transportProfileUri.data,
      endpoint_description.transportProfileUri.data +
          endpoint_description.transportProfileUri.length);
}

std::string EndpointDescription::endpoint_url() const { return m_endpoint_url; }

ApplicationDescription EndpointDescription::server() const { return m_server; }

Certificate EndpointDescription::server_certificate() const {
  return m_server_certificate;
}

MessageSecurityMode EndpointDescription::security_mode() const {
  return m_security_mode;
}

std::string EndpointDescription::security_policy_uri() const {
  return m_security_policy_uri;
}

std::vector<UserTokenPolicy> EndpointDescription::user_identity_tokens() const {
  return m_user_identity_tokens;
}

std::string EndpointDescription::transport_profile_uri() const {
  return m_transport_profile_uri;
}

unsigned char EndpointDescription::security_level() const {
  return m_security_level;
}

json EndpointDescription::to_json() const {
  json endpoint_desc;
  endpoint_desc["EndpointUrl"] = m_endpoint_url;
  endpoint_desc["Server"] = m_server.to_json();
  //  endpoint_desc["Certificate"] = m_server_certificate.to_string();

  switch (m_security_mode) {
    case MessageSecurityMode::Invalid:
      endpoint_desc["SecurityMode"] = "Invalid";
      break;
    case MessageSecurityMode::None:
      endpoint_desc["SecurityMode"] = "None";
      break;
    case MessageSecurityMode::Sign:
      endpoint_desc["SecurityMode"] = "Sign";
      break;
    case MessageSecurityMode::SignAndEncrypt:
      endpoint_desc["SecurityMode"] = "SignAndEncrypt";
      break;
  }

  endpoint_desc["SecurityPolicyUri"] = m_security_policy_uri;
  endpoint_desc["TransportProfileUri"] = m_transport_profile_uri;
  endpoint_desc["SecurityLevel"] = m_security_level;

  json policies;
  std::for_each(
      m_user_identity_tokens.begin(),
      m_user_identity_tokens.end(),
      [&](UserTokenPolicy const &p) { policies.push_back(p.to_json()); });
  endpoint_desc["UserIdentityTokens"] = policies;
  return endpoint_desc;
}

bool EndpointDescription::operator==(const EndpointDescription &rhs) const {
  return endpoint_url() == rhs.endpoint_url() && server() == rhs.server() &&
         server_certificate() == rhs.server_certificate() &&
         security_mode() == rhs.security_mode() &&
         security_policy_uri() == rhs.security_policy_uri() &&
         user_identity_tokens() == rhs.user_identity_tokens() &&
         transport_profile_uri() == rhs.transport_profile_uri() &&
         security_level() == rhs.security_level();
}

bool EndpointDescription::operator!=(const EndpointDescription &rhs) const {
  return endpoint_url() != rhs.endpoint_url() && server() == rhs.server() &&
         server_certificate() != rhs.server_certificate() &&
         security_mode() != rhs.security_mode() &&
         security_policy_uri() != rhs.security_policy_uri() &&
         user_identity_tokens() != rhs.user_identity_tokens() &&
         transport_profile_uri() != rhs.transport_profile_uri() &&
         security_level() != rhs.security_level();
}

std::ostream &operator<<(std::ostream &out,
                         const EndpointDescription &endpoint_description) {
  auto j = endpoint_description.to_json();
  out << j;
  return out;
}

}  // namespace open62541
