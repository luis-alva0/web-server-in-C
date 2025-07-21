#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

struct Server
{
    int domain;
    int service;
    int protocol;
    __u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    int socket;

    void (*launch)(struct Server *server); //member function for launching the server
};

struct Server server_constructor(int domain, int service, int protocol, __u_long interface, int port, int backlog, void(*launch)(struct Server *server));

#endif