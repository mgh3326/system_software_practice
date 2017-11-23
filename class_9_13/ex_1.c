#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv){//인자를 받음
if (argc != 2){
fprintf(stderr, "Usage: mkdir dirname\n");
return 1;
}
if(mkdir(argv[1], 0755)){//반환값 성공 :0, 실패 : -1
perror("mkdir error");
return 1;
} return 0;
}
//예시) ./a.out dirname argv[0]=./a.out argv[1]=dirname