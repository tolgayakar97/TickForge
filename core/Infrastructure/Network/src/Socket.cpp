#include <iostream> 
#include <sys/socket.h>
#include <unistd.h>
#include "Socket.h"

void Socket::CreateSocket()
{
    socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd_ == -1) {
        std::cout << "SetSocketFd (socket) failed" << std::endl;
        return;
    }
    else {
        std::cout << "SetSocketFd (socket_fd: " << socket_fd_ << ") created successfully!" << std::endl;
    }
}

Socket::~Socket()
{
    if (socket_fd_ >= 0) close(socket_fd_);
}

int Socket::GetSocketFd() const
{
    return socket_fd_;
}

void Socket::SetSocketFd(const int& socket_fd)
{
    socket_fd_ = socket_fd;
}