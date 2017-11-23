#include<stdio.h>
#include<stdlib.h>

int main(){//피보나치 수열
    int size, i;

    scanf("%d",&size);
    int* buffer=(int*)malloc(size * sizeof(int));

    buffer[0]=buffer[1]=1;

    for(i=0;i<size;i++){//마지막에는 8이 접근됨 이거 왜 에러 안뜨지
        //overflow
        buffer[i+2]=buffer[i+1]+buffer[i];
        printf("%d ",buffer[i]);
    }
    printf("\n");
    printf("%d\n",buffer[i]);
    printf("%d\n",buffer[i+1]);
    printf("%d\n",buffer[i+3]);
    
    return 0;
}