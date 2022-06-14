#ifndef __DISCPP_CLIENT_H__
#define __DISCPP_CLIENT_H__

#include <discpp/definitions.h>
#include <string>
#include <memory>

namespace discpp
{
    class Client
    {
    private:
        const std::string token;
        SafeQueue<std::string> queue;
        bool running;

    public:
        Client(const std::string &token);
        ~Client();

        const std::string &getToken();

        void send(const std::string &msg);

        void start();
        void stop();
    };
}

#endif // __DISCPP_CLIENT_H__