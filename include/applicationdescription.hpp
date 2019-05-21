#ifndef OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H

#include "open62541.h"

// STL
#include <string>
#include <vector>

// Dependencies
#include <nlohmann/json.hpp>

#include "enums.hpp"
#include "localizedtext.hpp"

namespace open62541 {
using namespace nlohmann;

class ApplicationDescription {
  class impl;
  std::unique_ptr<impl> d_ptr;
  friend std::ostream &operator<<(std::ostream &out,
                                  impl const &application_description);

 public:
  ApplicationDescription(std::string const &application_uri,
                         std::string const &product_uri,
                         LocalizedText const &application_name,
                         ApplicationType const &application_type,
                         std::string const &gateway_server_uri,
                         std::string const &discovery_profile_uri,
                         std::vector<std::string> const &discovery_urls);

  ApplicationDescription();
  ~ApplicationDescription();
  ApplicationDescription(ApplicationDescription &&) noexcept;
  ApplicationDescription &operator=(ApplicationDescription &&) noexcept;
  ApplicationDescription(ApplicationDescription const &);
  ApplicationDescription &operator=(ApplicationDescription const &);

  std::string application_uri() const;
  std::string product_uri() const;
  LocalizedText application_name() const;
  ApplicationType application_type() const;
  std::string gateway_server_uri() const;
  std::string discovery_profile_uri() const;
  std::vector<std::string> discovery_urls() const;

  json to_json() const;

  bool operator==(ApplicationDescription const &rhs) const;
  bool operator!=(ApplicationDescription const &rhs) const;
  friend std::ostream &operator<<(
      std::ostream &out, ApplicationDescription const &application_description);

  friend class EndpointDescription;
};

}  // namespace open62541

#endif  // OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H
