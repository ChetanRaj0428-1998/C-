#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
 int sockfd;
 struct sockaddr_in serv_add;
 char a[50],a1[50];
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 serv_add.sin_family=AF_INET;
 serv_add.sin_port=htons(6100);
 serv_add.sin_addr.s_addr=INADDR_ANY;
 connect(sockfd,(struct sockaddr *)&serv_add,sizeof(serv_add));
 printf("Enter the message:\n");
 scanf("%s",a);
 write(sockfd,a,50);
 read(sockfd,a1,50);
 printf("Client received the msg %s",a1);
 close(sockfd);

}
