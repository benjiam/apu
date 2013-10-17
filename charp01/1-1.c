#include <apue.h>

//#include <dirent.h>
//
//
int
main(int argc, char * argv[])
{
  DIR    *dp = NULL;
  struct dirent *dirp;


  if (argc != 2) {
     printf("usage: ls directory_name\n");
     exit(0);
  }

  if ((dp = opendir(argv[1])) == NULL) {
     printf("open %s", argv[1]);
     exit(1);
   }

   while ((dirp = readdir(dp)) != NULL) {
     printf("%s \n", dirp->d_name);
   }
   closedir(dp);
   exit(0);
}
