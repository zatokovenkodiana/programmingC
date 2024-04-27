Создать текстовый файл с записями следующего вида: 
Иванов Петр Сергеевич 1975 
Сидоров Николай Андреевич 1981 
Мухоморов Святослав Рюрикович 1961
Акулов Еремей Емельянович 1990
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
______________________________________________________________________________________



#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f1, *f2;
    char s[80];
    char s1[80];
    char s2[80];
    char s3[80];
    int y;
    f1 = fopen("1.txt", "r");
    f2 = fopen("2.txt", "w");
    
    while (fgets(s,80,f1)!=NULL){
        sscanf(s,"%s %s %s %d", s1,s2,s3,&y);
        printf("%s %s %s %d \n", s1,s2,s3,y);
        if (y>1980){
            fprint(f2,"%s", s);
        }
    }
    
    fclose(f1);
    fclose(f2);

    return 0;
}
_______________________________________________________________________________________________


#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    FILE *fp1, *fp2;
    /*
    fp1 = fopen("input.txt", "w");
    char s[10] = "abcdefghij";
    char s2[10] = "0123456789";
    
    for(int i = 0; i<20; i++){
        fprintf(fp1, "%c%c %c%c %c%c 19%c%c\n", s[rand()%10],s[rand()%10],s[rand()%10],s[rand()%10],s[rand()%10],s[rand()%10],s2[rand()%10],s2[rand()%10]);
    }
    */
    
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    char s1[100];
    
    while(fgets(s1, 50, fp1)){
        char s2[100];
        strncpy(s2, s1+strlen(s1)-5, strlen(s1));
        if(atoi(s2) > 1980)
            fprintf(fp2, "%s", s1);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
