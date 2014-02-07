

#include <apue.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
  int fd = 0;

  if ((fd = creat("file.hole", O_CREAT)) < 0)
  {
      perror("create error");
      return 0;
  }

  write(fd, buf1, 10);
  lseek(fd, 1024*1024*8, SEEK_SET);
  write(fd, buf2, 10);

  close(fd);

  return 0;


}

