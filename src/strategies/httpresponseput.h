#ifndef HTTPRESPONSEPUT_H
#define HTTPRESPONSEPUT_H

#include <fstream>

#include "httpresponsestrategy.h"

/**
 * @brief The HttpResponsePut class
 * @remarks HttpReponseStrategy handler for PUT requests
 */
class HttpResponsePut : virtual public HttpResponseStrategy
{
public:
    virtual void response(HttpRequest* request, HttpResponseInfo* info);
};

#endif // HTTPRESPONSEPUT_H
