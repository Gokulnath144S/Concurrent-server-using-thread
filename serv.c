#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
int main(int argc,char**argv)
{
	char wrbuf[128];
	int sockfd,newsfd;
	struct sockaddr_in srv,cln;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("socket");
		return 0;
	}
	printf("socket created successfully...\n");
	srv.sin_family=AF_INET;
	srv.sin_port=htons(atoi(argv[1]));
	srv.sin_addr.s_addr=inet_addr("192.168.3.190");
	if(connect(sockfd,(struct sockaddr*)&srv,sizeof(srv))==0)
		printf("connected to server\n");
	else
	{	perror("connect");
		return 0;
	}
	while(1)
	{
		printf("enter data:");
		scanf("%[^\n]",wrbuf);
		write(sockfd,wrbuf,strlen(wrbuf+1));
	}
}
