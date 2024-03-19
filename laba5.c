Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы массивов ввести с консоли). 
А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) и возвращающую указатель на массив-результат. 
  Разместить эту функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения полученного вектора
  
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







#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int n;
    double *data;
} Matrix;

Matrix* createMatrix(unsigned int n) {
    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));
    mat->n = n;
    mat->data = (double*)malloc(n * n * sizeof(double));
    return mat;
}

void freeMatrix(Matrix *mat) {
    free(mat->data);
    free(mat);
}

Matrix* matrixOperation(const Matrix *mat1, const Matrix *mat2, char op) {
    Matrix *result = createMatrix(mat1->n);
    for (unsigned int i = 0; i < mat1->n; ++i) {
        for (unsigned int j = 0; j < mat1->n; ++j) {
            double value;
            if (op == '+') {
                value = mat1->data[i * mat1->n + j] + mat2->data[i * mat2->n + j];
            } else if (op == '-') {
                value = mat1->data[i * mat1->n + j] - mat2->data[i * mat2->n + j];
            } else if (op == '*') {
                value = mat1->data[i * mat1->n + j] * mat2->data[i * mat2->n + j];
            }
            result->data[i * result->n + j] = value;
        }
    }
    return result;
}

void printMatrix(const Matrix *mat) {
    printf("Matrix[%d, %d]:\n", mat->n, mat->n);
    for (unsigned int i = 0; i < mat->n; ++i) {
        for (unsigned int j = 0; j < mat->n; ++j) {
            printf("%f ", mat->data[i * mat->n + j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned int n;
    printf("Введите размерность n: ");
    scanf("%d", &n);

    Matrix *mat1 = createMatrix(n);
    Matrix *mat2 = createMatrix(n);

    printf("Введите элементы матрицы 1[%d, %d]:\n", n, n);
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            scanf("%lf", &mat1->data[i * n + j]);
        }
    }

    printf("Введите элементы матрицы 2[%d, %d]:\n", n, n);
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            scanf("%lf", &mat2->data[i * n + j]);
        }
    }

    char op;
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &op);

    Matrix *result = matrixOperation(mat1, mat2, op);
    printMatrix(result);

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(result);

    return 0;
}




#include <stdio.h>
#include "matrix.h"

int main() {
    unsigned int n;
    printf("Введите размерность n: ");
    scanf("%d", &n);

    Matrix *mat1 = createMatrix(n);
    Matrix *mat2 = createMatrix(n);

    printf("Введите элементы матрицы 1[%d, %d]:\n", n, n);
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            scanf("%lf", &mat1->data[i * n + j]);
        }
    }

    printf("Введите элементы матрицы 2[%d, %d]:\n", n, n);
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            scanf("%lf", &mat2->data[i * n + j]);
        }
    }

    char op;
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &op);

    Matrix *result = matrixOperation(mat1, mat2, op);
    printMatrix(result);

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(result);

    return 0;
}


#ifndef MATRIX_H
#define MATRIX_H


typedef struct {
    unsigned int n;
    double *data;
} Matrix;

Matrix* createMatrix(unsigned int n);
void freeMatrix(Matrix *mat);
Matrix* matrixOperation(const Matrix *mat1, const Matrix *mat2, char op);
void printMatrix(const Matrix *mat);

#endif


#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* createMatrix(unsigned int n) {
    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));
    mat->n = n;
    mat->data = (double*)malloc(n * n * sizeof(double));
    return mat;
}

void freeMatrix(Matrix *mat) {
    free(mat->data);
    free(mat);
}

Matrix* matrixOperation(const Matrix *mat1, const Matrix *mat2, char op) {
    Matrix *result = createMatrix(mat1->n);
    for (unsigned int i = 0; i < mat1->n; ++i) {
        for (unsigned int j = 0; j < mat1->n; ++j) {
            double value;
            if (op == '+') {
                value = mat1->data[i * mat1->n + j] + mat2->data[i * mat2->n + j];
            } else if (op == '-') {
                value = mat1->data[i * mat1->n + j] - mat2->data[i * mat2->n + j];
            } else if (op == '*') {
                value = mat1->data[i * mat1->n + j] * mat2->data[i * mat2->n + j];
            }
            result->data[i * result->n + j] = value;
        }
    }
    return result;
}

void printMatrix(const Matrix *mat) {
    printf("Matrix[%d, %d]:\n", mat->n, mat->n);
    for (unsigned int i = 0; i < mat->n; ++i) {
        for (unsigned int j = 0; j < mat->n; ++j) {
            printf("%f ", mat->data[i * mat->n + j]);
        }
        printf("\n");
    }
}
---------------------------------------------------------------------------------------

  
#include <stdio.h>




int main()
{
    
    double **m1,**m2, **result;
    int n;
    printf("vvedite razmer matici:");
    scanf("%d",&n);
    
     // Выделение памяти под указатели на строки
    m1 = (double**)malloc(n * sizeof(double*));
    // Ввод элементов массива
    for (i = 0; i < n; i++) // цикл по строкам
    {
      // Выделение памяти под хранение строк
      m1[i] = (double*)malloc(n * sizeof(double));
      for (j = 0; j < m; j++) // цикл по столбцам
      {
         printf("m1[%d][%d] = ", i, j);
         scanf("%lf", &m1[i][j]);
      }
    }
 
    result = matrix_sum(m1,m2,n);
    
    printmatrix(m3);
    
         // Выделение памяти под указатели на строки
    m2 = (double**)malloc(n * sizeof(double*));
    // Ввод элементов массива
    for (i = 0; i < n; i++) // цикл по строкам
    {
      // Выделение памяти под хранение строк
      m2[i] = (double*)malloc(n * sizeof(double));
      for (j = 0; j < n; j++) // цикл по столбцам
      {
         printf("m2[%d][%d] = ", i, j);
         scanf("%lf", &m2[i][j]);
      }
    }
    
    
    
    // Очистка памяти
    for (i = 0; i < n; i++) // цикл по строкам
      free(m1[i]);  // освобождение памяти под строку
    free(m1);
    
        // Очистка памяти
    for (i = 0; i < n; i++) // цикл по строкам
      free(m2[i]);  // освобождение памяти под строку
    free(m2);

    return 0;
}


matrix.c

  double **matrix_sum(double **m1, double **m2, int n){
    double **result;

// Выделение памяти под указатели на строки
    m1 = (double**)malloc(n * sizeof(double*));
    // Ввод элементов массива
    for (i = 0; i < n; i++) // цикл по строкам
    {
      // Выделение памяти под хранение строк
      m1[i] = (double*)malloc(n * sizeof(double));
      for (j = 0; j < m; j++) // цикл по столбцам
      
    }
    
          // Выделение памяти под указатели на строки
    m2 = (double**)malloc(n * sizeof(double*));
    // Ввод элементов массива
    for (i = 0; i < n; i++) // цикл по строкам
    {
      // Выделение памяти под хранение строк
      m2[i] = (double*)malloc(n * sizeof(double));
      for (j = 0; j < n; j++) // цикл по столбцам
      
    }

        for(int i=0;i<m;i++)
          for(int j=0;j<m;j++) {
            result = m1[n][n] + m2[n][n];
            
          }
    }

    
    
    
    return result;
} 

void printmatrix(duble **m){
    
}



____________________________________________________________________


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





