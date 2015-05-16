#ifndef HTTPRESPONSEINFO_H
#define HTTPRESPONSEINFO_H

#include <string>
#include <vector>
#include <sstream>
#include <time.h>

/**
 * @brief The HttpResponseInfo class
 * @remarks Helps response texts to be constructed
 */
class HttpResponseInfo
{
public:
    HttpResponseInfo(const std::string &rootdir);

    std::string toString();

    inline unsigned int code() const { return this->_code; }
    inline void setCode(const unsigned int code) { this->_code = code; }

    std::string statusText();

    void addHeader(std::string header);

    inline void setContent(const std::string &str) { this->_content = str; }

    inline const std::string& rootDir() const { return this->_rootdir; }
    std::string pathTo(const std::string &file);

    static std::string formatTime(struct tm tm);
    static std::string currentTime();

private:
    unsigned int _code;
    std::vector<std::string> _headers;
    std::string _content;

    std::string _rootdir;
};

#endif // HTTPRESPONSEINFO_H
