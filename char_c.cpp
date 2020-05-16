#include<iostream>
#include<sys/socket>
#include<netinet/in.h>
#include<cstring>
#include<cerrno>
#include<cstdlib>
#include<cunistd>
#include<cstring>
short myport,desport;
int main(int argc,char argv[])
{
int sockfd,newfd,nbyte,n,na,p,q;
struct sockaddr_in myaddr,servaddr;
char buff[512],buff[512];
sockfd=socket(AF_INET,SOCK_DGARAM,0);
if(sockfd==-1)
{
perror("Unable to craete socket");
exit(1);
}
myport=atoi(argv[1]);
myaddr.sin_family=AF_INET;
myaddr.sin_port=htons(myport);
myaddr.sin_addr.s_addr=INADDR_ANY;
bzero(&(myaddr.sin_zero),8);
desport=atoi(argv[2]);
myaddr.sin_family=AF_INET;
myaddr.sin_port=htons(mdesport);
myaddr.sin_addr.s_addr=INADDR_ANY;
bzero(&(myaddr.sin_zero),8);
q=bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr));
if(q==-1)
{
perror("Bind Error");
exit(1);
}
newfd=sizeof(servaddr);
write(1,"\n ENTER MESSAGE TO CONNECT TO SEREVER&..:",57);
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
write(1,"\n Client :",sizeof("\n Client :"));
na=read(0,buff,512);
if(sendto(sockfd,buff,na,0,(struct sockaddr*)&servaddr,newfd)==-1)
{
perror("SEND ERROR");
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
perror("RECIEVE ERROR");
exit(1);
}
write(1,"\rServer :",10);
write(1,biff1,n);
write(1,"\nClient :",10);
}
}
}
