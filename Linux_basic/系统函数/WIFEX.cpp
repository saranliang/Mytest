#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
    pid_t pid,wpid;
    int status;
    pid = fork();
    if(pid==0)
    {
        printf("child，parent = %d\n",getppid());
        sleep(10);
        printf("-------------child die\n");
        //return 100;
    }else if (pid>0)
    {                            //wait将阻塞该进程，直到该进程的某个子进程结束运行为止
        wpid = wait(&status);    //wait函数返回结束运行的子进程pid，并将其退出状态存储到status指向的内存
        if(wpid ==-1)
        {
            perror("wait error:");
            exit(1);
        }
        while (1)
        {
            printf("parent,pid = %d,my son =%d\n",getpid(),pid);  //在父进程中pid返回的是子进程的pid
            sleep(1);
        }
        
    }
    else
    {
        perror("fork：");
        return 1;
    }
    return 0;
}