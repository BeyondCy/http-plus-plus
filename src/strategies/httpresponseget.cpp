#include "httpresponseget.h"

void HttpResponseGet::response(HttpRequest *request, HttpResponseInfo *info)
{
    HttpResponseHead::response(request, info);

    if (info->code() != 200)
        return;

    std::ifstream ifs(info->pathTo(request->file()).c_str());
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                           (std::istreambuf_iterator<char>()    ) );

    info->setContent(content);
}
