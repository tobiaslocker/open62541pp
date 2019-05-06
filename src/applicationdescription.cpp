#include "applicationdescription.hpp"

namespace open62541 {

ApplicationDescription::ApplicationDescription(
    UA_ApplicationDescription const &application_description)
    : m_application_name{LocalizedText(
          application_description.applicationName)},
      m_application_type{
          ApplicationType(application_description.applicationType)} {
  if (application_description.discoveryUrls) {
    for (size_t i = 0; i < application_description.discoveryUrlsSize; ++i) {
      if (auto c = reinterpret_cast<char *>(
              application_description.discoveryUrls[i].data)) {
        m_discovery_urls.push_back(
            std::string(c, application_description.discoveryUrls[i].length));
        BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace)
            << "Appending discovery url "
            << m_discovery_urls.at(m_discovery_urls.size() - 1);
      } else {
        BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No discovery URL";
      }
    }
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No discovery URLS";
  }

  if (auto c = reinterpret_cast<char *>(
          application_description.applicationUri.data)) {
    m_application_uri =
        std::string(c, application_description.applicationUri.length);
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace)
        << "Application URI = " << m_application_uri;
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No application URI";
  }

  if (auto c =
          reinterpret_cast<char *>(application_description.productUri.data)) {
    m_product_uri = std::string(c, application_description.productUri.length);
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace)
        << "Product URI = " << m_product_uri;
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No product URI";
  }
  if (auto c = reinterpret_cast<char *>(
          application_description.gatewayServerUri.data)) {
    m_gateway_server_uri =
        std::string(c, application_description.gatewayServerUri.length);
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace)
        << "Gateway server URI " << m_gateway_server_uri;
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No gateway server URI";
  }
  if (auto c = reinterpret_cast<char *>(
          application_description.discoveryProfileUri.data)) {
    m_discovery_profile_uri =
        std::string(c, application_description.discoveryProfileUri.length);
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace)
        << "Discovery profile URI " << m_discovery_profile_uri;
  } else {
    BOOST_LOG_CHANNEL_SEV(m_lg, m_channel, trace) << "No discovery profile URI";
  }
}

std::string ApplicationDescription::application_uri() const {
  return m_application_uri;
}

std::string ApplicationDescription::product_uri() const {
  return m_product_uri;
}

LocalizedText ApplicationDescription::application_name() const {
  return m_application_name;
}

ApplicationType ApplicationDescription::application_type() const {
  return m_application_type;
}

std::string ApplicationDescription::gateway_server_uri() const {
  return m_gateway_server_uri;
}

std::string ApplicationDescription::discovery_profile_uri() const {
  return m_discovery_profile_uri;
}

std::vector<std::string> ApplicationDescription::discovery_urls() const {
  return m_discovery_urls;
}

json ApplicationDescription::to_json() const {
  json j;
  j["ApplicationUri"] = m_application_uri;
  j["ProductUri"] = m_product_uri;
  j["ApplicationName"] = m_application_name.text();
  switch (m_application_type) {
    case ApplicationType::Server:
      j["ApplicationType"] = "Server";
      break;
    case ApplicationType::Client:
      j["ApplicationType"] = "Client";
      break;
    case ApplicationType::ClientAndServer:
      j["ApplicationType"] = "ClientAndServer";
      break;
    case ApplicationType::DiscoveryServer:
      j["ApplicationType"] = "DiscoveryServer";
      break;
  }
  j["GatewayServerUri"] = m_gateway_server_uri;
  j["DiscoveryProfileUri"] = m_discovery_profile_uri;
  j["DiscoveryUrls"] = m_discovery_urls;
  return j;
}

}  // namespace open62541
