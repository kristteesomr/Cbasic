#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   float val;
   int val1;
   char str[20];

   strcpy(str, "98993489");
   val1 = atoi(str);
   printf("Gia tri duoi dang chuoi = %s, \nGia tri duoi dang so thuc = %d\n", str, val1);

   strcpy(str, "QTM.com");
   val = atof(str);
   printf("\nGia tri duoi dang chuoi = %s, \nGia tri duoi dang so thuc = %f\n", str, val);

   return(0);
}