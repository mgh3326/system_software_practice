#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *workfile="junk";

int main(){
	int fd;

	if((fd=open(workfile,O_RDWR))==-1){
		printf("Couldn't open %s\n", workfile);
		exit(1);
	}
	printf("%d\n",fd);
	return 0;
}
