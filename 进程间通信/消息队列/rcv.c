#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

//消息队列：读消息

struct msgbuf{
	long channel;
	char buf[100];
};

int main()
{
	int id=msgget(1234,0);

	struct msgbuf mb;
    memset(&mb,0x00,sizeof(mb));
	printf("你想读取哪个通道的数据：");
	scanf("%d",&mb.channel);

	msgrcv(id,&mb,100,mb.channel,0);

	printf("%s\n",mb.buf);
	return 0;
}
