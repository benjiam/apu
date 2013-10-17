#include <apu.h>

int mydup2(int src, int desc);

int mydup2(int src, int desc)
{
   if (src == desc) {
       return src;
   }
   close(desc);
   if (-1 == fcntl(src, F_DUPFD, desc)) {
       retunr -1;
   } 
   return src;
}



int main()
{

   
}
