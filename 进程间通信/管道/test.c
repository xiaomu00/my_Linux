#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>


//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////管道

int main()
{
	int fds[2];
	pipe(fds);

	pid_t pid=fork();
	if(pid==0){
		close(1);//关闭原来的标准输出
		dup(fds[1]);//将标准输出和管道绑定
		close(fds[0]);//关闭读，用不到
		close(fds[1]);//已经将fds[1]复制给了1，引用计数为2 ，所以关掉fds[1]
		execlp("ls","ls","-l",NULL);//用ls -l替换掉当前进程，使得输出来源来自于 ls -l
	}
	else{
		
		close(0);//关闭原来的标准输入
		dup(fds[0]);//将标准输入和管道绑定
		close(fds[1]);
		close(fds[0]);
		execlp("wc","wc","-l",NULL);
	}

	return 0;
}


/*
int main()
{
	int fds[2];
	pipe(fds);

	pid_t pid=fork();
	if(pid==0){
		close(fds[0]);//关闭子进程读
		sleep(5);
		write(fds[1],"abcde",5);
		close(fds[1]);
	}
	else{
		close(fds[1]);//关闭父进i；；：；kqq程写
		char s[10];
		read(fds[0],s,10);
		close(fds[0]);
		printf("parent:%s\n",s);
	}

	return 0;
}*/
