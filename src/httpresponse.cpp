#include "httpresponse.h"

HttpResponse::HttpResponse(HttpRequest *request, const std::string &rootdir) :
    _request(request), _rootdir(rootdir)
{
    this->_responseStrategy =
            HttpResponseFactory::produce(this->_request->type());
}

HttpResponse::~HttpResponse()
{
    delete this->_responseStrategy;
}

void HttpResponse::respond()
{
    HttpResponseInfo info(this->_rootdir);
    info.addHeader("Date: " + HttpResponseInfo::currentTime());
    info.addHeader("Server: CS436 HW2 (Linux)");

    this->_responseStrategy->response(this->_request, &info);
    printf("Thread: %d\tResponse: %d %s\n", (unsigned int)pthread_self(), info.code(), info.statusText().c_str());
    this->_request->client()->transmit(info.toString());
}


