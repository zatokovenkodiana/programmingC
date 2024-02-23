#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char inputString[80]; 
    printf("Введите строку: ");
    fgets(inputString, 80, stdin); 

    for (int i = 0; i < strlen(inputString); i++) {
        if (inputString[i] == 'a' || inputString[i] == 'b') {
            inputString[i] = toupper(inputString[i]);
        }
    }
   
    printf("Результат: %s", inputString);

    return 0;
}
