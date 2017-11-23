#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFSIZE 256
#define FIFO_MODES O_RDONLY

int dofifoparent(const char *fifoname){
    char buf[BUFSIZE];
    int fd,rval;

    fprintf(stderr, "[%ld]:(parent)about to open FIFO %s....\n",(long)getpid(),fifoname);
    while(((fd=open(fifoname,FIFO_MODES))==-1&&errno==EINTR));
    if(fd==-1){
        fprintf(stderr,"[%ld]:failed to open named pip %s for write: %s\n", (long)getpid(), fifoname,strerror(errno));
        return 1;
    }
    fprintf(stderr,"[%ld]:about to read...\n",(long)getpid());
    rval=read(fd,buf,BUFSIZ);
    if(rval==-1){
        fprintf(stderr,"[%ld]:failed to make read from pipe: %s\n",(long)getpid(),strerror(errno));
        return 1;
    }
    fprintf(stderr,"[%ld]:read %.*s\n",(long)getpid(),rval,buf);
    return 0;
}