#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>



int main()
{
	int id = shmget(1234,sizeof(int),IPC_CREAT|0666);
	if(id==-1){
		perror("shmget");
		exit(1);
	}else
	  printf("shmget OK\n");
	return 0;
}
