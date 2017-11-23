#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;
    pid=getpid();
    tid=pthread_self();
        for(int i=0;i<1000;i++)
    printf("%d : %s pid %u tid %u (0x%x)\n",i,s, (unsigned int)pid,(unsigned int ) tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
    printids(" New thread : ");
    return((void *)0);
}
int main (void){
    int err;
    err=pthread_create(&ntid,NULL,thr_fn,NULL);//제어의 새로운 흐름을 만듦
    if(err!=0)
    exit(1);
    printids("Main Thread : ");
    sleep(1);
    exit(0);
}
