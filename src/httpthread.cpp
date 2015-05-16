#include "httpthread.h"

void* start_httpthread(void* data)
{
    struct httpthread_args_t* args = static_cast<httpthread_args_t*>(data);

    HttpRequest request(args->client);
    HttpResponse response(&request, args->rootdir);

    response.respond();

    free(data);
    pthread_exit(0);
}
