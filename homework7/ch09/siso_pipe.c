#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd[2];
      pipe( fd );
      if ( fork() ) { /* Parent */
         // Execution point(1)
         close( fd[0] ); // Execution Point(2): read fd closed
         write( fd[1], "How are you?", 12); 
      } else {        /* Child */
         // Execution point(1)
         char buf[100];
         close( fd[1] ); // Execution Point(3): write fd closed
read( fd[0], buf, 100);    
printf("Child received message: %s\n", buf);
    fflush(stdout);
       }
       exit(0);
    
}
