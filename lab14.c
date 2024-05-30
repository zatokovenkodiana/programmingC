Написать программу с использованием нелокального перехода setjmp/longjmp, которая вычисляет сумму чисел Фибоначчи (начиная с1, 1,...). 
  Использовать рекурсивную функции для вычисления суммы, в качестве механизма возврата из вложенных вызовов использовать нелокальный переход. 

  
#include <stdio.h>
#include <setjmp.h>

int main(){
    int a = 1, b = 1, c = 0, n = 0;
    scanf("%d", &n);
    if (n < 3){
        printf("1");
        return 0;
    }
    jmp_buf env = {0};
    int val = setjmp(env);
    c = a + b;
    a = b;
    b = c;
    if(val < n - 3) longjmp(env, val + 1);
    printf("%d", c);
    return 0;
}
