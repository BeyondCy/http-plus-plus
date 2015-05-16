#include "httpresponseinfo.h"

HttpResponseInfo::HttpResponseInfo(const std::string &rootdir)
    : _rootdir(rootdir)
{
}



std::string HttpResponseInfo::statusText()
{
    switch (this->code())
    {
    case 200:   return "OK";
    case 201:   return "Created";
    case 202:   return "Accepted";
    case 204:   return "No Content";
    case 301:   return "Moved Permanently";
    case 302:   return "Moved Temporarily";
    case 304:   return "Not Modified";
    case 400:   return "Bad Request";
    case 401:   return "Unauthorized";
    case 403:   return "Forbidden";
    case 404:   return "Not Found";
    case 500:   return "Internal Server Error";
    case 501:   return "Not Implemented";
    case 502:   return "Bad Gateway";
    case 503:   return "Service Unavailable";
    default:    return "Unknown";
    }
}


std::string HttpResponseInfo::toString()
{
    std::stringstream ret;
    ret << "HTTP/1.0 " << this->code() << " " << this->statusText() << "\r\n";

    std::vector<std::string>::size_type numHeaders = this->_headers.size();

    for(std::vector<std::string>::size_type i = 0; i != numHeaders; ++i)
        ret << this->_headers[i] << "\r\n";

    if (!this->_content.empty())
    {
        ret << "Content-Length: " << this->_content.size() << "\r\n";
        ret << "\r\n" << this->_content << "\r\n";
    }

    ret << "\r\n";

    return ret.str();
}

void HttpResponseInfo::addHeader(std::string header)
{
    this->_headers.push_back(header);
}


std::string HttpResponseInfo::formatTime(tm tm)
{
    char buf[100];
    strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
    return buf;
}

std::string HttpResponseInfo::currentTime()
{
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    return HttpResponseInfo::formatTime(tm);
}


std::string HttpResponseInfo::pathTo(const std::string &file)
{
    return this->_rootdir + file;
}
