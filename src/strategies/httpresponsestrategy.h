#ifndef HTTPRESPONSESTRATEGY_H
#define HTTPRESPONSESTRATEGY_H

#include "../httprequest.h"
#include "../httpresponseinfo.h"

/**
 * @brief The HttpResponseStrategy class
 * @author Sean Dillon
 * @remarks Represents a way to handle different requests (GET, HEAD, etc.)
 * @abstract
 */
class HttpResponseStrategy
{
public:
    virtual ~HttpResponseStrategy() {}
    virtual void response(HttpRequest* request, HttpResponseInfo* info) = 0;
};

/**
 * @brief The HttpResponseUnimplemented class
 * @author Sean Dillon
 * @remarks HttpReponseStrategy handler for UNKNOWN requests
 */
class HttpResponseUnimplemented : virtual public HttpResponseStrategy
{
    virtual void response(HttpRequest*, HttpResponseInfo* info)
    {
        info->setCode(501);
    }
};

#endif // HTTPRESPONSESTRATEGY_H
