#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
  char s[300];
  int num, fd;

  mkfifo("/tmp/namedpipe" , 0666);
  fd = open("/tmp/namedpipe", O_WRONLY); 

  while (gets(s)) {
    if ((num = write(fd, s, strlen(s))) == -1)
          perror("write");
    printf("producer: wrote %d bytes\n", num);
  }
  return 0;
}
