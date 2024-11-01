#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread0(void *arg)
{
    for(;;)
    {
        printf("thread0:hello world!\n");
        sleep(1);
    }

    return arg;
}

void* thread1(void *arg)
{  
    for(;;)
    {
        printf("thread1:hello world!\n");
        sleep(1);
    }
    
    return arg;
}

int main()
{
    pid_t result;

    result = fork();

    if(result == -1)
    {
        printf("Fork error\n");
    }
    else if (result == 0)
    {
        printf("The returned value is %d\nIn child process!!\nMy PID is %d\n",result,getpid());
    }
    else
    {
        printf("The returned value is %d\nIn father process!!\nMy PID is %d\n",result,getpid());
        for(;;)
        {
            printf("PID%d:hello world!\n",getpid());
            sleep(1);
        }
    }

    pthread_t th;  
    pthread_create( &th, NULL, thread0, NULL);  
    pthread_create( &th, NULL, thread1, NULL);  

    for(;;)
    {
        printf("PID%d:hello world!\n",getpid());
        sleep(1);
    }
}

