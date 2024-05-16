Дано натуральное число N. Выведите все его цифры по одной, в обычном по-рядке (а потом в обратном), 
  разделяя их пробелами или новыми строками. Например: 179 => 1 7 9; 179 => 9 7 1 
При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется). 


#include <stdio.h>

void printDigits(int n) {
    int digit = n % 10;
    if (n / 10 != 0) {
        printDigits(n / 10);
    }
    printf("%d ", digit);
}

void printReverseDigits(int n) {
    int digit = n % 10;
    printf("%d ", digit);
    if (n / 10 != 0) {
        printReverseDigits(n / 10);
    }
}

int main() {
    int N;
    printf("Enter a natural number: ");
    scanf("%d", &N);

    printf("Digits of %d in order: ", N);
    printDigits(N);
    printf("\n");

    printf("Digits of %d in reverse order: ", N);
    printReverseDigits(N);
    printf("\n");

    return 0;
}
