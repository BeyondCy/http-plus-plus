#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "httpserver.h"
#include "httprequest.h"
#include "strategies/httpresponsefactory.h"

/**
 * @brief The HttpResponse class
 * @remarks Takes a parsed request and sends data back to its client
 */
class HttpResponse
{
public:
    HttpResponse(HttpRequest* request, const std::string &rootdir);
    ~HttpResponse();

    void respond();

private:
    HttpResponseStrategy* _responseStrategy;
    HttpRequest* _request;
    std::string _rootdir;
};

#endif // HTTPRESPONSE_H
