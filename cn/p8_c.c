#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
short myport,destport;
int main(int argc,char* argv[])
{
 int sockfd,newfd,nbyte,n,na,p,q;
 struct sockaddr_in myaddr,servaddr;
 char buff[512],buff1[512];
 sockfd=socket(AF_INET,SOCK_DGRAM,0);
 if(sockfd==-1)
 {
 perror("unable to create socket");
 exit(1);
 }
 myport=atoi(argv[1]);
 myaddr.sin_family=AF_INET;
 myaddr.sin_addr.s_addr=inet_addr("192.168.200.154");
 myaddr.sin_port=htons(myport);
 bzero(&(myaddr.sin_zero),8);
 destport=atoi(argv[2]);
 servaddr.sin_family=AF_INET;
 servaddr.sin_addr.s_addr=inet_addr("192.168.200.154");
 servaddr.sin_port=htons(destport);
 bzero(&(servaddr.sin_zero),8);
 q=bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr));
 if(q==-1)
 {
 perror("bind error");
 exit(1);
 }
 newfd=sizeof(servaddr);
 write(1,"\n ENTER MESSAGE TO CONNECT TO THE SERVER&..:",57);
 p=fork();
 if(p<0)
 {
 perror("CHILD CANNOT BE CREATED&.");
 exit(1);
 }
 if(p>0)
 {
 for(;;)
 {
 write(1,"Client:",sizeof("\nClient:"));
 na=read(0,buff,512);
 if((sendto(sockfd,buff,na,0,(struct sockaddr*)&servaddr,newfd))==-1)
 {
 perror("send error");
 exit(1);
 }
 }
 }
 else
 {
 for(;;)
 {
 n=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr*)&servaddr,&newfd);
 if(n==-1)
 {
 perror("RECEIVE ERROR");
 exit(1);
 }
 write(1,"\rServer :",10);
 write(1,buff1,n);
 write(1,"\nClient :",10);
 }
 }
}
