#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<stdlib.h>
#define TIMER_MSG "Received Timer Interrupt"
int i=0;//ctrl키가 입력된 횟수를 count 하고, 많은 함수에서 사용되기에 전역변수로 선언했습니다.
int sec;//interval sec를 담는 변수입니다. 많은 함수에서 사용되기에 전역변수로 선언했습니다.
void handler() {//SIGALRM에 따른 signal handler 함수
	i++;	
	printf(" ctrl + c enter %dst\n",i);
}
static void interrupt()
{
	printf("Received Timer Interrupt! (interval_sec : %d)\n",sec);
}

static int setinterrupt(){
	struct sigaction act;

	act.sa_flags=0;
	act.sa_sigaction=interrupt;
	if(sigaction(SIGALRM,&act,NULL)==-1)//SIGALRM이 호출되면 interrupt 함수가 호출됩니다.
		return -1;
	return 0;
}

int main(){
	sec=3;//처음 3으로 초기화
	if(setinterrupt()==-1)
	{
		perror("Failed to setup SIGALRM handler");
		return -1;
	}
	timer_t timerid;
	struct itimerspec value;
	if(timer_create(CLOCK_REALTIME,NULL,&timerid)==-1)
	return -1;
	value.it_interval.tv_sec=(long)sec;
	value.it_interval.tv_nsec=0;
	value.it_value=value.it_interval;//초기 value값 또한 intverval과 같게 했습니다.
	timer_settime(timerid,0,&value,NULL);
	struct sigaction sa;//SIGINT를 받을 sigaction 입니다.
	sa.sa_flags=0;
	sa.sa_handler=handler;
	sigaction(SIGINT,&sa,NULL);
	while(1)
	{
		
	if(i==1)//ctrl+c (SIGINT)입력 1회
	{
		if(timer_delete(timerid)) {//현재의 타이머를 삭제합니다.
			printf("timer_delete error\n");
			exit(1);
		}
		sec=5;//sec를 5로 새로운 타이머를 생성합니다.
			timer_t timerid;
			struct itimerspec value;
			if(timer_create(CLOCK_REALTIME,NULL,&timerid)==-1)
			return -1;
			value.it_interval.tv_sec=(long)sec;
			value.it_interval.tv_nsec=0;
			value.it_value=value.it_interval;	
			//value.it_value.tv_sec=5;
			timer_settime(timerid,0,&value,NULL);
	}
	if(i>1)//ctrl+c (SIGINT)입력 2회 이상
	{
		if(timer_delete(timerid)) {//현재의 타이머를 삭제합니다.
			printf("timer_delete error\n");
			exit(1);
		}
		sec=3;//sec를 3으로 새로운 타이머를 생성성합니다.
			timer_t timerid;
			struct itimerspec value;
			if(timer_create(CLOCK_REALTIME,NULL,&timerid)==-1)
			return -1;
			value.it_interval.tv_sec=(long)sec;
			value.it_interval.tv_nsec=0;
			value.it_value=value.it_interval;	
			timer_settime(timerid,0,&value,NULL);
	}
		pause();
	}
	return 0;
}
