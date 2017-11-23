#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char * ptr=malloc(10);
    char * tmp=malloc(10);

    strcpy(ptr, "text");

    printf("realloc() 호출 전 ptr의 값: %p\n",ptr);
    ptr=realloc(ptr,50);//메모리의 크기를 늘려주어서
    //같은 주소를 쓴다면 다른 주소를 침범할 수 있기 때문에
    //새로운 주소를 할당하게 됩니다.
    printf("realloc() 호출 후 ptr의 값: %p\n",ptr);
    strcpy(ptr+strlen(ptr)," appended text");//append하기 위해 길이를 더했구나
    printf("%s\n",ptr);

    free(ptr);
    free(tmp);

    return 0;
}