#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

//往共享内存写数据

/*
int main()
{
	int id = shmget(1234,0,0);

	//1.将共享内存段挂载到自己的内存空间
	int *pi=(int*)shmat(id,NULL,0);

	printf("num:");
	scanf("%d",pi);

	getchar();
	getchar();

	return 0;
}*/


int main()
{
	int id = shmget(1234,0,0);

	//1.将共享内存段挂载到自己的内存空间
	int *pi=(int*)shmat(id,NULL,0);


	int i=1;
	while(1){
		*pi=i++;
		sleep(1);
	}
	return 0;
}



