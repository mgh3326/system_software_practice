#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int alarm_handler(){
    printf("\n signal handled!\n");
    
    return 0;
}
void main(){
    signal(SIGALRM,(void*)alarm_handler);
    alarm(3);

    while(1){
        printf("sleeping\n");
        sleep(1);
        alarm(3);
    }
}
