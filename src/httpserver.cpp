#include "httpserver.h"

HttpServer::HttpServer(unsigned short port, const std::string &rootdir)
    : TcpServer(port)
{
    this->setRootDir(rootdir);
}

void HttpServer::run()
{
    TcpSocket* client = 0; /* client socket */
    pthread_t tid;  /* thread id */
    struct httpthread_args_t * threadArgs;

    while (true)
    {
        client = this->acceptClient();

        threadArgs = (struct httpthread_args_t *) malloc(sizeof(struct httpthread_args_t));
        threadArgs->client = client;
        strncpy(threadArgs->rootdir, this->_rootdir.c_str(), 1024);

        printf("Creating new thread\n");
        pthread_create(&tid, NULL, &start_httpthread,(void *) threadArgs);
    }
}

void HttpServer::setRootDir(const std::string &dir)
{
    if (dir.size() > 0 && dir[0] != '/') // relative path
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            this->_rootdir = std::string(cwd) + "/" + dir;
    }
    else                                 // absolute path
    {
        this->_rootdir = dir;
    }

    if (*this->_rootdir.rbegin() != '/')  // append trailing slash if needed
        this->_rootdir += "/";
}
