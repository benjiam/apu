

#include "apue.h"


int
main(int argc, char * argv[])
{
    int n;
    char buf[BUFFSIZE];
    char * messagew = "write error\n";
    char * messager = "read <0\n";
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            
            write(STDERR_FILENO, messagew, strlen(messagew) );
            exit(0);
        }
    }
    if (n < 0) {
        write(STDERR_FILENO, messager, strlen(messager));
    }

    exit(0);
}
