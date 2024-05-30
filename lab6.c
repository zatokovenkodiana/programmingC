Создать текстовый файл с записями следующего вида: 
Иванов Петр Сергеевич 1975 
Сидоров Николай Андреевич 1981 
Мухоморов Святослав Рюрикович 1961
Акулов Еремей Емельянович 1990
Воробьянинов Ипполит Матвеевич 1978 

Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года. 
  
#include <stdio.h>

int main() {
    FILE *in_file, *out_file;
    char first_name[20], middle_name[20], last_name[20]; 
    int year; 

    in_file = fopen("input.txt", "r");  //открывает файл для чтения
    out_file = fopen("output.txt", "w");  //открывает файл и создает пустой файл для записи

    while (fscanf(in_file, "%s %s %s %d", last_name, first_name, middle_name, &year) == 4) {
        if (year > 1980) {
            fprintf(out_file, "%s %s %s %d\n", last_name, first_name, middle_name, year);  //если файл заполнен, то читает его и записывает в выходной файл данные, которые удовлетворяют условию
        }
    }

    fclose(in_file);
    fclose(out_file);  //закрывает файлы

    return 0;
}
