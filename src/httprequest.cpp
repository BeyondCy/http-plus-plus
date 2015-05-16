#include "httprequest.h"

HttpRequest::HttpRequest(TcpSocket* client)
    : _type(HttpRequest::HTTPUNKNOWN), _client(client)
{
    this->recieveAll();
}

HttpRequest::~HttpRequest()
{
    delete this->_client;
}

void HttpRequest::recieveAll()
{
    std::string tmp = "";

    this->firstHeader(this->client()->recieveLine());

    while (true)
    {
        tmp = this->_client->recieveLine();
        if (tmp == "\r\n" || tmp == "\n")
            break;

        this->addHeader(tmp);
    }

    if (this->_headers.find("Content-Length") != this->_headers.end())
    {
        int nBytes = atoi(this->_headers.at("Content-Length").c_str());
        this->_content = this->client()->recieveBytes(nBytes);
    }
}

void HttpRequest::parse(const std::string &rawData)
{
    std::vector<std::string> lines = this->split(rawData, '\n');

    std::vector<std::string>::size_type numLines = lines.size();

    for(std::vector<std::string>::size_type i = 0; i != numLines; ++i)
    {
        if (i == 0)
        {
            this->firstHeader(lines[i]);
            continue;
        }
    }
}

std::vector<std::string> &HttpRequest::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
        elems.push_back(item);

    return elems;
}

std::vector<std::string> HttpRequest::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::string HttpRequest::join(std::vector<std::string> elems)
{
    std::stringstream ss;
    std::copy(elems.begin(), elems.end(),
        std::ostream_iterator<std::string>(ss));

    return ss.str();
}

std::string &HttpRequest::ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::string &HttpRequest::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

std::string &HttpRequest::trim(std::string &s)
{
    return ltrim(rtrim(s));
}

std::string &HttpRequest::clean(std::string &s)
{
    this->trim(s);
    char chars[] = "\r\n";

    for (unsigned int i = 0; i < strlen(chars); ++i)
        s.erase (std::remove(s.begin(), s.end(), chars[i]), s.end());

    return s;
}

void HttpRequest::firstHeader(const std::string &line)
{
    printf("Thread: %d\tRequest: %s", (unsigned int)pthread_self(), line.c_str());
    std::vector<std::string> args = this->split(line, ' ');

    if (args.size() < 2)
        return;

    if (args[0].compare("GET") == 0)
        this->_type = HttpRequest::HTTPGET;
    else if (args[0].compare("HEAD") == 0)
        this->_type = HttpRequest::HTTPHEAD;
    else if (args[0].compare("PUT") == 0)
        this->_type = HttpRequest::HTTPPUT;
    else if (args[0].compare("DELETE") == 0)
        this->_type = HttpRequest::HTTPDELETE;
    else
        this->_type = HttpRequest::HTTPUNKNOWN;

    this->setFile(args[1]);
}

void HttpRequest::setFile(const std::string &file)
{
    this->_file = file;
    this->clean(this->_file);
    this->trim(this->_file);

    if (*this->_file.rbegin() == '/') // set default file
        this->_file += "index.html";
}

void HttpRequest::addHeader(const std::string &line)
{
    std::size_t offset = line.find(":");
    if (offset == std::string::npos)
        return;

    std::string key = line.substr(0, offset);
    std::string val = line.substr(offset+1);

    this->clean(key);
    this->clean(val);

    this->_headers[key] = val;
}
