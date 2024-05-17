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
__________________________________________________________________________________________________________________________________________________

#include <stdio.h>   
#include <stdarg.h>

int sum(int num_args, ...)  
{
    va_list args;
    va_start(args, num_args);
    
    int total = 0;
    for (int i = 0; i < num_args; i++)
    {
        total += va_arg(args, int);
    }
    
    va_end(args);
    
    return total;
}

int max(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    
    int maximum = va_arg(args, int);
    for (int i = 1; i < num_args; i++)
    {
        int current = va_arg(args, int);
        if (current > maximum)
        {
            maximum = current;
        }
    }
    
    va_end(args);
    
    return maximum;
}

int min(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    
    int minimum = va_arg(args, int);
    for (int i = 1; i < num_args; i++)
    {
        int current = va_arg(args, int);
        if (current < minimum)
        {
            minimum = current;
        }
    }
    
    va_end(args);
    
    return minimum;
}

float average(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    
    int total = 0;
    for (int i = 0; i < num_args; i++)
    {
        total += va_arg(args, int);
    }
    
    va_end(args);
    
    return(float)total / num_args;
}

int main()
{
    printf("Сумма: %d\n", sum(5, 1,2,3,4,5));
    printf("Максимум: %d\n", max(5, 1,2,3,4,5));
    printf("Минимум: %d\n", min(5, 1,2,3,4,5));
    printf("Среднее арифметическое: %.2f\n", average(5, 1,2,3,4,5));
    
    return 0;
}
