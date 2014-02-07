
#include <apue.h>

#define RWRWRW (S_IRUSR| S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{

   int i = open("testtmp", O_RDWR);
   printf("open %d\n", i);
   unlink("testtmp");
   printf("file unlinked\n");
   sleep(15);

   printf("done \n");

   return 0;


}
