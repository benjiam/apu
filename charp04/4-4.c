
#include <apue.h>

#define RWRWRW (S_IRUSR| S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main()
{
   struct stat statbuf;
   stat("foo", &statbuf);

   chmod("foo",  S_ISGID | (statbuf.st_mode & ~S_IXGRP));
   chmod("bar",  S_ISGID | S_IWUSR | S_IRGRP | S_IROTH);


   return 0;


}
