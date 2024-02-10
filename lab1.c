/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
int main()
{
   double a, b, c, d, x1, x2;
   
   a=5.1;
   b=1;
   c=-2.2;
   
   d=b*b-4*a*c;
   printf("d = %lf", d);
   
   x1 = (-b + sqrt(d))/(2*a);
   x1 = (-b - sqrt(d))/(2*a);
   
   printf ("x1=%lf x2=%lf \n", x1, x2);
    return 0;
}
