#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
	
struct dirent* direntp;
DIR *dirp;

dirp=opendir("dirPath");

while((direntp=readdir(dirp))!=NULL){
	printf("%s\n",direntp->d_name);
}
}