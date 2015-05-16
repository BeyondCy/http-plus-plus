#ifndef HTTPRESPONSEGET_H
#define HTTPRESPONSEGET_H

#include <fstream>
#include <string>

#include "httpresponsehead.h"

/**
 * @brief The HttpResponseGet class
 * @author Sean Dillon
 * @remarks HttpReponseStrategy handler for GET requests
 */
class HttpResponseGet : virtual public HttpResponseHead
{
public:
    virtual void response(HttpRequest* request, HttpResponseInfo* info);
};

#endif // HTTPRESPONSEGET_H
