Написать программу с использованием нелокального перехода setjmp/longjmp, которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). 
  Использовать рекурсивную функции для вычисления суммы, в качестве механизма возврата из вложенных вызовов использовать нелокальный переход. 

  
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int fib(int n) {
    if (n <= 0) {
        longjmp(buf, 1);
    }
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int n;
    printf("Введите значение n для вычисления суммы чисел Фибоначчи: ");
    scanf("%d", &n);

    if (setjmp(buf) == 0) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total += fib(i);
        }
        printf("Сумма чисел Фибоначчи до %d равна: %d\n", n, total);
    } else {
        printf("ошибка!\n");
    }

    return 0;
}
