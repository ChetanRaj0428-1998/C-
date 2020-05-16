#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
int sockfd;
struct sockaddr_in serv_addr;
char a[50],a1[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("\nSocket Failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(3002);
if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("\nConnectioon Failed");
exit(0);
}
printf("\n Enter the msg:");
scanf("%s",a);
write(sockfd,a,50);
read(sockfd,a1,50);
printf("Client Recieved the msg %s",a1);
close(sockfd);
}

