#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
int sockfd,clilen;
char msg[50];
struct sockaddr_in serv_addr,cli_addr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printf("\n Socket Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(2004);
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\n Bind Failed");
exit(0);
}
clilen=sizeof(cli_addr);
recvfrom(sockfd,msg,50,0,(struct sockaddr*)&cli_addr,&clilen);
printf("Recieved msg from client: %s",msg);
sendto(sockfd,msg,50,0,(struct sockaddr*)&cli_addr,clilen);
close(sockfd);
}
