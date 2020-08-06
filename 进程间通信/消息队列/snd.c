#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

//消息队列：写消息

struct msgbuf{
	long channel;
	char buf[100];
};

int main()
{
	int id=(1234,0);

	struct msgbuf mb;
    printf("channel:");
	scanf("%d",&mb.channel);
	printf("\nmsg:");
	scanf("%s",&mb.buf);

	if(msgsnd(id,&mb,strlen(mb.buf),0) == -1){
	  perror("msgsnd");
	  exit(1);
	}
	return 0;
}
