/**
 * @file main.cpp
 * @author Sean Dillon
 * @date 05 November 2013
 * @brief Entry point of http server application
 * @param Port number for the server
 */

#include "httpserver.h"

int main(int argc, char* argv[])
{
    unsigned short port = (argc > 1) ? atoi(argv[1]) : 9001;

    HttpServer server(port, "htdocs");
    server.run();

    return 0;
}

