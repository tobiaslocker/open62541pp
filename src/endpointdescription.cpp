#include "endpointdescription.hpp"

namespace open62541 {

EndpointDescription::EndpointDescription(
    std::string const &endpoint_url,
    ApplicationDescription const &server,
    Certificate const &server_certificate,
    MessageSecurityMode const &security_mode,
    std::string const &security_policy_uri,
    std::vector<UserTokenPolicy> const &user_identity_tokens,
    std::string const &transport_profile_uri,
    unsigned char security_level)
    : m_endpoint_url{endpoint_url},
      m_server{server},
      m_server_certificate{server_certificate},
      m_security_mode{security_mode},
      m_security_policy_uri{security_policy_uri},
      m_user_identity_tokens{user_identity_tokens},
      m_transport_profile_uri{transport_profile_uri},
      m_security_level{security_level} {}

EndpointDescription::EndpointDescription() {}

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
//  endpoint_desc["Server"] = m_server.to_json();
  //  endpoint_desc["Certificate"] = m_server_certificate.str();

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
