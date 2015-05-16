#ifndef HTTPTHREAD_H
#define HTTPTHREAD_H

#include <stdlib.h>

#include "tcpsocket.h"
#include "httprequest.h"
#include "httpresponse.h"

/**
 * @brief The start_httpthread() function
 * @remarks thread entry point for each client, matches pthread C calling convention
 */
extern "C" void* start_httpthread(void*);

/**
 * @brief The httpthread_args_t struct
 * @remarks passes a client TcpSocket and a string to the web root to the thread
 */
struct httpthread_args_t {
    TcpSocket* client;
    char rootdir[1024];
};


#endif // HTTPTHREAD_H
