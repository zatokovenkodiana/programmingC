Написать программу вычисления максимального числа из введенных пользова-телем в виде одной строки.  
 Использовать для этого макрос (без функции), на вход ко-торому подается массив чисел и их количество. 

#include <stdio.h>

#define MAX_NUMBER(arr, size) ({ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) { 
        if (arr[i] > max) { 
            max = arr[i]; 
        } 
    } 
    max; 
})

int main() {
    int n;
    printf("Введите количество чисел: ");
    scanf("%d", &n);
    
    int numbers[n];
    printf("Введите числа через пробел: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int maxNumber = MAX_NUMBER(numbers, n);
    printf("Максимальное число: %d\n", maxNumber);
    
    return 0;
}
