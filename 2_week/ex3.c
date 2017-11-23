#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 512

int main()
{
	char buf[BUF_SIZE];
	int fd;
	ssize_t nread;
	long total = 0; 
	if((fd = open("sosil",O_RDONLY))==-1){
		printf ("error in opening sosil\n"); 
		exit (1); 
	} 

		/* EOF까지 반복하라. EOF는 복귀값 0에 의해 표시된다. */ 
		while( (nread = read(fd, buf, BUF_SIZE)) >0)
		{
			buf[nread]='\0';
		total+=nread;// total을 증가시킨다. 
		}
		printf ("total chars in sosil: %ld\n", total); 
		close(fd);
		return 0;
		} 
		
	//각자 집에서 쳐보는걸로
