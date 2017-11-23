#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char * ptr=malloc(15);
    char * tmp=malloc(15);
    char *newptr;
    strcpy(ptr, "text");
    strcpy(tmp,"1234");

   // newptr=realloc(ptr,30);
   
    strcpy(ptr," appended text");//append하기 위해 길이를 더했구나
   
    int i;
    for(i=0;i<120;i++)
    printf("%c ",(char)ptr[i]);

    return 0;
}
