#ifndef HTTPRESPONSEFACTORY_H
#define HTTPRESPONSEFACTORY_H

#include "../httprequest.h"
#include "httpresponsestrategy.h"
#include "httpresponsehead.h"
#include "httpresponseget.h"
#include "httpresponsedelete.h"
#include "httpresponseput.h"

/**
 * @brief The HttpResponseFactory class
 * @remarks Returns a strategy for handling an HttpRequest
 */
class HttpResponseFactory
{
    HttpResponseFactory();

public:
    /**
     * @brief produce
     * @remarks Caller must delete allocated strategy
     */
    static HttpResponseStrategy* produce(HttpRequest::Type requestType);
};

#endif // HTTPRESPONSEFACTORY_H
