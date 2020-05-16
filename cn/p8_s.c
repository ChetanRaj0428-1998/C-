#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<errno.h>
#include<arpa/inet.h>
short myport;
int main(int argc,char *argv[])
{
 int sockfd,newsockfd,nbyte,n,p;
 struct sockaddr_in my_addr,cli_addr;
 char buff[512],buff1[512];
 if(argc!=2)
 {
 perror("invalid no of arguments");
 exit(1);
 }
 sockfd=socket(AF_INET,SOCK_DGRAM,0);
 if(sockfd==-1)
 {
 perror("Unable to create socket");
 exit(1);
 }
 myport=atoi(argv[1]);
 my_addr.sin_family=AF_INET;
 my_addr.sin_port=htons(myport);
 my_addr.sin_addr.s_addr=inet_addr("192.168.200.154");
 bzero(&(my_addr.sin_zero),8);
 if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(my_addr))==-1)
 {
 perror("bind failed");
 exit(1);
 }
 write(1,"\n Waiting for client",sizeof("\n Waiting for client"));
// printf("server is waiting");
 newsockfd=sizeof(cli_addr);
 n=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&cli_addr,&newsockfd);
 if(n==-1)
 {
 perror("receive eeror");
 exit(1);
 }
 printf("\n client connected&..");
 write(1,"\n client:",10);
 write(1,buff1,n);
 p=fork();
 if(p<0)
 {
 perror("cvhild cannot be created&..");
 exit(1);
 }
 if(p>0)
 {
 for(;;)
 {
 write(1,"\n server:",10);
 n=read(0,buff,512);
 if(sendto(sockfd,buff,n,0,(struct sockaddr *)&cli_addr,newsockfd)==-1)
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
 n=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr *)&cli_addr,&newsockfd);
 write(1,"\rClient:",10);
 write(1,buff1,n);
 write(1,"\nserver:",sizeof("\nserver:"));
 }
 }
}
