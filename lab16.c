Написать программу подсчитывающая количество битов, выставленных в единицу у числа типа long и double. Сами значения чисел вводятся с клавиатуры.

#include <stdio.h>

int countBitsLong(long num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int countBitsDouble(double num) {
    int count = 0;
    unsigned long long *ptr = (unsigned long long *)&num;
    unsigned long long bits = *ptr;
    
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}

int main() {
    long num_long;
    double num_double;

    printf("Введите целое число типа long: ");
    scanf("%ld", &num_long);
    printf("Введите число типа double: ");
    scanf("%lf", &num_double);

    int count_long = countBitsLong(num_long);
    int count_double = countBitsDouble(num_double);

    printf("Количество единичных битов в числе типа long: %d", count_long);
    printf("Количество единичных битов в числе типа double: %d", count_double);

    return 0;
}

____________________________________________________________________________________

Пример ввода программы:

Введите целое число типа long: 100
Введите число типа double: 3.14
