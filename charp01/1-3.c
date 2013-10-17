

#include "apue.h"


int
main(int argc, char * argv[])
{
    int c;
    char * messagew = "write error\n";
    char * messager = "read <0\n";
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF)
        {
            write(STDERR_FILENO, messagew, strlen(messagew) );
            exit(0);
        }
    }
    if (ferror(stdin)) {
        write(STDERR_FILENO, messager, strlen(messager));
    }

    exit(0);
}
