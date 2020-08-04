#include<stdio.h>
#include<unistd.h>
#include<signal.h>


/*  
//重写一个信号处理函数
void handler(int s)
{
	printf("你弄不死我!\n");
}
int main()
{
	signal(SIGINT,handler);

	while(1)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
	}

	return 0;
}
*/

/*
//在特定条件下又恢复原来的功能
void handler(int s)
{
	printf("你弄不死我!\n");
}
int main()
{
	__sighandler_t ret=NULL;
	if((ret=signal(SIGINT,handler))==SIG_ERR)//当返回错误时，正常情况下返回原来的信号处理函数
	{
		perror("signal");//将错误打印出来
		exit(1);
	}
    
	char c;
	while((c=getchar())!='\n')
	{}

	signal(SIGINT,ret);//当按下回车之后，SIGINT恢复之前的功能
	while(1)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
	}

	return 0;
}
*/


//在特定条件下又恢复原来的功能
void handler(int s)
{
	printf("你弄不死我!\n");
}
int main()
{
	__sighandler_t ret=NULL;
	if((ret=signal(SIGINT,handler))==SIG_ERR)//当返回错误时，正常情况下返回原来的信号处理函数
	{
		perror("signal");//将错误打印出来
		exit(1);
	}
    
	char c;
	while((c=getchar())!='\n')
	{}

	signal(SIGINT,ret);//当按下回车之后，SIGINT恢复之前的功能
	while(1)
	{
		printf(".");
		fflush(stdout);
		sleep(1);
	}

	return 0;
}


