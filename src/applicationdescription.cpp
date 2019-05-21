#include "applicationdescription.hpp"

namespace open62541 {

class ApplicationDescription::impl {
  std::string m_application_uri;
  std::string m_product_uri;
  LocalizedText m_application_name;
  ApplicationType m_application_type;
  std::string m_gateway_server_uri;
  std::string m_discovery_profile_uri;
  std::vector<std::string> m_discovery_urls;

 public:
  impl() {}

  impl(std::string application_uri,
       std::string product_uri,
       LocalizedText application_name,
       ApplicationType application_type,
       std::string gateway_server_uri,
       std::string discovery_profile_uri,
       std::vector<std::string> discovery_urls)
      : m_application_uri{application_uri},
        m_product_uri{product_uri},
        m_application_name{application_name},
        m_application_type{application_type},
        m_gateway_server_uri{gateway_server_uri},
        m_discovery_profile_uri{discovery_profile_uri},
        m_discovery_urls{discovery_urls} {}

  std::string application_uri() const { return m_application_uri; }

  std::string product_uri() const { return m_product_uri; }

  LocalizedText application_name() const { return m_application_name; }

  ApplicationType application_type() const { return m_application_type; }

  std::string gateway_server_uri() const { return m_gateway_server_uri; }

  std::string discovery_profile_uri() const { return m_discovery_profile_uri; }

  std::vector<std::string> discovery_urls() const { return m_discovery_urls; }

  json to_json() const {
    json app_description;
    app_description["ApplicationUri"] = m_application_uri;
    app_description["ProductUri"] = m_product_uri;
    app_description["ApplicationName"] = m_application_name.text();
    switch (m_application_type) {
      case ApplicationType::Server:
        app_description["ApplicationType"] = "Server";
        break;
      case ApplicationType::Client:
        app_description["ApplicationType"] = "Client";
        break;
      case ApplicationType::ClientAndServer:
        app_description["ApplicationType"] = "ClientAndServer";
        break;
      case ApplicationType::DiscoveryServer:
        app_description["ApplicationType"] = "DiscoveryServer";
        break;
    }
    app_description["GatewayServerUri"] = m_gateway_server_uri;
    app_description["DiscoveryProfileUri"] = m_discovery_profile_uri;
    app_description["DiscoveryUrls"] = m_discovery_urls;
    return app_description;
  }

  bool operator==(const impl &rhs) const {
    return product_uri() == rhs.product_uri() &&
           discovery_urls() == rhs.discovery_urls() &&
           application_uri() == rhs.application_uri() &&
           application_name() == rhs.application_name() &&
           application_type() == rhs.application_type() &&
           gateway_server_uri() == rhs.gateway_server_uri();
  }

  bool operator!=(const impl &rhs) const {
    return product_uri() != rhs.product_uri() &&
           discovery_urls() != rhs.discovery_urls() &&
           application_uri() != rhs.application_uri() &&
           application_name() != rhs.application_name() &&
           application_type() != rhs.application_type() &&
           gateway_server_uri() != rhs.gateway_server_uri();
  }
};

std::ostream &operator<<(
    std::ostream &out,
    const ApplicationDescription::impl &application_description) {
  auto j = application_description.to_json();
  out << j;
  return out;
}

ApplicationDescription::ApplicationDescription(
    const std::string &application_uri,
    const std::string &product_uri,
    const LocalizedText &application_name,
    const ApplicationType &application_type,
    const std::string &gateway_server_uri,
    const std::string &discovery_profile_uri,
    const std::vector<std::string> &discovery_urls)
    : d_ptr{std::make_unique<impl>(application_uri,
                                   product_uri,
                                   application_name,
                                   application_type,
                                   gateway_server_uri,
                                   discovery_profile_uri,
                                   discovery_urls)} {}

ApplicationDescription::ApplicationDescription()
    : d_ptr{std::make_unique<impl>()} {}

ApplicationDescription::ApplicationDescription(ApplicationDescription const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

ApplicationDescription &ApplicationDescription::operator=(
    ApplicationDescription const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

std::string ApplicationDescription::application_uri() const {
  return d_ptr->application_uri();
}

std::string ApplicationDescription::product_uri() const {
  return d_ptr->product_uri();
}

LocalizedText ApplicationDescription::application_name() const {
  return d_ptr->application_name();
}

ApplicationType ApplicationDescription::application_type() const {
  return d_ptr->application_type();
}

std::string ApplicationDescription::gateway_server_uri() const {
  return d_ptr->gateway_server_uri();
}

std::string ApplicationDescription::discovery_profile_uri() const {
  return d_ptr->discovery_profile_uri();
}

std::vector<std::string> ApplicationDescription::discovery_urls() const {
  return d_ptr->discovery_urls();
}

json ApplicationDescription::to_json() const { return d_ptr->to_json(); }

bool ApplicationDescription::operator==(
    const ApplicationDescription &rhs) const {
  return *d_ptr == *rhs.d_ptr;
}

bool ApplicationDescription::operator!=(
    const ApplicationDescription &rhs) const {
  return *d_ptr != *rhs.d_ptr;
}

std::ostream &operator<<(
    std::ostream &out, const ApplicationDescription &application_description) {
  out << *application_description.d_ptr;
  return out;
}

}  // namespace open62541
