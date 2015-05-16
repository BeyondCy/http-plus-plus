# http++
http++ is a fully featured web server written in C++. The Unix socket library is used to create a TCP server which binds to a port specified on the command line.  It uses the C pthread library so that each request is processed in a new thread, allowing it to be very responsive. These libraries should be abandoned for the C++11 standard library in the future.

The web server can handle GET, POST, HEAD, PUT, and DELETE http requests.  It sends all of the widely used http response status codes.  It also has the ability to transmit images and downloadable files.  It can handle interactions via telnet or any standard web browser.

The screenshot below shows the server being compiled from a Makefile.  The server is bound to the localhost on port 9001 and then handles a GET and PUT request from Google Chrome.

![](http://i.imgur.com/y04ejxy.png)

### Usage
```
root@server:~# git clone https://github.com/zerosum0x0/http-plus-plus.git
root@server:~# cd http-plus-plus/src
root@server:~# make
root@server:~# ./httpserver 9001
```
At the webroot (found in src/htdocs/) there is an index.html file that has some AJAX for simpler testing of the capabilities of the system.


### Operation
The web server itself is written almost completely in C++, except for one extern C function for use with the pthread library.  There is an abstract TcpServer class that HttpServer inherits, implementing its run() method to construct thread args and a pointer to the thread function.  

In the thread, there is an HttpRequest class that reads the TcpSocket client and parses the data sent.  This information is passed to a HttpResponse object, which uses the strategy pattern to handle the request.
