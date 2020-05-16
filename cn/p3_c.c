#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
int sockfd;
char msg1[50],msg[50];
struct sockaddr_in serv_addr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("\nSocket Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(3004);

if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("Connect Faield");
exit(0);
}
printf("enter a msg:");
scanf("%s",msg);
write(sockfd,msg,50);
read(sockfd,msg1,50);
printf("Client Recvd: %s",msg1);
close(sockfd);
}
