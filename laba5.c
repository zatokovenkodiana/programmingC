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
