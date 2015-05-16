#ifndef HTTPRESPONSEDELETE_H
#define HTTPRESPONSEDELETE_H

#include <fstream>
#include <string>

#include "httpresponsehead.h"

/**
 * @brief The HttpResponseDelete class
 * @author Sean Dillon
 * @remarks HttpReponseStrategy handler for DELETE requests
 */
class HttpResponseDelete : virtual public HttpResponseHead
{
public:
    virtual void response(HttpRequest* request, HttpResponseInfo* info);
};

#endif // HTTPRESPONSEDELETE_H
