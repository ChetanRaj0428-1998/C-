#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
	{
int sockfd,newsockfs,clilen,number=0;
	struct sockaddr_in serv_addr,cli_addr;
	char a[50];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		{
printf(“\nSocket Failed”);
exit(0);
}
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=(“192.168.2.144”);
	serv_addr.sin_port=htons(3500);
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
		{
printf(“\nBind Failed”);
exit(1);
}
	              if(listen(sockfd,5)<0)
		{
printf(“\nListen Failed”);
		   exit(0);
}
	clilen=sizeof(cli_addr);
	printf(“\nWaiting for Client”);
	newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
	for(int i=0;i<10;i++)
		{read(newsockfs,a,50);
number=Integer.parseint(a[i]);+number;}
printf(“\nServer received:%s”,a);
write(newsockfd,number,1);
close(newsockfd);
}
