
#include <apue.h>

int
main(int argc, char * argv[])
{
   char buf[MAXLINE] = {0};
   pid_t pid;
   int status;
   int i = 0;
   printf("%%");

   while (fgets(buf, MAXLINE, stdin) != NULL) {
	   if (buf[strlen(buf) -1] == '\n') {
		   buf[strlen(buf) -1] = 0;
	   }

	   for (i = 0; i < 8; ++i) {
		   if ((pid = fork()) < 0) {
			   printf ("fork error\n");
			   exit(0);
		   } else if (pid == 0) {
			   printf("fork %d times\n", i+1);
			   execlp(buf, buf, (char *)0);
			   exit(127);

		   } else {
			   if ((pid = waitpid(pid, &status, 0)) < 0)
				   exit(128);
                           //printf("%d\n", i);
                           if (i >= 7) {
			       printf("%% ");
                               fsync(STDOUT_FILENO);
                           }           
		   }
	   }
           printf("for done\n");
   }

   printf("exit\n");
   exit(0);
} 
