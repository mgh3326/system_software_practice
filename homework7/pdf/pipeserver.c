#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define BLKSIZE 1024
//#include "restart.h"
#define FIFOARG 1
#define FIFO_PERMS (S_IRWXU | S_IWGRP| S_IWOTH)
int copyfile(int fromfd, int tofd) {
char buf[BLKSIZE];
int bytesread, byteswritten;
int totalbytes = 0;
for ( ; ; ) {
if ((bytesread = read(fromfd, buf, BLKSIZE)) <= 0)
break;
if ((byteswritten = write(tofd, buf, bytesread)) == -1)
break;
totalbytes += byteswritten;
}
return totalbytes;
}
int main (int argc, char *argv[]) {
int requestfd;
if (argc != 2) { /* name of server fifo is passed on the command line */
fprintf(stderr, "Usage: %s fifoname > logfile\n", argv[0]);
return 1;
}
 /* create a named pipe to handle incoming requests */
if ((mkfifo(argv[FIFOARG], FIFO_PERMS) == -1) && (errno != EEXIST)) {
perror("Server failed to create a FIFO");
return 1;
}
/* open a read/write communication endpoint to the pipe */
if ((requestfd = open(argv[FIFOARG], O_RDWR)) == -1) {
perror("Server failed to open its FIFO");
return 1;
}
copyfile(requestfd, STDOUT_FILENO);
return 1;
}