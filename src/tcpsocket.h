#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <unistd.h>
#include <sys/socket.h>

#include <string>

/**
 * @brief The TcpSocket class
 * @author Sean Dillon
 * @remarks Helps with reading and writing of a TCP socket
 */
class TcpSocket
{
public:
    TcpSocket(int client);
    ~TcpSocket();

    std::string recieveAll();
    unsigned char recieveByte();
    std::string recieveBytes(int nBytes);
    std::string recieveLine(char delim = '\n');

    void transmit(const std::string& msg);

private:
    int _client;

};

#endif // TCPSOCKET_H
