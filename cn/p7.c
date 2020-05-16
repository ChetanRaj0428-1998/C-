#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
int main()
{
int sockfd,MAXSEG,sndbuf,optlen;
sockfd=socket(AF_INET,SOCK_STREAM,0);
optlen=sizeof(MAXSEG);
getsockopt(sockfd,IPPROTO_TCP,TCP_MAXSEG,(char*)&MAXSEG,&optlen);
printf("\nMaxSeg=%d",MAXSEG);
sndbuf=4867;
setsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char*)&sndbuf,sizeof(sndbuf));
optlen=sizeof(sndbuf);
getsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char*)&sndbuf,&optlen);
printf("\nsndbuf=%d",sndbuf);
}

