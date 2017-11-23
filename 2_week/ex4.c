#include <unistd.h>
#include <fcntl.h>
/* copyfile -- name1을 name2로 복사한다 */ 

#define BUF_SIZE 512// 읽혀질 덩어리의 크기  
#define PERM 0644// 새 파일의 권한  
/* name1을 name2로 복사한다*/ 
int copyfile(const char*name1,const char *name2)
{
	int infile,outfile;
	ssize_t nread;
	char buf[BUF_SIZE];
	if((infile=open(name1, O_RDONLY))== -1)
		return (-1);

	if((outfile=open(name2,O_WRONLY|O_CREAT|O_TRUNC,PERM))==-1){
		close(infile);
		return (-2);
	}
	//이제 name1으로부터 한 번에 BUF_SIZE 문자를 읽는다
	while((nread=read(infile,buf,BUF_SIZE))>0){
				if(write(outfile,buf,nread)<nread){/* buf를 출력 파일에 쓴다. */ 					
				close(infile);
				close(outfile);
				if(nread==-1)
				return(-3);// 쓰기 오류
				}
				}
				close (infile);
				close (outfile);
				if(nread ==1)
				return (-4);// 마지막 읽기에서 오류 발생
				else
				return (0);
				}

int main(){/* "copyfile"을 테스트하는 main 함수 */ 
copyfile("test.in","test.out");
return 0;
}
