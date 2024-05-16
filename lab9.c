Реализовать программу-калькулятор с возможностью выполнения арифметиче-ских действий (+, -), унарный и бинарный вариант. 
У пользователя запрашивается вы-ражение, например, "-123.5 + 4 - 456+56", программа должна решить выражение.
    Для разбора входной строки использовать функцию strok. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculate(char *expression) {
    char *token = strtok(expression, " ");
    float result = atof(token);

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
    printf("Enter expression: ");
    fgets(expression, 100, stdin);

    char *pos;
    if ((pos=strchr(expression, '\n')) != NULL) {
        *pos = '\0';
    }

    printf("Result: %.2f\n", calculate(expression));

    return 0;
}
