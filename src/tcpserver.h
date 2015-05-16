#ifndef SOCKET_H
#define SOCKET_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdexcept>

#include "tcpsocket.h"

/**
 * @brief The TcpServer class
 * @remarks Creates socket, binds to port, and listens to it
 * @abstract
 */
class TcpServer
{
public:
    TcpServer(unsigned short port);
    virtual ~TcpServer();

    virtual void run() = 0;

    class SocketOpenException {};
    class SocketBindException {};
    class SocketListenException {};
    class SocketAcceptException {};

protected:
    void openSocket();
    void bindPort();
    void listenSocket();
    void closeSocket();
    /* accepts a client, returns their socket descriptor */
    TcpSocket* acceptClient(); // must be freed by the caller

private:
    int	_sock; /* master socket */
    unsigned short _port;
    struct sockaddr_in _servAddr; /* Local address */
};



#endif // SOCKET_H
