#include <discpp/client.h>
#include <iostream>

namespace discpp
{
    Client::Client(const std::string &token) : token(token), ws(), queue()
    {
        // *ws = *WebSocket::from_url("wss://gateway.discord.gg/");
    }

    Client::~Client()
    {
    }

    const std::string &Client::getToken()
    {
        return token;
    }

    void Client::send(const std::string &msg)
    {
        queue.enqueue(msg);
    }

    void Client::start()
    {
        running = true;

        while (running && ws->getReadyState() != WebSocket::CLOSED)
        {
            ws->poll();
            ws->dispatch([](const std::string &msg)
                         { std::cerr << "MSG : " << msg << "\n"; });
            ws->send(queue.dequeue());
        }

#ifdef _WIN32
        WSACleanup();
#endif
    }

    void Client::stop()
    {
        running = false;
    }
}