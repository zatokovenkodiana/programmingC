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




-------------------------------------------------------------------------

   
   
   #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;


int main(int argc, char *argv[]) {
    time_t t1,t0;
    long unsigned int i;
    float diftime;

    t0 = time (NULL);
    
      for(i=0; i<1500000000L; i++);
  //---------------------------------------
    int rows, cols;
    
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);
    
    
    
    int matrix1[rows][cols], matrix2[rows][cols];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = random_number(1, 100); 
            matrix2[i][j] = random_number(1, 100);
        }
    }
    
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("ошибка\n");
        return 1;
    }
    
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix1[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
   
    fclose(file);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = 0;
            matrix2[i][j] = 0;
        }
    }

    return 0;
}
    
 
    
    //--------------------------------------------
   
   t1 = time (NULL);
    diftime = difftime( t1, t0);
    printf("Need time difftime = %f \n", difftime); 
    
    return 0;
}
