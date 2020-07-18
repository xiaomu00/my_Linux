#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{

   printf("bofore fork\n");

   pid_t pid=fork();
  
   if(pid==0)
   {
       printf("child\n");
   }
   else
   {
       printf("parent\n");
   }

   getchar();

   return 0;
}
