#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
int sockfd,n,clilen,servlen;
struct sockaddr_in serv_addr,cli_addr;
char msg[100],msg1[100];
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printf("\n Socket Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(3005);
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=htonl(INADDR_ANY);
cli_addr.sin_port=htons(0);
if(bind(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr))<0)
{
printf("\n Bind failed");
exit(1);
}
printf("Enter String:");
scanf("%s",msg);
if(sendto(sockfd,msg,80,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("Client send to error");
exit(0);
}
servlen=sizeof(serv_addr);
n=recvfrom(sockfd,msg1,80,0,(struct sockaddr*)&serv_addr,&servlen);
if(n<0)
{
printf("Recieve Error");
exit(1);
}
else
{
printf("Client recieved msg:%s",msg1);
}
close(sockfd);
}
