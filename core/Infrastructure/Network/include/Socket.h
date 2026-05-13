#ifndef SOCKET_H
#define SOCKET_H

class Socket {
public:
    Socket() = default;
    Socket(const Socket& other) = delete;
    Socket& operator=(const Socket& other) = delete; 
    ~Socket();
    void CreateSocket();
    int GetSocketFd() const;
    void SetSocketFd(const int& socket_fd);
private:
    int socket_fd_;
};

#endif