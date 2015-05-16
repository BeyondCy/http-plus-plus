#include "tcpserver.h"

TcpServer::TcpServer(unsigned short port) : _port(port)
{
    this->openSocket();
    this->bindPort();
    this->listenSocket();
}

TcpServer::~TcpServer()
{
    this->closeSocket();
}

TcpSocket* TcpServer::acceptClient()
{
    int clientsd = 0;                    /* Socket descriptor for client */
    struct sockaddr_in clientAddr; /* Client address */
    unsigned int clntLen = 0;            /* Length of client address data structure */

    /* Set the size of the in-out parameter */
    clntLen = sizeof(clientAddr);

    /* Wait for a client to connect */
    if ((clientsd = accept(this->_sock, (struct sockaddr *) &clientAddr, &clntLen)) < 0)
        throw SocketAcceptException();

    return new TcpSocket(clientsd);
}


void TcpServer::openSocket()
{
    /* create socket */
    if ((this->_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        throw SocketOpenException();
}

void TcpServer::bindPort()
{
    /* Construct local address structure */
    memset(&this->_servAddr, 0, sizeof(this->_servAddr));   /* Zero out structure */
    this->_servAddr.sin_family = AF_INET;                /* Internet address family */
    this->_servAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    this->_servAddr.sin_port = htons(this->_port);              /* Local port */

    /* Bind to the local address */
    if (bind(this->_sock, (struct sockaddr *) &this->_servAddr, sizeof(this->_servAddr)) < 0)
        throw SocketBindException();
}

void TcpServer::listenSocket()
{
    if (listen(this->_sock, 100) < 0)
        throw SocketListenException();
}

void TcpServer::closeSocket()
{
    close(this->_sock);
}
