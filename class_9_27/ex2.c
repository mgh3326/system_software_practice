#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i;
    char* buffer1=(char*)malloc(50*sizeof(char));
    char* buffer2=(char*)malloc(50*sizeof(char));

    memset(buffer1,1,50);
    memset(buffer2,2,50);

    //for(i=0;i<80;i++)//violation
    for(i=0;i<80;i++)
    buffer1[i]=3;//얘가 50까지인데 30만큼은 vioration이 일어나서
    //buffer2의 메모리에 침범하게된다.
    printf("\n");

    for(int i=0;i<50;i++)
    printf("%d ",buffer2[i]);
    printf("\n");
    return 0;
}