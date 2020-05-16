#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
//#include <arpa/inet.h>
#include<time.h>
int main()
{
int sockfd,newsockfd,clilen;
struct sockaddr_in serv_addr,cli_addr;
char timestr[100],a[50];
time_t now;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("\nBind Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(4002);

if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\n Bind failed");
exit(0);
}

if(listen(sockfd,5)<0)
{
printf("\nBind Failed");
exit(0);
}

clilen=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
time(&now);
sprintf(timestr,"\n Server Recvd msg: %s\n",ctime(&now));
read(newsockfd,a,50);
printf("\n %s",a);
write(newsockfd,timestr,100);
close(newsockfd);
}
