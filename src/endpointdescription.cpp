#include "endpointdescription.hpp"

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

EndpointDescription::EndpointDescription() {}

EndpointDescription::EndpointDescription(
    const UA_EndpointDescription &endpoint_description)
    : m_server{endpoint_description.server},
      m_server_certificate{endpoint_description.serverCertificate},
      m_security_mode{MessageSecurityMode(endpoint_description.securityMode)},
      m_user_identity_tokens_size{endpoint_description.userIdentityTokensSize},
      m_security_level{endpoint_description.securityLevel} {
  for (size_t i = 0; i < endpoint_description.userIdentityTokensSize; ++i) {
    auto policy = UserTokenPolicy(endpoint_description.userIdentityTokens[i]);
    m_user_identity_tokens.push_back(policy);
  }
  if (auto c =
          reinterpret_cast<char *>(endpoint_description.endpointUrl.data)) {
    m_endpoint_url = std::string(c);
  }
  if (auto c = reinterpret_cast<char *>(
          endpoint_description.securityPolicyUri.data)) {
    m_security_policy_uri = std::string(c);
  }
  if (auto c = reinterpret_cast<char *>(
          endpoint_description.transportProfileUri.data)) {
    m_transport_profile_uri = std::string(c);
  }
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

size_t EndpointDescription::user_identity_tokens_size() const {
  return m_user_identity_tokens_size;
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

}  // namespace open62541
