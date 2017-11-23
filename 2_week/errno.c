#include <stdio.h> 
#include <fcntl.h> 
#include <errno.h> 
int main(){ 
	int fd; 
	if ( (fd = open ("nonesuch", O_RDONLY)) == -1) 
        //fprintf(stderr, "error %d\n", errno);
        perror("error opening nonesuch");
	return 0;
} 
