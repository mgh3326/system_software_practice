#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<stdlib.h>
#define TIMER_MSG "Received Timer Interrupt"
int i=0;
int sec;
void handler() {//SIGALRM에 따른 signal handler 함수
	i++;	
	printf("ctrl + c enter %dst\n",i);
	//timer_delete(timerid);
}
static void interrupt()
{
	printf("Received Timer Interrupt! (interval_sec : %d)\n",sec);
}

static int setinterrupt(){
	struct sigaction act;

	act.sa_flags=0;
	act.sa_sigaction=interrupt;
	if(sigaction(SIGALRM,&act,NULL)==-1)
		return -1;
	return 0;
}

int main(){
	sec=3;
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
	value.it_value=value.it_interval;	
	//value.it_value.tv_sec=5;
	timer_settime(timerid,0,&value,NULL);
	struct sigaction oh;
	oh.sa_flags=0;
	oh.sa_handler=handler;
	sigaction(SIGINT,&oh,NULL);
	while(1)
	{
		
	if(i==1)
	{
		if(timer_delete(timerid)) {
			printf("timer_delete error\n");
			exit(1);
		}
		sec=5;
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
	if(i>1)
	{
		if(timer_delete(timerid)) {
			printf("timer_delete error\n");
			exit(1);
		}
		sec=3;
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
		pause();
	
		
		
	}
	return 0;
}
