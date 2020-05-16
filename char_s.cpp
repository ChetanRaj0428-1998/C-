#include<iostream>
#include<netinet/in.h>
#include<cstring>
#include<cerrno>
#include<cstdlib>
//#include<cunistd>
short myport;
int main(int argc,char *argv[])
{
int sockfd,newfd,nbyte,n,p;
struct sockaddr_in myaddr,claddr;
char buff[512],buff1[512];
if(argc!=2)
{
perror("invalid no. of arguments");
exit(1);
}
if(sockfd=socket(AF_INET,SOCK_DGRAM,0)==-1)
{
perror("Unable to create socket ");
exit(1);
}
myport=atoi(argv[1]);
myaddr.sin_family=AF_INET;
myaddr.sin_port=htons(myport);
myaddr.sin_addr.s_addr=INADDR_ANY;
bzero(&(myaddr.sin_zero),8);
if(bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr))==-1)
{
perror("bind error ");
exit(1);
}
write(1,"\n Waiting for client",sizeof("\n Wait for Client"));
newfd=sizeof(claddr);
n=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr*)&claddr,&newfd);
if(n==-1)
{
perror("Recieve Error");
exit(1);
}
printf("\n CLIENT CONNECTED&..");
write(1,"\n Client:",10);
write(1,buff1,n);
//for(;;)
p=fork();
if(p<0)
{
perror("\n CHILD CANNOT BE CREATED");
exit(1);
}
if(p>0)
{
for(;;)
{
write(1,"\nServer",10);
n=raed(0,buff,512);
if(sendto(sockfd,buff,n,0,(struct sockaddr*)&claddr,newfd)==-1)
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
n=recvfrom(sockfd,buff1,sizeof(buff1),0,(struct sockaddr*)&claddr,&newfd);
write(1,"\rClient:",10);
write(1,buff1,n);
write(1,"\nServer:",sizeof("\nServer"));
}
}
}
