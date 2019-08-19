#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //create a socket
    int network_socket;
    network_socket = socket(AF_INET,SOCK_STREAM,0);

    // specify an address for the socket

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct  sockaddr *) &server_address, sizeof(server_address));
 
    if(connection_status == -1){
        printf("error making connection");
    }

    char server_respose[256];
    recv(network_socket,&server_respose,sizeof(server_respose),0);

    // print out server's response
    printf("the sever sent data: %s\n",server_respose);

    close(network_socket);
    return 0;
}