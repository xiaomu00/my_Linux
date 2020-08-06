#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

union semun{
	int val;
};

int main()
{
	int id=semget(1234,0,0);
    
	union semun su;
	su.val = 5;
	semctl(id,0,SETVAL,su);

	return 0;
}
