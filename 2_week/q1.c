#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int fd;
	ssize_t nread;
	int n;
	char buf[1024];
	
	fd=open("data", O_RDONLY);
	
	n=read(fd,buf,1024);
	buf[n]='\0';
	
	//printf("%s", buf);
	printf("n : %d ,buf=%s\n", n,buf);
	close(fd);
	return 0;
}

