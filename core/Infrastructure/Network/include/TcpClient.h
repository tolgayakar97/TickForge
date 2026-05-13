#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <iostream>
#include "Socket.h"

#define PORT_NUM 8080

class TcpClient {
public:
    TcpClient() = default;
    ~TcpClient();

    TcpClient(const TcpClient& other) = delete;
    TcpClient& operator=(const TcpClient& other) = delete;

    void StartServer();
    void SendMessage(const char* msg);
private:
    int clientSocket_;
};

#endif