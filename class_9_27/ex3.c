#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    char* buffer1=(char*)malloc(50*sizeof(char));
    //for(i=0;i<80;i++)//vioration
    for(i=0;i<80;i++)//vioration
    buffer1[i]=3;
    // char* buffer2=(char*)malloc(50*sizeof(char));
    //malloc으로 하면 침범 당한 메모리가 3으로 남아 있게 됩니다.
    char* buffer2=(char*)calloc(50,sizeof(char));
    for(i=0;i<50;i++)
    printf("%d ",buffer2[i]);
  
    printf("\n");

    return 0;
}