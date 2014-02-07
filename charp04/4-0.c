
#include <apue.h>
void showstat(struct stat *);

typedef int (*xx) ( struct stat);

struct aaa {
   xx s1;
   char *name;
};

#define p(S) \
int p##S (struct stat M) \
{      \
  return (int)S(M.st_mode);      \
}
p(S_ISDIR)

p(S_ISREG)

p(S_ISCHR)

p(S_ISBLK)

p(S_ISFIFO)

p(S_ISLNK)

p(S_ISSOCK)


int main(int argc, char * argv[])
{ 
  char *pfile = 0;
  struct stat pstat = {0};
  if (argc >=2 ) {
      pfile = argv[1];
      stat(pfile, &pstat);
      showstat(&pstat);

      lstat(pfile, &pstat);
      showstat(&pstat);



   }
  


   return 0;
}



void showstat(struct stat *pstat){
  int i = 0;
  struct aaa a[10] = {0};
  a[1].s1 = &pS_ISREG;
  a[1].name = "regua";

  a[0].s1 = &pS_ISDIR;
  a[0].name = "dir";

  a[2].s1 = &pS_ISCHR;
  a[2].name = "char ";


  a[3].s1 = &pS_ISBLK;
  a[3].name = "block ";

  a[4].s1 = &pS_ISFIFO;
  a[4].name = "fifo ";


  a[5].s1 = &pS_ISLNK;
  a[5].name = "link ";

  
  a[6].s1 = &pS_ISSOCK;
  a[6].name = "sock ";
   for (i = 0; i <=6; ++i)  {
     if (a[i].s1(*pstat)) {
        printf("%s\n", a[i].name);
        break;
     }
   }

   printf("show stat\n");
   printf("mode %d\n", pstat->st_mode);
   printf("ino %d\n", pstat->st_ino);
   printf("nlink %d\n", pstat->st_nlink);
   printf ("\n");
}
