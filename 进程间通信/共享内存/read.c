#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

//读共享内存数据

int main()
{
	int id = shmget(1234,0,0);

	//1.将共享内存段挂载到自己的内存空间
	int *pi=(int*)shmat(id,NULL,0);

	while(1){
		printf("*pi=%d\n",*pi);
	}

	return 0;
}
