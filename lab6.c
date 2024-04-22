Создать текстовый файл с записями следующего вида: 
Иванов Петр Сергеевич 1975 
Сидоров Николай Андреевич 1981 
...
Воробьянинов Ипполит Матвеевич 1978 

Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года. 

  
#include <stdio.h> 
#include <stdlib.h> 

#define MAX_NAME_LENGTH 50 

typedef struct { 
    char last_name[MAX_NAME_LENGTH]; 
    char first_name[MAX_NAME_LENGTH]; 
    char middle_name[MAX_NAME_LENGTH]; 
    int birth_year; 
} Person; 

int main() { 
    FILE *input_file = fopen("input.txt", "r"); 
    FILE *output_file = fopen("output.txt", "w"); 

    if (input_file == NULL || output_file == NULL) { 
        printf("Ошибка открытия файлов.\n"); 
        return 1; 
    } 

    while (!feof(input_file)) { 
        Person person; 
        fscanf(input_file, "%s %s %s %d\n", person.last_name, person.first_name, person.middle_name, &person.birth_year); 

        if (person.birth_year > 1980) { 
            fprintf(output_file, "%s %s %s %d\n", person.last_name, person.first_name, person.middle_name, person.birth_year); 
        } 
    } 

    fclose(input_file); 
    fclose(output_file); 

    printf("Процесс завершен. Проверьте файл output.txt для результатов.\n"); 

    return 0; 
}
