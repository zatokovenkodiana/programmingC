Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли). 
А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвращающую указатель на массив-результат. 
Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения полученного вектора

____________________________________________________________________

main.c
    
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    
    int n;
    double **m1 = (double**)malloc(n * sizeof(double*));
    double **m2 = (double**)malloc(n * sizeof(double*));
   
    printf("Введите размер матрицы:");
    scanf("%d",&n);
    

    printf("Введите элементы матрицы 1:\n");
    for (int i = 0; i < n; i++) {
        m1[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &m1[i][j]);
        }
    }

    printf("Введите элементы матрицы 2:\n");
    for (int i = 0; i < n; i++) {
        m2[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &m2[i][j]);
        }
    }

    char operation;
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);
    
    double **result;
    if (operation == '+') {
        result = matrix_sum(m1, m2, n);
    } else if (operation == '-') {
        result = matrix_minus(m1, m2, n);
    } else if (operation == '*') {
        result = matrix_product(m1, m2, n);
    } else {
        printf("Ошибка!");
        return 1;
    }
 

    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    


 // Очистка памяти
    for (int i = 0; i < n; i++) {
        free(m1[i]);
        free(m2[i]);
        free(result[i]);
    }
    free(m1);
    free(m2);
    free(result);

    return 0;
}



matrix.h
#ifndef MATRIX_H
#define MATRIX_H

double **matrix_sum(double **m1, double **m2, int n);
double **matrix_minus(double **m1, double **m2, int n);
double **matrix_product(double **m1, double **m2, int n);

#endif


matrix.c

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

    double **matrix_sum(double **m1, double **m2, int n) {
    double **result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

    double **matrix_minus(double **m1, double **m2, int n) {
    double **result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result;
}

    double **matrix_product(double **m1, double **m2, int n) {
    double **result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

__________________________________________________________________________________________________
Результать сделать функцией 

 void printm(int n, double** m1, double **m2) {
    double **result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
    
}
         
         
         

