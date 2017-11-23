#include <unistd.h>
#include <string.h>
#include <stdio.h>
int rmdir(const char *pathname);
int main(int argc, char *argv[]){
if(chdir(argv[1])){ // chdir을 통해 디렉토리가 존재하는지 확인
perror("directory not found"ee);
return 1;
}
chdir(“..”); // 다시 상위 디렉토리로 이동
rmdir(argv[1]); // 디렉토리 삭제
return 0;
}