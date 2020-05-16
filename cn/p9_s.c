#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/uio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
 {
 int sockfd,newsockfd,clilen;
 struct sockaddr_in serv_addr, cli_addr;
 struct iovec iov[2];
 char b[50],b1[50];
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 serv_addr.sin_family=AF_INET;
 serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);//inet_addr("192.168.200.152");
 serv_addr.sin_port=htons(3201);
 bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
 listen(sockfd,1);
 clilen=sizeof(cli_addr);
 newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
 if(newsockfd<0)
 {
 printf("\nConnection Failed");
 }
 iov[0].iov_base=b;
 iov[0].iov_len=50;
 iov[1].iov_base=b1;
 iov[1].iov_len=50;
 readv(newsockfd,&iov[0],2);
 printf("Server Received msg %s \n %s\n",b,b1);
 writev(newsockfd,&iov[0],2);
 close(newsockfd);
 }

