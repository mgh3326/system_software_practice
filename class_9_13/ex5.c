#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
int main(){
FILE *fs1, *fs2;
struct stat filestat;
int nRet=0;
if((fs1 = fopen("image/test.jpg", "rb")) != NULL) {//읽기전용으로 바이너리 파일을 연다.
unsigned char *pImgFile;
fstat( fileno ( fs1 ), &filestat );//fileno : 파일 포인터를 파일 기술자로 변경할때 사용됨
// QIBM_USE_DESCRIPTOR_STDIO 환경 변수가 Yes로 설정된 경우 fileno() 함수는 stdin에 대해 0을, stdout에 대해 1을, stderr에 대해 2를 리턴합니다.
// QIBM_USE_DESCRIPTOR_STDIO가 No로 설정된 경우 ILE C 세션 파일 stdin, stdout, stderr에는 연관된 파일 설명자가 없습니다. fileno() 함수는 이 경우 -1 값을 리턴합니다.
// errno 값을 EBADF로 설정할 수 있습니다.
pImgFile = ( unsigned char* )malloc( filestat.st_size);//filestat을 이용한 메모리 할당
memset(pImgFile, 0x00, filestat.st_size);//memset으로 메모리 초기화
nRet = fread((unsigned char*)pImgFile,1,filestat.st_size,fs1);//버퍼 주소, 버퍼의 크기, 읽어올 항목의 수, 파일 포인터
fclose(fs1);
if((fs2=fopen("TestImgData.lsf", "wb")) != NULL){//새로 쓰기용으로 바이너리 파일을 연다. 기존 내용은 삭제된다.
nRet = fwrite((void*)pImgFile,filestat.st_size,1,fs2);//버퍼 주소, 항목의 크기, 항목 수, 파일 포인터
fclose(fs2);
}
free(pImgFile);//메모리 초기화
}// end if
else{
    perror("fopen: image/test.jpg");
    exit(1);
}
return 0;
}// end main