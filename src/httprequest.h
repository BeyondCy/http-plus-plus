#ifndef HTTPPARSER_H
#define HTTPPARSER_H

#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <iterator>

#include "tcpsocket.h"

/**
 * @brief The HttpRequest class
 * @author Sean Dillon
 * @remarks Reads a client socket and parses the raw http data
 */
class HttpRequest
{
public:
    HttpRequest(TcpSocket* client);
    ~HttpRequest();

    enum Type { HTTPUNKNOWN = 0, HTTPGET, HTTPHEAD, HTTPPUT, HTTPDELETE };

    inline HttpRequest::Type type() const { return this->_type; }
    inline std::string file() const { return this->_file; }
    inline std::string content() const { return this->_content; }
    inline TcpSocket* client() const { return this->_client; }

protected:
    void recieveAll();

    void parse(const std::string &rawData);
    void firstHeader(const std::string &line);
    void setFile(const std::string &file);
    void addHeader(const std::string &line);

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);

    std::string join(std::vector<std::string> elems);

    std::string &ltrim(std::string &s);
    std::string &rtrim(std::string &s);
    std::string &trim(std::string &s);

    std::string &clean(std::string &s);

private:    
    HttpRequest::Type _type;
    std::string _file;
    std::string _content;

    std::map<std::string, std::string> _headers;

    TcpSocket* _client;
};

#endif // HTTPPARSER_H
