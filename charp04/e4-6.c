

#include <apue.h>

int main(int argc, char *argv[])
{
   if (argc == 3)
   {
     printf("cp\n");
     link(argv[1], argv[2]);
   
   }
   return 0;

}
