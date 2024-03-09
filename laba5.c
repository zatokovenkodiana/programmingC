Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли). 
А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвра-щающую указатель на массив-результат. 
  Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения по-лученного вектора

  #include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    
    int n, m;
    
    double **matrix1
    double **matrix2
    
    matrix1 = (double**)malloc(n*sizeof(double*));
    for(i=0; i<n; i++) {
        matrix1[i] = (double*)malloc(m*sizeof(double));
    }
    matrix1[n][m]
    matrix2 = (double*)malloc(n*sizeof(double));
    for(i=0; i<n; i++) {
        matrix2[i] = (double*)malloc(m*sizeof(double));
    }
    
    printf("Введите размерность матрицы: ");
    scanf("%d", &n);

    printf("Введите элементы первой матрицы: ");
    for (int i = 0; i < n*n; i++) {
        scanf("%lf", &matrix1[i]);
    }

    printf("Введите элементы второй матрицы: ");
    for (int i = 0; i < n*n; i++) {
        scanf("%lf", &matrix2[i]);
    }

    
    return 0;
}

