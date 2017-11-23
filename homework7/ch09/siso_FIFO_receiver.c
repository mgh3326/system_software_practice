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
  mkfifo ("/tmp/namedpipe", 0666);
  fd = open("/tmp/namedpipe", O_RDONLY);

  do {
    if ((num = read(fd, s, 300)) == -1)
        perror("read");
    s[num] = '\0';
    printf("consumer: read %d bytes: \"%s\"\n", num, s);
  } while (num > 0);

  return 0;
}

