TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    httpserver.cpp \
    httpthread.cpp \
    httprequest.cpp \
    tcpserver.cpp \
    tcpsocket.cpp \
    httpresponse.cpp \
    strategies/httpresponsefactory.cpp \
    httpresponseinfo.cpp \
    strategies/httpresponsehead.cpp \
    strategies/httpresponseget.cpp \
    strategies/httpresponsedelete.cpp \
    strategies/httpresponseput.cpp

HEADERS += \
    httpserver.h \
    httpthread.h \
    httprequest.h \
    tcpserver.h \
    tcpsocket.h \
    httpresponse.h \
    httpresponseinfo.h \
    httpresponseput.h \
    strategies/httpresponsestrategy.h \
    strategies/httpresponseget.h \
    strategies/httpresponsehead.h \
    strategies/httpresponsedelete.h \
    strategies/httpresponsefactory.h \
    strategies/httpresponseput.h

LIBS += -pthread

