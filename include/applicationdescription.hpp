#ifndef OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H
#define OPEN62541_CPP_WRAPPER_APPLICATION_DESCRIPTION_H

#include "open62541.h"

// STL
#include <string>
#include <vector>

// Dependencies
#include <nlohmann/json.hpp>

#include "localizedtext.hpp"

namespace open62541 {
using namespace nlohmann;

enum class ApplicationType : u_int32_t {
  Server = 0,
  Client = 1,
  ClientAndServer = 2,
  DiscoveryServer = 3,
};

std::ostream &operator<<(std::ostream &out, ApplicationType const &a);

class ApplicationDescription {
  std::string m_application_uri;
  std::string m_product_uri;
  LocalizedText m_application_name;
  ApplicationType m_application_type;
  std::string m_gateway_server_uri;
  std::string m_discovery_profile_uri;
  std::vector<std::string> m_discovery_urls;
  json m_json;
  ApplicationDescription(
      UA_ApplicationDescription const &application_description);

 public:
  ApplicationDescription() {}

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
