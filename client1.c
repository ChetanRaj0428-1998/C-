#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{

int client_socket;
char serv_msg[256] ="this is the client";//buffer to store reciving data
//Create a Socket
client_socket=socket(AF_INET,SOCK_STREAM,0);
//Specifying an Address for the socket
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9002);
server_address.sin_addr.s_addr=INADDR_ANY;
int con=connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address));
if(con<0)
{
printf("Connection Failed");
}
listen(client_socket,5/*Backlog*/);
char server_response[256];
int server_socket;
server_socket=accept(client_socket,NULL,NULL);
send(server_socket,serv_msg,sizeof(serv_msg),0);
recv(client_socket,&server_response,sizeof(server_response),0);
printf("The server data is :%s /n	",server_response);

int close(int client_socket);

}
