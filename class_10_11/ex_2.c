#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

void sig_handler(int signo){
    if(signo==SIGINT)
    printf(" INT signal recevied\n");
    else if(signo==SIGUSR1)
    printf(" SIGUSR1 signal recevied\n");
    else{
    printf(" siganl no = %d\n",signo);
    }
    return;
}
void main()
{
   if(signal(SIGINT,sig_handler)==SIG_ERR){
       fprintf(stderr,"can't catch SIGINT");
   }
   if(signal(SIGUSR1,sig_handler)==SIG_ERR){
    fprintf(stderr,"can't catch SIGUSR1");
}
while(1){
    pause();
}
}
// a.out & 이렇게 해서 할수도 있음
// ✘ ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  ./a.out &
// [2] 2979
//  ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11 
//  ✘ ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11 
//  ✘ ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11 
//  ✘ ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  kill -INT 2979
//  INT signal recevied
//  ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  kill -INT 2979
//  INT signal recevied
//  ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  kill -INT 2979
//  INT signal recevied
//  ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  kill -USR1 2979
//  SIGUSR1 signal recevied
//  ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  kill 2979
// [2]  - 2979 terminated  ./a.out
//  ⚙ moon@ubuntu  ~/Dropbox/sosil/class_10_11  kill -USR