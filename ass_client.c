#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
	{
int sockfd;
	 struct sockaddr_in serv_addr;
	 char a[50],a1[50];
	 sockfd=socket(AF_INET,SOCK_STREAM,0);
	 if(sockfd<0)
	      {
printf("\nSocket failed");
exit(0);
}
	          serv_addr.sin_family=AF_INET;
	          serv_addr.sin_addr.s_addr=INADDR_ANY;
	          serv_addr.sin_port=htons(3500);
	          if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
		{ 
printf("\nConnection Failed");
exit(0);
}
	printf("\nEnter 10 numbers: ");
	for(int i=0;i<10;i++)
		{
printf("\nEnter number %d: ",i+1);
		 scanf("%s",a);
		 write(sockfd,a,50);
}
	             read(sockfd,a1,50);
	             printf("The sum is %s",a1);
	             close(sockfd);
}

