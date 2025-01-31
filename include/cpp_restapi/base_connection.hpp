
#ifndef BASE_CONNECTION_HPP_INCLUDED
#define BASE_CONNECTION_HPP_INCLUDED

#include <map>

#include <cpp_restapi/iconnection.hpp>


namespace cpp_restapi
{
    /**
     * @brief base class with common parts for backend specific implementations
     */
    class BaseConnection: public cpp_restapi::IConnection
    {
    public:
        [[deprecated]] explicit BaseConnection(const std::string& address, const std::string& token);
        explicit BaseConnection(const std::string& address, const std::map<std::string, std::string>& headerEntries);

        std::string get(const std::string &) final;
        const std::string& url() const final;
        virtual std::pair<std::string, std::string> fetchPage(const std::string& request) = 0;

    protected:
        const std::map<std::string, std::string>& getHeaderEntries() const;

        const std::string& address() const;

    private:
        const std::string m_address;
        std::map<std::string, std::string> m_headerEntries;
    };
}

#endif
