Реализовать программу-калькулятор с возможностью выполнения арифметиче-ских действий (+, -), унарный и бинарный вариант. 
У пользователя запрашивается вы-ражение, например, "-123.5 + 4 - 456+56", программа должна решить выражение.
    Для разбора входной строки использовать функцию strok. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

double calculate(char *expression) {
    char *token = strtok(expression, " ");
    double result = atof(token);
    char *next_token;

    while ((token = strtok(NULL, " ")) != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok(NULL, " ");
            result += atof(token);
        } else if (strcmp(token, "-") == 0) {
            token = strtok(NULL, " ");
            result -= atof(token);
        }
    }
    return result;
}

int main() {
    char expression[100];
    printf("Введите выражение: ");
    fgets(expression, 100, stdin);
    expression[strcspn(expression, "\n")] = 0;

    double result = calculate(expression);
    printf("Результат: %f\n", result);

    return 0;
}
