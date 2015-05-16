#include "tcpsocket.h"

TcpSocket::TcpSocket(int client) :
    _client(client)
{
}

TcpSocket::~TcpSocket()
{
    close(this->_client);
}

std::string TcpSocket::recieveAll()
{
   char mesg[99999];
   recv(this->_client, mesg, 99999, 0);
   return mesg;
}

void TcpSocket::transmit(const std::string &msg)
{
    send(this->_client, msg.c_str(), msg.size(), 0);
}


std::string TcpSocket::recieveLine(char delim)
{
    char lastChar = '\0';
    std::string ret = "";
    do
    {
        lastChar = this->recieveByte();
        ret += lastChar;
    }
    while (lastChar != delim && lastChar != '\0');

    return ret;
}


unsigned char TcpSocket::recieveByte()
{
    unsigned char buf[1];
    return recv(this->_client, buf, 1, 0) > 0 ? buf[0] : '\0';
}

std::string TcpSocket::recieveBytes(int nBytes)
{
    std::string ret = "";
    char lastChar = '\0';
    for (int i = 0; i < nBytes; ++i)
    {
        lastChar = this->recieveByte();
        if (lastChar == '\0')
            break;
        ret += lastChar;
    }
    return ret;
}
