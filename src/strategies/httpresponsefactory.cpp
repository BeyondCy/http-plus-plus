#include "httpresponsefactory.h"

HttpResponseFactory::HttpResponseFactory()
{
}

HttpResponseStrategy* HttpResponseFactory::produce(HttpRequest::Type requestType)
{
    switch(requestType)
    {
    case HttpRequest::HTTPGET:
        return new HttpResponseGet();
    case HttpRequest::HTTPHEAD:
        return new HttpResponseHead();
    case HttpRequest::HTTPPUT:
        return new HttpResponsePut();
    case HttpRequest::HTTPDELETE:
        return new HttpResponseDelete();
    case HttpRequest::HTTPUNKNOWN:
    default:
        return new HttpResponseUnimplemented();
    }
}
