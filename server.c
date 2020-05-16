#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
int sockfd,newsockfd,clilen,sum=0,port=8000,key;
struct sockaddr_in serv_addr,cli_addr;
int a[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("Socket Failed");
exit(0);
}
l:serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(port);
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
printf("Bind Failed");
printf("\nPress 1 to retry  or 0 to exit port_busy=%d",port);
scanf("%d",&key);
if(key==1)
++port;
goto l;
 if(key==0)
exit(0);
}
printf("\n port_free=%d",port);
if(listen(sockfd,5)<0)
{
printf("Listen Failed");
exit(0);
}
clilen=sizeof(cli_addr);
printf("\n Waiting for client");
newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
read(newsockfd,a,50);
for(int i=0;i<10;i++)
{
sum=sum+a[i];
}
printf("\n Server processed the numbers and calculated the sum= %d ",sum);
write(newsockfd,&sum,50);
close(newsockfd);
}
