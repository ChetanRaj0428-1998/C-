#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<time.h>
int main()
{
int sockfd;
char a[50];
struct sockaddr_in serv_addr,cli_addr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("\nSocket failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(4002);
if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\nConnection failed");
exit(0);
}
write(sockfd,"Hello",50);
sleep(2);
read(sockfd,a,50);
printf("\nClient Recvd msg:%s",a);
close(sockfd);
}
