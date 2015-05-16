#include "httpresponseput.h"

void HttpResponsePut::response(HttpRequest *request, HttpResponseInfo *info)
{
    std::ofstream outputFile(info->pathTo(request->file()).c_str());

    if (!outputFile.is_open())
    {
        info->setCode(500);
        return;
    }

    outputFile << request->content();
    info->setCode(201);
}
