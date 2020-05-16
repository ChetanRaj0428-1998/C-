#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
char serv_msg[256]="This is the server my name is chetan";//buffer for sending data
int server_socket;
server_socket=socket(AF_INET,SOCK_STREAM,0);
//defining the server address
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9002);
server_address.sin_addr.s_addr=INADDR_ANY;
//Bind the Socket to our specified IP and Port
bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));
listen(server_socket,5/*Backlog*/);
//accept connection
int client_socket;
client_socket=accept(server_socket,NULL,NULL);
send(client_socket,serv_msg,sizeof(serv_msg),0);
char client_response[256];
recv(server_socket,&client_response,sizeof(client_response),0);
printf("The Client data is :%s /n	",client_response);
int close(int server_socket);
}
