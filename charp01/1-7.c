
#include <apue.h>

int
main(int argc, char * argv[])
{
    fprintf(stderr, "userid = %d   groupid = %d\n", getuid(), getgid()); 
    return 0;
} 
