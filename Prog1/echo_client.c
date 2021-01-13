#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

int main(int argc,char *argv[])
{
	int create_socket;
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	char fname[256];
	struct sockaddr_in address;
	
	if ((create_socket = socket(AF_INET,SOCK_STREAM,0)) > 0)
		printf("The socket was created\n");
		
	address.sin_family = AF_INET;
	address.sin_port = htons(15001);			
	inet_pton(AF_INET, argv[1], &address.sin_addr);	
	
	if (connect(create_socket, (struct sockaddr *)&address, sizeof(address)) == 0)
		printf("The connection was accepted with the server %s...\n",argv[1]);
	else
		printf("Error in connect\n");			
		
	printf("enter the name of the file to be requested : ");
	scanf("%s", fname);
	send (create_socket,fname,sizeof(fname),0);
	printf("request accepted ... receiving file .... \n\n");
	printf("the contents of the file are\n");
	uint32_t cont;
	while((cont = recv(create_socket, buffer, bufsize, 0))>0)
	{
		write(1,buffer,cont);
	}
	printf("\nEOF\n");
	return close(create_socket);
}
