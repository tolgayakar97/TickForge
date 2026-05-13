#include <sys/socket.h>
#include <unistd.h>
#include <memory>
#include <netinet/in.h>
#include "TcpClient.h"

TcpClient::~TcpClient()
{
    std::cout << "Dtor called client" << std::endl;
    close(clientSocket_);
}

void TcpClient::StartServer()
{
    // Sokcket creation
    clientSocket_ = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "TcpClient: " << clientSocket_ << std::endl;

    // Defining server address
    sockaddr_in clientAddr{};
    clientAddr.sin_family = AF_INET; // Ipv4 connection.
    clientAddr.sin_port = htons(PORT_NUM); // htons converts uint to network bytes.

    // Connecting to a server
    auto ret = connect(clientSocket_, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
    if (ret == -1) {
        return;
    }
}

void TcpClient::SendMessage(const char* msg)
{
    send(clientSocket_, msg, strlen(msg), 0);
}