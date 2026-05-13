#include <iostream>
#include <chrono>
#include <thread>
#include "TcpClient.h"

int main()
{
    TcpClient tcpClient;
    tcpClient.StartServer();
    tcpClient.SendMessage("Hello from tcpClient 1\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    tcpClient.SendMessage("Hello from tcpClient 2\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    tcpClient.SendMessage("Hello from tcpClient 3\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    tcpClient.SendMessage("Hello from tcpClient 4\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    tcpClient.SendMessage("Hello from tcpClient 5\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    tcpClient.SendMessage("exit\n");
    return 0;
}