#include<stdio.h>
#include<unistd.h>
int main()
{
    int x=fork();
    
    if(x==0){
       sleep(5);
       printf("The child process id is: %d\n",getpid());
       printf("The parent id is: %d\n",getppid());
    }
    else{
        
        printf("The parent process id is: %d\n",getpid());
     }
}
