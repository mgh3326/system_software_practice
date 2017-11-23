#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<stdlib.h>
#define TIMER_MSG "Received Timer Interrupt\n"

int i=0;
static void interrupt()
{
	printf("%s",TIMER_MSG);

}
void handler() {//SIGALRM에 따른 signal handler 함수
	printf("Oh!!\n");
	//timer_delete(timerid);
	i++;
}

static int setinterrupt(){
	struct sigaction act;

	act.sa_flags=0;
	act.sa_sigaction=interrupt;
	if(sigaction(SIGALRM,&act,NULL)==-1)
		return -1;
		if(i>0){
			sigaddset(&act.sa_mask,SIGALRM);
		}
	return 0;
}
static int setperiodic(int sec)
{
	timer_t timerid;
	struct itimerspec value;

	if(timer_create(CLOCK_REALTIME,NULL,&timerid)==-1)
		return -1;
	value.it_interval.tv_sec=(long)sec;
	value.it_interval.tv_nsec=0;
	value.it_value=value.it_interval;	
	//value.it_value.tv_sec=5;
	struct sigaction act;
	
		act.sa_flags=0;
		//act.sa_sigaction=interrupt;
		// if(sigaction(SIGALRM,&act,NULL)==-1)
		// 	return -1;
		// 	if(sigaction(SIGINT,&act,NULL)==-1)
		// 	return -1;
	return timer_settime(timerid,0,&value,NULL);

}
int main(){
	if(setinterrupt()==-1)
	{
		perror("Failed to setup SIGALRM handler");
		return -1;
	}
	if(setperiodic(2)==-1)
	{
		perror("Failed to setup periodic interrupt");
		return 1;
	}
	struct sigaction oh;
	oh.sa_flags=0;
	oh.sa_handler=handler;
	sigaction(SIGINT,&oh,NULL);
	while(i<1)
	{
		
		
		
		pause();
		
	}
	if(setinterrupt()==-1)
	{
		perror("Failed to setup SIGALRM handler");
		return -1;
	}
	if(setperiodic(5)==-1)
	{
		perror("Failed to setup periodic interrupt");
		return 1;
	}
	while(i<2)
	{
		
		
		
		pause();
		
	}
	// if(setperiodic(5)==-1)
	// {
	// 	perror("Failed to setup periodic interrupt");
	// 	return 1;
	// }
	// return 0;
}
