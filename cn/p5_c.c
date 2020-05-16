#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include <arpa/inet.h>
int main()
{
int sockfd,servlen,clilen;
struct sockaddr_in serv_addr,cli_addr;
char a[50],a1[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.0.105");
serv_addr.sin_port=htons(3005);
clilen=sizeof(cli_addr);
getsockname(sockfd,(struct sockaddr*)&cli_addr,&clilen);
printf("\nServer Local Address: %s",inet_ntoa(cli_addr.sin_addr));
connect(sockfd,(struct sockaddr*)&serv_addr,clilen);
printf("\nEnter a Msg");
scanf("%s",a);
servlen=sizeof(serv_addr);
getpeername(sockfd,(struct sockaddr*)&serv_addr,&servlen);
printf("\nPeer Name: %s",inet_ntoa(serv_addr.sin_addr));
write(sockfd,a,50);
read(sockfd,a1,50);
printf("\nClient Recvd:%s",a1);
close(sockfd);
}
