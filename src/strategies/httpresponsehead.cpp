#include "httpresponsehead.h"

void HttpResponseHead::response(HttpRequest *request, HttpResponseInfo *info)
{
    struct stat buf;
    int fd = stat(info->pathTo(request->file()).c_str(), &buf);

    if (fd == -1) // file doesn't exist
    {
        info->setCode(404);
    }
    else if (buf.st_mode & S_IROTH) // world readable
    {
        struct tm tm = *gmtime(&(buf.st_ctime));

        info->setCode(200);
        info->addHeader("Last-Modified: " + HttpResponseInfo::formatTime(tm));
    }
    else // not readable
    {
        info->setCode(403);
    }
}
