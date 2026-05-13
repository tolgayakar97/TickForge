#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <iostream>
#include "Socket.h"

#define PORT_NUM 8080

class TcpServer {
public:
    TcpServer() = default;
    ~TcpServer() = default;

    TcpServer(const TcpServer& other) = delete;
    TcpServer& operator=(const TcpServer& other) = delete;

    void StartServer();
    void GetMessage();
private:
    Socket serverSocket_;
    Socket clientSocket_;
};

#endif