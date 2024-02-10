#include <stdio.h>
#include <math.h>
int main()
{
   double a, b, c, d, x1, x2;
   int i;
   do {

   printf ("Введите a:");
   scanf ("%lf", &a);
   printf ("Введите b:");
   scanf ("%lf", &b);
   printf ("Введите c:");
   scanf ("%lf", &c);
   
   d=b*b-4*a*c;
   printf("d = %lf", d);
   
  
   if (d>0) {
   x1 = (-b + sqrt(d))/(2*a);
   x1 = (-b - sqrt(d))/(2*a);
   
   printf ("x1=%lf x2=%lf \n", x1, x2);
   }
   if (d == 0) {
       x1 = (-b/(2*a));
       printf ("x1 = %lf \n", x1);
   }
   if (d<0) {
       printf ("Корней нет");
   }
   printf ("Продолжить 1 - да, 2 - нет");
   scanf ("%d", &i);
   } while (i == 1);
    return 0;
}
