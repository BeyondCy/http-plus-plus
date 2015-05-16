###################################
# http++ makefile
###################################
CC = g++		# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O3 -Wall	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lpthread		# linked libraries	
LDFLAGS = -L.		# link flags
PROG = httpserver		# target executable (output)
OBJ = main.o \
    httpserver.o \
    httpthread.o \
    httprequest.o \
    tcpserver.o \
    tcpsocket.o \
    httpresponse.o \
    strategies/httpresponsefactory.o \
    httpresponseinfo.o \
    strategies/httpresponsehead.o \
    strategies/httpresponseget.o \
    strategies/httpresponsedelete.o \
    strategies/httpresponseput.o  
SRC = main.cpp \
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

all : $(PROG)

$(PROG): $(OBJ) 
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)


# cleanup
clean:
	/bin/rm -f *.o $(PROG)

# DO NOT DELETE
