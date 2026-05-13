#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory>
#include "TcpServer.h"

void TcpServer::StartServer()
{
    // Sokcket creation
    serverSocket_.CreateSocket();
    std::cout << "TcpServer server: " << serverSocket_.GetSocketFd() << std::endl;

    // Forcefully attaching socket to the port 8080
    int enable = 1;
    if (setsockopt(serverSocket_.GetSocketFd(), SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        std::cout << "setsockopt(SO_REUSEADDR) failed" << std::endl;
    }

    // Defining server address
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET; // Ipv4 connection.
    serverAddr.sin_port = htons(PORT_NUM); // htons converts uint to network bytes.
    serverAddr.sin_addr.s_addr = INADDR_ANY; // accepts connection on any ip

    // bind socket to address
    std::cout << "Binding!" << std::endl;
    auto ret = bind(serverSocket_.GetSocketFd(), (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (ret < 0) {
        std::cout << "Binding failed!" << std::endl;
        return;
    }

    // Listen for incoming connections
    std::cout << "Listening!" << std::endl;
    ret = listen(serverSocket_.GetSocketFd(), 3);
    if (ret == -1) {
        std::cout << "Listen failed!" << std::endl;
        return;
    }

    // Accepting incoming connections from client
    std::cout << "Accepting!" << std::endl;
    sockaddr_in clientAddr{};
    clientSocket_.SetSocketFd(accept(serverSocket_.GetSocketFd(), (struct sockaddr*)&clientAddr, (socklen_t*)&clientAddr));
    std::cout << "TcpServer client: " << clientSocket_.GetSocketFd() << std::endl;
    if (ret == -1) {
        std::cout << "Accept failed!" << std::endl;
        return;
    }

}

void TcpServer::GetMessage()
{
    bool exit{false};
    while(!exit)
    {
        char buffer[1024] = {0};
        auto size = recv(clientSocket_.GetSocketFd(), buffer, sizeof(buffer), 0);
        if (size <= 0) {
            std::cout << "Size is 0" << std::endl;
        }

        std::cout << "Message: "  << buffer << std::endl;
        if(strcmp(buffer, "exit\n") == 0)
        {
            exit = true;
        }
    }
}