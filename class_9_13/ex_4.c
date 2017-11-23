#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char**argv){
	char buf[255];
	printf("argc:%d,argv[0]:%s,argv[1]:%s\n",argc,argv[0],argv[1]);
	//int n=0;
	if(chdir(argv[1]))//IF (a) 는 IF (a != 0)과 같은 구문이고 IF (!a)는 IF (a == 0)과 같은 구문입니다.
	{
		perror("error");
		return 1;
	}
	//printf("%d\n",n);
	getcwd(buf,255);//경로명 리턴
	printf("pwf :%s\n",buf);
	return 0;
}
