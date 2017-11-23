#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler() {//SIGALRM에 따른 signal handler 함수
    printf("Timer Invoked..\n");
}

int main(void) {
    struct itimerval it;

    sigset(SIGALRM, handler);
    it.it_value.tv_sec = 3;//현재 남은 시간
    it.it_value.tv_usec = 0;
    it.it_interval.tv_sec = 2;//타이머 간격
    it.it_interval.tv_usec = 0;
//최초의 시그널은 3초후에 발생 이후에는 2초 간격으로 타이머가 작동하도록 함.
    if (setitimer(ITIMER_REAL, &it, (struct itimerval *)NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {
        if (getitimer(ITIMER_REAL, &it) == -1) {
            perror("getitimer");
            exit(1);
        }
        // printf("%d sec, %d msec.\n", (int)it.it_value.tv_sec,
        //                              (int)it.it_value.tv_usec);
        // sleep(1);
    }

    return 0;
}
