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
char msg[50],msg1[50];
struct sockaddr_in serv_addr,cli_addr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printf("\nSocket failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(3006);
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=htonl(INADDR_ANY);
cli_addr.sin_port=htons(0);

if(bind(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr))<0)
{
printf("\nBind Faield");
exit(0);
}

printf("Enter a msg:\n");
scanf("%s",msg);
if(sendto(sockfd,msg,80,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\nClient Send Error");
exit(0);
}
servlen=sizeof(serv_addr);
if(recvfrom(sockfd,msg1,80,0,(struct sockaddr*)&serv_addr,&servlen)<0)
{
printf("\nClient Recv Error");
exit(0);
}
else
{
printf("Client recvd: %s",msg1);
}
close(sockfd);
}

