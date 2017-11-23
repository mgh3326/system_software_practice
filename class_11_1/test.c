#include <sys/time.h>
#include <stdio.h>
int main()
{
	struct timeval tpend;
	struct timeval tpstart;

	if(gettimeofday(&tpstart,NULL)){
		fprintf(stderr,"Fail to get");
		return 1;
	}

	if(gettimeofday(&tpend,NULL)){
		fprintf(stderr,"Failed to get");
		return 1;
	}
	printf("tpstart : %ld\n tpend : %ld\n",tpstart,tpend);
}
