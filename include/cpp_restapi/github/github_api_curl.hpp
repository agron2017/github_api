
#ifndef GITHUBAPI_CURL_HPP
#define GITHUBAPI_CURL_HPP

#include <memory>

#include "cpp_restapi/iconnection.hpp"
#include "github_api_base.hpp"
#include "cpp_restapi_export.h"

namespace cpp_restapi::GitHub::CurlBackend
{
    /**
     * @brief Class for establishing connection with GitHub api with Curl. Deprecated, use @ref cpp_restapi::GitHub::ConnectionBuilder instead
     */
    class CPP_RESTAPI_DEPRECATED_EXPORT Api: public cpp_restapi::GitHubBase
    {
        public:
            Api(const std::string& addr = "https://api.github.com");
            Api(const Api &) = delete;
            ~Api();

            std::unique_ptr<cpp_restapi::IConnection> connect(const std::string& token = "") override;

            Api& operator=(const Api &) = delete;
    };

}

#endif
