#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int sig_count;

void siganl_int(int signo){
    sig_count++;
    printf("In signal handler <signal_int> : sig_count = %d\n",sig_count);
}

void sigaction_int(int signo){

    sig_count++;
    printf("In siganl handler <Sigaction_int> : sig_count = %d\n",sig_count);
}
int main(){
    struct sigaction act,oact;

    act.sa_handler=sigaction_int;
    act.sa_flags=0;
    sigemptyset(&act.sa_mask);
    if(sigaction(SIGINT,&act,&oact)<0){
        fprintf(stderr,"sigaction error");
        return 1;
    }
    while (sig_count <3);
  
    oact.sa_handler=sigaction_int;
    
    
   
    if(signal (SIGINT,siganl_int)==SIG_ERR){
        fprintf(stderr,"signal error");
        return 1;
    }
    if(sigaction(SIGINT,&oact,NULL)<0){
        fprintf(stderr,"signal error");
        return 1;
    }
//	while(sig_count<5);
   
    while (1);
    return 0;
}
