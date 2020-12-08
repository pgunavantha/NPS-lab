#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MAX 256
#include<string.h>

int main(){
    int client_socket;
    client_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_address;

    server_address.sin_addr.s_addr=INADDR_ANY;
    server_address.sin_family=PF_INET;
    server_address.sin_port=htons(9002);

    if(connect(client_socket,(struct sockaddr *) &server_address,sizeof(server_address))<0){
        printf("Could not connect\n");
        exit(0);
    }
    else{
        
        printf("Connected to server\n"); 

        char buff[MAX]; 
        int n; 

        while(1) { 
            bzero(buff, sizeof(buff)); 
            printf("Enter the command : "); 
            n = 0; 
            while ((buff[n++] = getchar()) != '\n'); 
            write(client_socket, buff, sizeof(buff)); 
            if ((strncmp(buff,"end",3)) == 0) { 
                printf("Client Exiting.\n"); 
                break; 
            } 
            
            
        } 

            
        
    }
    close(client_socket);
    return 0;
}
