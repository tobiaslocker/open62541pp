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
  json m_json;

 public:
  impl() {}

  impl(UA_ApplicationDescription const &application_description)
      : m_application_name{LocalizedText(
            application_description.applicationName)},
        m_application_type{
            ApplicationType(application_description.applicationType)} {
    if (application_description.discoveryUrls) {
      for (size_t i = 0; i < application_description.discoveryUrlsSize; ++i) {
        std::string s;
        s.assign(application_description.discoveryUrls[i].data,
                 application_description.discoveryUrls[i].data +
                     application_description.discoveryUrls[i].length);
        m_discovery_urls.push_back(s);
      }
    }
    m_application_uri.assign(application_description.applicationUri.data,
                             application_description.applicationUri.data +
                                 application_description.applicationUri.length);
    m_product_uri.assign(application_description.productUri.data,
                         application_description.productUri.data +
                             application_description.productUri.length);
    m_gateway_server_uri.assign(
        application_description.gatewayServerUri.data,
        application_description.gatewayServerUri.data +
            application_description.gatewayServerUri.length);
    m_discovery_profile_uri.assign(
        application_description.discoveryProfileUri.data,
        application_description.discoveryProfileUri.data +
            application_description.discoveryProfileUri.length);
  }

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

ApplicationDescription::ApplicationDescription()
    : d_ptr{std::make_unique<impl>()} {}

ApplicationDescription::ApplicationDescription(
    UA_ApplicationDescription const &a)
    : d_ptr{std::make_unique<impl>(a)} {}

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
