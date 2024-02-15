#include <stdio.h>

int main()
{
    int const n = 3;
    double mas[n][n];
    double sum1, sum2;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("mas[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &mas[i][j]);
        }
 
    printf("\nМатрица:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f  ", mas[i][j]);
        }
        printf("\n");
    }
 
    sum1 = 0;
    sum2 = 0;
 
    for (int i = 0; i < n; i++)
    {
        sum1 += mas[i][i];
        sum2 += mas[i][(n-1)-i];
    }
 
    printf("Сумма главной диагонали = %f\n", sum1);
    printf("Сумма побочной диагонали = %f\n", sum2);

    return 0;
}

