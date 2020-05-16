#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
void togglecase(char *msg,int cnt);
int main()
{
int sockfd,newsockfd,clilen,pid,pid1,n,n1;
char msg[50];int cnt=80;
struct sockaddr_in serv_addr,cli_addr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printf("\nSocket Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(3006);
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\n Bind Failed");
exit(0);
}
clilen=sizeof(cli_addr);
n=recvfrom(sockfd,msg,80,0,(struct sockaddr*)&cli_addr,&clilen);
if(n<0)
{
printf("\nFirst Client recv error");
exit(0);
}
pid=fork();
if(pid==0)
{
printf("Server Ready\n");
togglecase(msg,cnt);
printf("\nServer recvd:%s",msg);
sendto(sockfd,msg,80,0,(struct sockaddr*)&cli_addr,clilen);
}


n1=recvfrom(sockfd,msg,80,0,(struct sockaddr*)&cli_addr,&clilen);
if(n1<0)
{
printf("\nSecond Client recv error");
exit(0);
}
pid1=fork();
if(pid1==0)
{
printf("Server Ready\n");
togglecase(msg,cnt);
printf("\nServer recvd: %s",msg);
sendto(sockfd,msg,80,0,(struct sockaddr*)&cli_addr,clilen);
}

close(sockfd);
}

void togglecase(char *msg,int cnt)
{
int i;
for(i=0;i<cnt;i++)
{
if((msg[i]>='A')&&(msg[i]>='Z'))
msg[i]+=0x20;
else if((msg[i]>='a')&&(msg[i]>='z'))
msg[i]-=0x20;
}

}
