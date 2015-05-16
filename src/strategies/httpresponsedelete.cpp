#include "httpresponsedelete.h"

void HttpResponseDelete::response(HttpRequest *request, HttpResponseInfo *info)
{
    HttpResponseHead::response(request, info);

    if (info->code() != 200)
        return;

    if (remove(info->pathTo(request->file()).c_str()) == 0)
        info->setCode(202);
    else
        info->setCode(500);
}
