#ifndef OPEN62541_CPP_WRAPPER_USER_TOKEN_POLICY_H
#define OPEN62541_CPP_WRAPPER_USER_TOKEN_POLICY_H

// STL
#include <memory>
#include <string>

#include "enums.hpp"

namespace open62541 {

class UserTokenPolicy {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  UserTokenPolicy();
  ~UserTokenPolicy();

  UserTokenPolicy(UserTokenPolicy &&) noexcept;
  UserTokenPolicy &operator=(UserTokenPolicy &&) noexcept;
  UserTokenPolicy(UserTokenPolicy const &);
  UserTokenPolicy &operator=(UserTokenPolicy const &);

  UserTokenPolicy(std::string const &policy_id,
                  UserTokenType token_type,
                  std::string const &issued_token_type,
                  std::string const &issuer_endpoint_url,
                  std::string const &security_policy_uri);

 public:
  std::string policy_id() const;
  UserTokenType token_type() const;
  std::string issued_token_type() const;
  std::string issuer_endpoint_url() const;
  std::string security_policy_uri() const;

  bool operator==(UserTokenPolicy const &rhs) const;
  bool operator!=(UserTokenPolicy const &rhs) const;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_USER_TOKEN_POLICY_H
