#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<time.h>
#define max 100
void errexit(char *str)
{
 puts(str);
 exit(0);
}
int main()
{
 int sockfd,newsockfd,fd,clilen,n,start;
 struct sockaddr_in serv_addr,cli_addr;
 fd_set readfds,testfds;
 char msg[max];
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 serv_addr.sin_family=AF_INET;
 serv_addr.sin_port=htons(6100);
 serv_addr.sin_addr.s_addr=INADDR_ANY;
 bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
 listen(sockfd,5);
 FD_ZERO(&readfds);
 FD_SET(sockfd,&readfds);
 printf("\n Server Waiting");
 while(1)
 {
 testfds=readfds;
 start=select(FD_SETSIZE,&testfds,(fd_set*)0,(fd_set*)0,(struct timeval *)0);
 for(fd=0;fd<FD_SETSIZE;fd++)
 {
 if(FD_ISSET(fd,&testfds))
 {
 if(fd==sockfd)
 {
 newsockfd=accept(sockfd,(struct sockaddr*)0,NULL);
 FD_SET(newsockfd,&readfds);
 printf("\n Adding Client fd:%d to readfds:",newsockfd);
 }
 else
 {
 n=recv(fd,msg,max,0);
 if(n<0)
 errexit("Recv error");
 else if(n==0)
 {
 close(fd);
 FD_CLR(fd,&readfds);
 printf("\n Removing Client fd: %d from readfds",newsockfd);
 }
 else
 {
 if(send(fd,msg,n,0)==0)
 errexit("Send err");
 }
 }
 }
 }
 }
}

