#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <pthread.h>

void cleanup(void *arg)//클린업 핸들러 함수입니다.
{
printf("cleanup: %s\n", (char *)arg);
}

void * thr_fn1(void *arg)
{
printf("thread 1 start\n");
pthread_cleanup_push(cleanup, "thread 1 first handler");
pthread_cleanup_push(cleanup, "thread 1 second handler");
printf("thread 1 push complete\n");
if (arg)//arg가 0이 아니면 여기 if문 들어감
return((void *)1); 
  pthread_cleanup_pop(0);
  pthread_cleanup_pop(0); 
  return((void *)1);
}
void * thr_fn2(void *arg)
{
   printf("thread 2 start\n");
 pthread_cleanup_push(cleanup, "thread 2 first handler");
  pthread_cleanup_push(cleanup, "thread 2 second handler");
printf("thread 2 push complete\n");
if(arg)
pthread_exit((void *)2);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *)2);//존재하는 제어의 흐름으로부터 탈출
}
int main(void)
{
int err;
pthread_t tid1, tid2;
void *tret;
err = pthread_create(&tid1, NULL, thr_fn1, (void *)1);//제어의 새로운 흐름을 만듦
if (err != 0)
fprintf(stderr, "can′t create thread 1");
err = pthread_create(&tid2, NULL, thr_fn2, (void *)1);//제어의 새로운 흐름을 만듦
if (err != 0)
fprintf(stderr, "can′t create thread 2");
err = pthread_join(tid1, &tret);//제어의 흐름으로부터 탈출 상태를 획득
if (err != 0)
fprintf(stderr, "can′t join with thread 1");
printf("thread 1 exit code %ld\n", (long)tret);
err = pthread_join(tid2, &tret);//제어의 흐름으로부터 탈출 상태를 획득
if (err != 0)
fprintf(stderr, "can′t join with thread 2");
printf("thread 2 exit code %ld\n", (long)tret);
exit(0);
}
/*
pthread_cleanup_pop() 함수가 호출 되는 경우
쓰레드의 종료(즉, pthread_exit() 호출)
쓰레드의 취소(cancellation) 요청에 관한 행동
쓰레드가 0이 아닌 execute 인자 값으로 pthread_cleanup_pop() 호출
이렇기 때문에 thr_fn1은 클린업 핸들러 함수가 호출 되지 않고(return 으로 끝나서)
thr_fn2 클린업 핸들러 함수가 호출됩니다. (쓰레드의 종료(즉, pthread_exit() 호출))

*/