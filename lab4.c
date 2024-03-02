#include <stdio.h>
#include <math.h>

int isTriangleValid(float a, float b, float c) {
    if (a + b > c && b + c > a && a + c > b)
        return 1; 
    else
        return 0; 
}
 
float calculatePerimeter(float a, float b, float c) {
    return a + b + c; 
}
 
float calculateArea(float a, float b, float c) {
    float p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
 
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
