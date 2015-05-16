#include "httpserver.h"

int main(int argc, char* argv[])
{
    unsigned short port = (argc > 1) ? atoi(argv[1]) : 9001;

    HttpServer server(port, "htdocs");
    server.run();

    return 0;
}

