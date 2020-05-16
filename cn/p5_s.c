#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include <arpa/inet.h>
int main()
{
int sockfd,newsockfd,clilen,servlen;
char a[50];
struct sockaddr_in cli_addr,serv_addr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.0.105");
serv_addr.sin_port=htons(3005);
bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
servlen=sizeof(serv_addr);
getsockname(sockfd,(struct sockaddr*)&serv_addr,&servlen);
printf("\nServer Local Address:%s",inet_ntoa(serv_addr.sin_addr));
listen(sockfd,5);
clilen=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
if(newsockfd<0)
{
printf("\nConnection not established");
exit(0);
}
else
{
printf("\nConnection Established");
read(newsockfd,a,30);
getpeername(newsockfd,(struct sockaddr*)&cli_addr,&clilen);
printf("\nPeer Address:%s",inet_ntoa(cli_addr.sin_addr));
printf("\n Server Recvd msg:%s",a);
write(newsockfd,"Hai",50);
close(newsockfd);
}

}
