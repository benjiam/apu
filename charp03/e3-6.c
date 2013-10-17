#include <apue.h>


int main()
{

  char * stdout = "stdout string\n";
  char * stderr = "stderr string\n";


  sleep(10);


  write(STDOUT_FILENO, stdout, strlen(stdout));
  write(STDERR_FILENO, stderr, strlen(stderr));

  return 0;



   
}
