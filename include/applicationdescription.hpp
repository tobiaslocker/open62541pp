#ifndef OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H

// STL
#include <memory>
#include <string>
#include <vector>

#include "enums.hpp"
#include "localizedtext.hpp"

namespace open62541 {

class ApplicationDescription {
  class impl;
  std::unique_ptr<impl> d_ptr;

 public:
  ApplicationDescription();
  ~ApplicationDescription();

  ApplicationDescription(ApplicationDescription &&) noexcept;
  ApplicationDescription &operator=(ApplicationDescription &&) noexcept;
  ApplicationDescription(ApplicationDescription const &);
  ApplicationDescription &operator=(ApplicationDescription const &);

  ApplicationDescription(std::string const &application_uri,
                         std::string const &product_uri,
                         LocalizedText const &application_name,
                         ApplicationType const &application_type,
                         std::string const &gateway_server_uri,
                         std::string const &discovery_profile_uri,
                         std::vector<std::string> const &discovery_urls);

  std::string application_uri() const;
  std::string product_uri() const;
  LocalizedText application_name() const;
  ApplicationType application_type() const;
  std::string gateway_server_uri() const;
  std::string discovery_profile_uri() const;
  std::vector<std::string> discovery_urls() const;

  bool empty() const;

  bool operator==(ApplicationDescription const &rhs) const;
  bool operator!=(ApplicationDescription const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, ApplicationDescription const &op);

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H
