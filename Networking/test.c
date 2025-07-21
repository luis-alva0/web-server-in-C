#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Server.h"

void launch(struct Server *server)
{
    char buffer[30000];
    char *hello = "HTTP/1.1 200 OK\nGMT\nServer: Apache/2.2.14 (Win32)\nLast-Modified: Wed, 9 Jul 2025 16:07:00 GMT\nContent-Type: text/html\nConnection: Closed\n\n<html><body><h1>Homo deus</h1></body></html>";
    int address_length = sizeof(server->address);
    int new_socket;
    while(1)
    {
        printf("===== WAITIONG FOR CONNECTION =====\n");
        new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}

int main(){
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
}