#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

void show_mask(){
 sigset_t set;
 if(sigprocmask(0,NULL, &set)<0)
 fprintf(stderr,"sigismember error");
 if(sigismember(&set,SIGINT))
 printf("SIGINT ");
 if(sigismember(&set,SIGQUIT))
 printf("SIGQUIT ");
 if(sigismember(&set,SIGALRM))
 printf("SIGALRM ");
 if(sigismember(&set,SIGUSR1))
 printf("SIGUSR1 ");
 printf("\n");
}
void main()
{
   sigset_t newmask,oldmask;
   sigemptyset(&newmask);//시그널 집합의 저장된 시그널을 모두 비움   
   sigaddset(&newmask,SIGQUIT);//시그널 집합의 멤버로서 signo로 지정된 시그널을 제거
   if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)//block은 마스크에 추가
   //시그널의 상태 검사 및  변경을 위한 함수
   fprintf(stderr,"sigprocmask error");//new가 블록되고 new에 있는게 old로 감
   show_mask();//마스크 된걸 보는놈
   if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)//setmask는 마스크로 대체
   fprintf(stderr,"sigprocmask error");
   exit(0);
}
//preg a.out
//kill-KILL
//    -INT