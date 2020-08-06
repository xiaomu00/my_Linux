#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////消息队列

int main()
{
	int id = msgget(1234,IPC_CREAT|0644);
	if(id==-1){
		perror("msgget error");
		exit(1);
	} else {
		printf("msgget OK\n");
	}
	return 0;
}
