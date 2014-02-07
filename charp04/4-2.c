
#include <apue.h>

int main(int argc, char *argv[])
{
   int i = 0;
   if (argc != 2)
   {
       printf("sss\n");
       return -1;
   }
   struct vv
   {
     int mode;
     char * name;
   };

   struct vv v1[4];
   v1[0].mode = R_OK;
   v1[0].name = "R_OK";


   v1[1].mode = W_OK;
   v1[1].name = "W_OK";


   v1[2].mode = X_OK;
   v1[2].name = "X_OK";


   v1[3].mode = F_OK;
   v1[3].name = "F_OK";

   for (i = 0; i < sizeof(v1)/sizeof(v1[0]); ++i)
   if (access(argv[1], v1[i].mode) < 0) {

      printf("%s FAILED \n", v1[i].name);
   } else {

      printf("%s SUCCESS \n", v1[i].name);
   }
 
}
