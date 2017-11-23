#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
//메시지 수신 프로그램 
int main(int argc,char *argv[])//FIFO 파일경로(파일명)은 프로그램의 첫 번째 인자로 입력 받습니다.
{
   if(argc!=2){
        fprintf(stderr,"Usage:%s pipename\n", argv[0]);
        return 1;
      }
  char s[300];
  int num, fd;
  mkfifo (argv[1], 0666);//fifo 생성
  fd = open(argv[1], O_RDONLY);//읽기 전용
if(fd==-1){
        if(errno!=EEXIST){//생성 실패 할 경우 오류발생
            fprintf(stderr,"failed to create named pipe %s: %s\n", argv[1],strerror(errno));
            return 1;
        }
    }
  do {
    if ((num = read(fd, s, 300)) == -1)
        perror("read");
    s[num] = '\0';//read의 경우 마지막 값이 쓰래기 값이 들어가므로 널값을 넣어 주었습니다.
    if(strstr(s,"quit")&&num==4)//송신 프로그램에서 “quit”를 입력하면 수신 프로그램이 종료됩니다.
    {
      return 0;
    }

    printf("[recv] : %s\n",s);
    s[0] = '\0'; // 배열 내용 지웁니다.
  } while (num>0);//값이 입력되면 반복이 되도록 합니다.

  return 0;
}

