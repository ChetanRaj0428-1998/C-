#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
void togglecase(char *msg,int cnt);
int main()
{
int sockfd,newsockfd,newsockfd1,clilen,pid,pid1;
char msg[50];
struct sockaddr_in serv_addr,cli_addr;
int cnt=50;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("\nSocket failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(3004);
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\nBind Failed");
exit(0);
}
if(listen(sockfd,5)<0)
{
printf("\nBind Failed");
exit(0);
}
clilen=sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
pid=fork();
if(pid==0)
{
close(sockfd);
read(newsockfd,msg,50);
togglecase(msg,cnt);
printf("\nServer Recvd: %s",msg);
write(newsockfd,msg,50);
}
close(newsockfd);
newsockfd1=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
pid1=fork();
if(pid1==0)
{
close(sockfd);
read(newsockfd1,msg,50);
togglecase(msg,cnt);
printf("\nServer Recvd: %s",msg);
write(newsockfd1,msg,50);
}
close(newsockfd1);
}

void togglecase(char *msg,int cnt)
{
int i;
for(i=0;i<cnt;i++)
{
if((msg[i]>='A')&&(msg[i]<='Z'))
msg[i]+=0x20;
else if((msg[i]>='a')&&(msg[i]<='z'))
msg[i]-=0x20;
}
}
