#include "usertokenpolicy.hpp"

namespace open62541 {

class UserTokenPolicy::impl {
  std::string m_policy_id;
  UserTokenType m_token_type;
  std::string m_issued_token_type;
  std::string m_issuer_endpoint_url;
  std::string m_security_policy_uri;

 public:
  impl() {}

  std::string policy_id() const { return m_policy_id; }

  UserTokenType token_type() const { return m_token_type; }

  std::string issued_token_type() const { return m_issued_token_type; }

  std::string issuer_endpoint_url() const { return m_issuer_endpoint_url; }

  std::string security_policy_uri() const { return m_security_policy_uri; }

  bool operator==(impl const &rhs) const {
    return policy_id() == rhs.policy_id() && token_type() == rhs.token_type() &&
           issued_token_type() == rhs.issued_token_type() &&
           issuer_endpoint_url() == rhs.issuer_endpoint_url() &&
           security_policy_uri() == rhs.security_policy_uri();
  }

  bool operator!=(impl const &rhs) const {
    return policy_id() != rhs.policy_id() && token_type() != rhs.token_type() &&
           issued_token_type() != rhs.issued_token_type() &&
           issuer_endpoint_url() != rhs.issuer_endpoint_url() &&
           security_policy_uri() != rhs.security_policy_uri();
  }
};

UserTokenPolicy::UserTokenPolicy() : d_ptr{std::make_unique<impl>()} {}

UserTokenPolicy::~UserTokenPolicy() = default;

UserTokenPolicy::UserTokenPolicy(UserTokenPolicy const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

UserTokenPolicy &UserTokenPolicy::operator=(UserTokenPolicy const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

std::string UserTokenPolicy::policy_id() const { return d_ptr->policy_id(); }

UserTokenType UserTokenPolicy::token_type() const {
  return d_ptr->token_type();
}

std::string UserTokenPolicy::issued_token_type() const {
  return d_ptr->issued_token_type();
}

std::string UserTokenPolicy::issuer_endpoint_url() const {
  return d_ptr->issuer_endpoint_url();
}

std::string UserTokenPolicy::security_policy_uri() const {
  return d_ptr->security_policy_uri();
}

bool UserTokenPolicy::operator==(UserTokenPolicy const &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool UserTokenPolicy::operator!=(UserTokenPolicy const &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

}  // namespace open62541
