1.
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
2.
#include <stdio.h>

int main()
{
  int n=2;
    double mas[n][n];
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            printf("mas[%d][%d] = ", i+1, j+1);
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
    int vozv_matrix[n][n];
    int i, j, k = 0, l;
    while (k < 2)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                vozv_matrix[i][j] = 0;
                for (l = 0; l < n; l++)
                    vozv_matrix[i][j] += (mas[i][l] * mas[l][j]);
                k++;
            }
    }
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<n; j++)
        {
            printf("%d  ", vozv_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
