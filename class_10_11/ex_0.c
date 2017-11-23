#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int n;

void handler(int signum)
{
    printf("signal %d received\n",signum);
    n=0;
}
void main()
{
    signal(SIGINT,handler);
    signal(SIGQUIT,SIG_IGN);
    signal(SIGTERM,SIG_IGN);
    // SIG_IGN : 시그널을 무시한다.
    // SIGQUIT : 프로세스를 종료시킨다.
    // SIGTERM 시그널은 프로그램을 종료하는데 사용하는 포괄적인 시그널이다. SIGKILL과 달리, 이 신호는 블록되어진고, 처리되어지고 무시되어질 수 있다. 쉘 코맨드 kill은 디폴트로 SIGTERM을 발생시킨다.
    while(1)
    {
        printf("Working %d\n",n++);
        sleep(1);
    }
}
//preg a.out
//kill-KILL
//    -INT