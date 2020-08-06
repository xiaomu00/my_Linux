#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>



int main()
{
	int id=semget(1234,1,IPC_CREAT|0644);

	return 0;
}
