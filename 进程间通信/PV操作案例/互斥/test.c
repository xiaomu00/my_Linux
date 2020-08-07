#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

int id;

void pint(char c)
{
	int i=10;
	while(i){
		//P操作
		struct sembuf sb[1];
		sb[0].sem_num = 0;
		sb[0].sem_op = -1;
		sb[0].sem_flg = 0;

		semop(id,sb,1);

		printf("%c",c);
		fflush(stdout);

		sleep(rand()%3);

		printf("%c",c);
		fflush(stdout);
		
		sb[0].sem_op = 1;
		semop(id,sb,1);

		--i;
	}
}

union semun{
int val;
};

int main()
{

	//创建一个信号量
	id = semget(12345,1,IPC_CREAT|0644);
	
	//设置初值
	union semun su;
	su.val = 1;
	semctl(id,0,SETVAL,su);


	srand(getpid());
	
	pid_t pid = fork();

	if(pid == 0){
		pint('A');
	} else {
		pint('B');
	}
	printf("\n");

	return 0;
}
