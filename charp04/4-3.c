
#include <apue.h>

#define RWRWRW (S_IRUSR| S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
   printf("umask %d \n", umask(0));
   printf(" set to 0\n");
   creat("foo", RWRWRW);

   umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
   creat("bar", RWRWRW);
   return 0;


}
