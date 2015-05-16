#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <stdlib.h>
#include <time.h>

#include "tcpserver.h"
#include "httpthread.h"
#include "httprequest.h"

/**
 * @brief The HttpServer class
 * @remarks Overrides TcpServer::run() to spawn a new thread for each http request
 */
class HttpServer : public TcpServer
{
public:
    explicit HttpServer(unsigned short port, const std::string &rootDir);

    virtual void run();

    void setRootDir(const std::string &dir);

private:
    std::string _rootdir;
};

#endif // HTTPSERVER_H
