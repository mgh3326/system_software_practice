#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int ncount;	// 쓰레드간	공유되는 자원
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER; // 쓰레드초기화

void* do_loop(void *data)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex); // 잠금을	생성한다.
        printf("loop1 : %d\n", ncount);
        ncount ++;
        if(i == 10)
        return;
        pthread_mutex_unlock(&mutex); // 잠금을	해제한다.
        sleep(1);
    }
}
void* do_loop2(void *data)
{
int i;

// 잠금을	얻으려고	하지만	do_loop 에서	이미	잠금을
// 얻었음으로	잠금이	해제될때까지	기다린다.
for (i = 0; i < 10; i++)
{
pthread_mutex_lock(&mutex); // 잠금을	생성한다.
printf("loop2 : %d\n", ncount);ncount ++;
pthread_mutex_unlock(&mutex); // 잠금을	해제한다.
sleep(2);
}
}
int main()
{
int thr_id;
pthread_t p_thread[2];
int status;
int a = 1;

ncount = 0;
thr_id = pthread_create(&p_thread[0], NULL, do_loop, (void*)&a);//0번째 스레드 생성
sleep(1);
thr_id = pthread_create(&p_thread[1], NULL, do_loop2, (void*)&a);//1번째 스레드 생성

pthread_join(p_thread[0], (void *) &status);//0번째 스레드가 종료 되기를 기다림
pthread_join(p_thread[1], (void *) &status);//1번째 스레드가 종료 되기를 기다림

status = pthread_mutex_destroy(&mutex);
printf("code	=	%d", status);
printf("programing is end\n");
return 0;
}
//과제 : 클린업 팝 함수하고 푸시 팝 함수 실행해보고 코맨트 달기