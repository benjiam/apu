
#include <apue.h>


int main() {
   
   char buff[100] = {0};

   int fd = dup(STDOUT_FILENO);

   sprintf(buff, "1 new fd %d\n", fd);
   write(STDOUT_FILENO, buff, strlen(buff));
   close(STDOUT_FILENO);

   sprintf(buff, "2 new fd %d\n", fd);

   write(STDOUT_FILENO, buff, strlen(buff));
   write(fd, buff, strlen(buff));

   sprintf(buff, "2 new fd %d\n", fd);
   close(fd);

   write(STDOUT_FILENO, buff, strlen(buff));
   write(fd, buff, strlen(buff));
   
   return 0;
}
