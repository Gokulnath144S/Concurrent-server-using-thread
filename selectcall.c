#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<strings.h>
int main()
{
	char rbuf[30];
	int i;
	fd_set rdset,testset;
	printf("%ld\n",sizeof(rdset));
	int sfd,nsfd;
	struct sockaddr_in server,client;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return 0;
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(3000);
	server.sin_addr.s_addr=inet_addr("0.0.0.0");

	if(bind(sfd,(struct sockaddr*)&server,sizeof(server))==0)
			printf("bind:success");
	else
	{
			perror("bind");
			return 0;
	}

listen(sfd,1);
int len;
len=sizeof(client);
FD_ZERO(&rdset);
FD_SET(sfd,&rdset);
while(1)
{
	testset=rdset;
	select(100,&rdset,0,0,0);
	for(i=0;i<100;i++)
	{
		if(FD_ISSET(sfd,&testset))
				break;
				}
	if(sfd==i)
	{
		printf("new connection");
		nsfd=accept(sfd,(struct sockaddr*)&client,&len);
		FD_SET(nsfd,&rdset);
	}
	else{	bzero(rbuf,128);
		read(i,rbuf,128);
		printf("%s\n",rbuf);
	}
}
}



