#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
int sockfd,clilen,servlen;
char msg1[50],msg[50];
struct sockaddr_in serv_addr,cli_addr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(2004);
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=htonl(INADDR_ANY);
cli_addr.sin_port=htons(0);
if(connect(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr))<0)
{
printf("Client can't bind");
exit(0);
}
printf("Enetr a msg:\n");
fgets(msg,50,stdin);
servlen=sizeof(serv_addr);
if(sendto(sockfd,msg,80,0,(struct sockaddr*)&serv_addr,servlen)<0)
{
printf("\nSend Error");
}
if(recvfrom(sockfd,msg1,80,0,(struct sockaddr*)&serv_addr,&servlen)<0)
{
printf("\n Recv Error");
}
else
{
printf("Client Recieved the msg:%s",msg1);
}
close(sockfd);
}
