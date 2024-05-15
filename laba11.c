Создать в отдельном модуле функции с переменным количеством аргументов, которая вычисляет их сумму, максимум, минимум, среднее арифметическое. 


#include <time.h>
#include <stdio.h>
#include <stdarg.h>

int add_num(int n, ...)
{
    int res = 0;
    va_list list;
    va_start(list, n);
    while (n)
    {
        res += va_arg(list, int);
        --n;
    }
    va_end(list);
    return res;
    
}

int main() {
    int res = 0;
    res = add_num(5, 1,2,3,4,5);
    printf("res=%d", res);
}
    
