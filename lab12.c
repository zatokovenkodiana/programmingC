Написать программу-календарь. Пользователь может указать даты в формате: 
- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате; 
- гггг.мм – программа выводит 
календарь за данный месяц; 
- гггг – календарь за год; 
- now – текущую дату. 

  
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int year, month, day;
    char input[10];

printf("Укажите дату (yyyy.mm.dd, yyyy.mm, yyyy, now): ");
scanf("%s", input);

if (strcmp(input, "now") == 0) {
    printf("Сейчас: %d.%02d.%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
} else if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3) {
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    mktime(&tm);
    printf("День недели %d.%02d.%02d is ", year, month, day);
} else if (sscanf(input, "%d.%d", &year, &month) == 2) {
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = 1;
    mktime(&tm);
    printf("Календарь года %d.%02d:\n", year, month);
} else if (sscanf(input, "%d", &year) == 1) {
    printf("Календарь года %d:\n", year);
} else {
    printf("Ошибка\n");
    return -1;
}

printf("Год: %d\n", tm.tm_year + 1900);
printf("Месяц: %02d\n", tm.tm_mon + 1);
printf("День: %02d\n", tm.tm_mday);
printf("День недели: %d\n", tm.tm_wday);

return 0;
}
