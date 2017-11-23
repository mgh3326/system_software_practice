#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
//메시지 송신 프로그램
int main(int argc,char *argv[])//FIFO 파일경로(파일명)은 프로그램의 첫 번째 인자로 입력 받습니다.
{
   if(argc!=2){
        fprintf(stderr,"Usage:%s pipename\n", argv[0]);
        return 1;
      }
     
  char s[300];
  int num, fd;

  mkfifo(argv[1] , 0666);//fifo 생성
  fd = open(argv[1], O_WRONLY); //쓰기 전용
if(fd==-1){
        if(errno!=EEXIST){//생성 실패 할 경우 오류발생
            fprintf(stderr,"failed to create named pipe %s: %s\n", argv[1],strerror(errno));
            return 1;
        }
    }
  while (1) {
        printf("[send] : ");
        fgets(s,300,stdin);
        s[strlen(s) - 1] = '\0';//fgets의 경우 마지막에 개행 문자가 있기에 없애주기 위해 널값을 넣어주었습니다.
        
    if ((num = write(fd, s, strlen(s))) == -1)
          perror("write");
          if(strstr(s,"quit")&&num==4)//송신 프로그램에서 “quit”를 입력하면 송신 프로그램이 종료됩니다.
        {      
        return 0;
        }
          s[0] = '\0'; // 배열 내용 지웁니다.

  }
  return 0;
}
