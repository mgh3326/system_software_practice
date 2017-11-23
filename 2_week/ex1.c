#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()	{
	int fd;
	ssize_t nread;
	char buf[1024];

	 /* opening the file for reading */
	 fd = open("data", O_RDONLY);

	 /* reading the data */
	 nread = read(fd, buf, 1024);
    printf("nread : %zd\n",nread);
	 /* close the file */
	 close(fd);		 
     return 0;
}
