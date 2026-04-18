#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>
void* thread1(void*p)

{
	printf("new connection \n");
	int s=*(int*)p;
	free(p);
	printf("%d\n",s-3);
	while(1)
	{

	char rdbuf[128];
	bzero(rdbuf,128);
	if(read(s,rdbuf,128)==0)
	{	printf("client %d treminated\n",s);
		pthread_exit(NULL);
	}

	printf("received data %s\n",rdbuf);


	}
}

int main(int argc,char**argv)
{	
	pthread_t tid;
	char rdbuf[128];
	int sockfd;
	struct sockaddr_in srv,cln;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{	
		perror("socket");
		return 0;
	}
	printf("socket created successfully\n");
	srv.sin_family=AF_INET;
	srv.sin_port=htons(atoi(argv[1]));
	srv.sin_addr.s_addr=inet_addr("0.0.0.0");
	if(bind(sockfd,(struct sockaddr*)&srv,sizeof(srv))==0)
		printf("binding address success\n");
	else
	{
		perror("bind");
		return 0;
	}
	if(listen(sockfd,1)==0)
		printf("server listening\n");
	int len=sizeof(cln);
	while(1)
	{	int *newfd=malloc(sizeof(int));
		*newfd=accept(sockfd,(struct sockaddr*)&cln,&len);
		pthread_create(&tid,0,thread1,newfd);
	 	pthread_detach(tid);
	}


}


