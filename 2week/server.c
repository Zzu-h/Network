#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    char server_message[256] = "socket programming in c";
    
    // creating the server socket
    int server_socket = socket(AF_INET,SOCK_STREAM,0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the IP and port to the server
    bind(server_socket,(struct sockadd*)&server_address,sizeof(server_address));

    // listen at the port
    listen(server_socket,5);
    
    // accept the incoming connection from the client
    int client_sock;
    client_sock = accept(server_socket, NULL, NULL);

    // send the message on the client address
    send(client_sock, server_message, sizeof(server_message),0);
    close(server_socket);

    return 0;
}