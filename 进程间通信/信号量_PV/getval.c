#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

int main()
{
	int id=semget(1234,0,0);
	
	int val = semctl(id,0,GETVAL,0);
	printf("==>%d\n",val);

	return 0;
}
