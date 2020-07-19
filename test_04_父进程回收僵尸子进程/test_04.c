#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
   pid_t pid;
   pid =fork();
   if(pid==0) //子进程
   {
      int i=0;
      for(i;i<10;++i)
      {
         printf(".");
         fflush(stdout);
         sleep(1);

      }  
   }
   else
   {
      wait(NULL);
      
       printf("wait return\n");
   }

   return 0;
}
