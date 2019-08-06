#include "endpointdescription.hpp"

namespace open62541 {

class EndpointDescription::impl {
  std::string m_endpoint_url;
  ApplicationDescription m_server;
  ByteString m_server_certificate;
  MessageSecurityMode m_security_mode;
  std::string m_security_policy_uri;
  std::vector<UserTokenPolicy> m_user_identity_tokens;
  std::string m_transport_profile_uri;
  unsigned char m_security_level = 0;
  bool m_empty = false;

 public:
  impl() : m_security_mode{MessageSecurityMode::None}, m_empty{true} {}

  impl(std::string const &endpoint_url,
       ApplicationDescription const &server,
       ByteString const &server_certificate,
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

  std::string endpoint_url() const { return m_endpoint_url; }

  ApplicationDescription server() const { return m_server; }

  ByteString server_certificate() const { return m_server_certificate; }

  MessageSecurityMode security_mode() const { return m_security_mode; }

  std::string security_policy_uri() const { return m_security_policy_uri; }

  std::vector<UserTokenPolicy> user_identity_tokens() const {
    return m_user_identity_tokens;
  }

  std::string transport_profile_uri() const { return m_transport_profile_uri; }

  unsigned char security_level() const { return m_security_level; }

  bool empty() const { return m_empty; }

  bool operator==(impl const &rhs) const {
    return endpoint_url() == rhs.endpoint_url() && server() == rhs.server() &&
           server_certificate() == rhs.server_certificate() &&
           security_mode() == rhs.security_mode() &&
           security_policy_uri() == rhs.security_policy_uri() &&
           user_identity_tokens() == rhs.user_identity_tokens() &&
           transport_profile_uri() == rhs.transport_profile_uri() &&
           security_level() == rhs.security_level();
  }

  bool operator!=(impl const &rhs) const {
    return endpoint_url() != rhs.endpoint_url() || server() != rhs.server() ||
           server_certificate() != rhs.server_certificate() ||
           security_mode() != rhs.security_mode() ||
           security_policy_uri() != rhs.security_policy_uri() ||
           user_identity_tokens() != rhs.user_identity_tokens() ||
           transport_profile_uri() != rhs.transport_profile_uri() ||
           security_level() != rhs.security_level();
  }
};

EndpointDescription::EndpointDescription(
    std::string const &endpoint_url,
    ApplicationDescription const &server,
    ByteString const &server_certificate,
    MessageSecurityMode const &security_mode,
    std::string const &security_policy_uri,
    std::vector<UserTokenPolicy> const &user_identity_tokens,
    std::string const &transport_profile_uri,
    unsigned char security_level)
    : d_ptr{std::make_unique<impl>(endpoint_url,
                                   server,
                                   server_certificate,
                                   security_mode,
                                   security_policy_uri,
                                   user_identity_tokens,
                                   transport_profile_uri,
                                   security_level)} {}

EndpointDescription::~EndpointDescription() = default;

EndpointDescription::EndpointDescription(EndpointDescription const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

EndpointDescription::EndpointDescription(EndpointDescription &&) noexcept =
    default;

EndpointDescription &EndpointDescription::operator=(
    EndpointDescription &&) noexcept = default;

EndpointDescription::EndpointDescription() : d_ptr{std::make_unique<impl>()} {}

EndpointDescription &EndpointDescription::operator=(
    EndpointDescription const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

std::string EndpointDescription::endpoint_url() const {
  return d_ptr->endpoint_url();
}

ApplicationDescription EndpointDescription::server() const {
  return d_ptr->server();
}

ByteString EndpointDescription::server_certificate() const {
  return d_ptr->server_certificate();
}

MessageSecurityMode EndpointDescription::security_mode() const {
  return d_ptr->security_mode();
}

std::string EndpointDescription::security_policy_uri() const {
  return d_ptr->security_policy_uri();
}

std::vector<UserTokenPolicy> EndpointDescription::user_identity_tokens() const {
  return d_ptr->user_identity_tokens();
}

std::string EndpointDescription::transport_profile_uri() const {
  return d_ptr->transport_profile_uri();
}

unsigned char EndpointDescription::security_level() const {
  return d_ptr->security_level();
}

bool EndpointDescription::empty() const { return d_ptr->empty(); }

bool EndpointDescription::operator==(EndpointDescription const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool EndpointDescription::operator!=(EndpointDescription const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(std::ostream &out, const EndpointDescription &op) {
  out << "{\n"
      << "    endpoint_url -> " << op.endpoint_url() << '\n'
      << "    security_mode -> " << op.security_mode() << '\n'
      << "    security_level -> "
      << static_cast<unsigned int>(op.security_level()) << '\n'
      << "    security_policy_uri -> " << op.security_policy_uri() << '\n'
      << "    transport_profile_uri -> " << op.transport_profile_uri() << '\n'
      << "    user_identity_tokens ->\n    [\n";
  for (auto const &token : op.user_identity_tokens()) {
    out << token;
  }

  out << "    ]\n}";
  return out;
}

}  // namespace open62541
