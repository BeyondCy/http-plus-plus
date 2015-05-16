#ifndef HTTPRESPONSEHEAD_H
#define HTTPRESPONSEHEAD_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "httpresponsestrategy.h"

/**
 * @brief The HttpResponseHead class
 * @author Sean Dillon
 * @remarks HttpReponseStrategy handler for HEAD requests
 */
class HttpResponseHead : virtual public HttpResponseStrategy
{
public:
    virtual void response(HttpRequest* request, HttpResponseInfo* info);
};

#endif // HTTPRESPONSEHEAD_H
