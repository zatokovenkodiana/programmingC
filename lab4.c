Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). 
Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) 
и выдать на консоль вычис-ленные с помощью написанных функций значения его периметра и площади. 

main.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "triangle.h"
int main() {
    float side1, side2, side3;
    printf("Введите длины сторон треугольника: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    if (isTriangleValid(side1, side2, side3)) {
        float perimeter = calculatePerimeter(side1, side2, side3);
        float area = calculateArea(side1, side2, side3);

        printf("Периметр треугольника: %.2f\n", perimeter);
        printf("Площадь треугольника: %.2f\n", area);
    }
    else {
        printf("Треугольник с указанными сторонами не существует.\n");
    }
    
    return 0;
}

triangle.h
#include <stdbool.h>
bool isTriangleValid(float a, float b, float c);
float calculatePerimeter(float a, float b, float c);
float calculateArea(float a, float b, float c);

triangle.c
#include <math.h>
#include <stdbool.h>
bool isTriangleValid(float a, float b, float c) {
    if (a + b > c && b + c > a && a + c > b)
        return true; 
    else
        return false; 
}
 
float calculatePerimeter(float a, float b, float c) {
    return a + b + c; 
}
 
float calculateArea(float a, float b, float c) {
    float p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
