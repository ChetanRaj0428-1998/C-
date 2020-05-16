#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
int sockfd,sum,port=8000;
struct sockaddr_in serv_addr;
int a[10],a1[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("\nSocket failed");
exit(0);
}
l:serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htons(port);
if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
printf("Connection Failed \nport_busy=%d",port);
printf("Enter a port thats free");
scanf("%d",&port);
goto l;
}
printf("Enter 10 numbers:\n");
for(int i=0;i<10;i++)
{
printf("\nEnter Number: ");
scanf("%d",&a[i]);
}
write(sockfd,a,50);
read(sockfd,&sum,50);
printf("Server caluculated and sent the result : %d",sum);
close(sockfd);
}
