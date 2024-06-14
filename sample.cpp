#include <iostream>
#include <memory>
#include <stdexcept>

// Mock classes to simulate the original context
class HttpClientConfig {
public:
    void addInterceptor(std::unique_ptr<class OAuth2Interceptor> interceptor) {
        // Mock implementation
        std::cout << "Interceptor added" << std::endl;
    }
};

class OAuth2Interceptor {
public:
    OAuth2Interceptor(const std::string& authUrl) {
        // Mock implementation
        std::cout << "OAuth2Interceptor created with URL: " << authUrl << std::endl;
    }
};

class ServerConfig {
public:
    std::string getAuthUrl() const {
        return "https://auth.example.com";
    }
};

class AMSNDSLiveDownloader {
public:
    AMSNDSLiveDownloader(const std::shared_ptr<ServerConfig>& serverConfig)
        : m_serverConfig(serverConfig) {}

    std::unique_ptr<HttpClientConfig> getHttpClientConfig() {
        std::unique_ptr<HttpClientConfig> clientConfig = std::make_unique<HttpClientConfig>();
        std::unique_ptr<OAuth2Interceptor> oAuth = std::make_unique<OAuth2Interceptor>(m_serverConfig->getAuthUrl());

        if (clientConfig != nullptr && oAuth != nullptr) {
            clientConfig->addInterceptor(std::move(oAuth));
        }

        return clientConfig;
    }

private:
    std::shared_ptr<ServerConfig> m_serverConfig;
};

int main() {
    std::shared_ptr<ServerConfig> serverConfig = std::make_shared<ServerConfig>();
    AMSNDSLiveDownloader downloader(serverConfig);

    std::unique_ptr<HttpClientConfig> config = downloader.getHttpClientConfig(
