
#include <apue.h>


int main(int argc, char *argv[])
{
   
   int fd;
   int newfd;
   if (argc < 2) {
      printf("no argv\n");
      return -1;
   }
   newfd = open("./aaa", O_RDONLY);
   if (newfd == -1) {
    perror("");
   }
   printf("newfd %d\n", newfd);
   fd = atoi(argv[1]); 
   printf("fd = %d\n", fd);
   dup2(fd, 0);
   dup2(fd, 1);
   dup2(fd, 2);
   if (fd > 2) {
       printf(" close %d\n", fd);
       close(fd);
       sleep(120);
   }
   getchar();


    return 0;
}
