#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
int sockfd,newsockfd,clilen;
struct sockaddr_in serv_addr,cli_addr;
char a[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("Socket Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(3002);
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("Bind Failed");
exit(1);
}
if(listen(sockfd,5)<0)
{
printf("\nListen failed");
exit(0);
}
clilen=sizeof(cli_addr);
printf("\nWaiting For Client");
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
read(newsockfd,a,50);
printf("\n Server Recieved: %s",a);
write(newsockfd,a,50);
close(newsockfd);
}
