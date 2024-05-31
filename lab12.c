Написать программу-календарь. Пользователь может указать даты в формате: 
- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате; 
- гггг.мм – программа выводит 
календарь за данный месяц; 
- гггг – календарь за год; 
- now – текущую дату. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getDayOfWeek(int year, int month, int day) {
    struct tm timeStruct = {0};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    mktime(&timeStruct);
    return timeStruct.tm_wday;
}

int getNumDaysInMonth(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        return 29;
    }
    return daysInMonth[month - 1];
}

void printCalendar(int year, int month) {
    int numDays = getNumDaysInMonth(year, month);
    int startDay = getDayOfWeek(year, month, 1);

    char *monthNames[] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};

    printf("\n%s %d\n", monthNames[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int day = 1;
    for (int i = 0; i < startDay; i++) {
        printf("    ");
    }
    for (int i = startDay; i < 7; i++) {
        printf("%3d ", day);
        day++;
    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (day <= numDays) {
                printf("%3d ", day);
                day++;
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[10];
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    int currentYear = current_time->tm_year + 1900;
    int currentMonth = current_time->tm_mon + 1;
    int currentDay = current_time->tm_mday;

    printf("Enter a date in the format 'yyyy.mm.dd', 'yyyy.mm', 'yyyy' or 'now': ");
    scanf("%s", input);

    if (strcmp(input, "now") == 0) {
        printf("%02d.%02d.%02d ", currentDay, currentMonth, currentYear);
        switch (current_time->tm_wday) {
            case 0:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
        }
    } else {
        int year, month, day;
        sscanf(input, "%d.%d.%d", &year, &month, &day);

        if (day != 0) {
            int dayOfWeek = getDayOfWeek(year, month, day);
            printf("The day of the week for %02d.%02d.%02d is ", day, month, year);
            switch (dayOfWeek) {
                case 0:
                    printf("Sunday\n");
                    break;
                case 1:
                    printf("Monday\n");
                    break;
                case 2:
                    printf("Tuesday\n");
                    break;
                case 3:
                    printf("Wednesday\n");
                    break;
                case 4:
                    printf("Thursday\n");
                    break;
                case 5:
                    printf("Friday\n");
                    break;
                case 6:
                    printf("Saturday\n");
                    break;
            }
        } else if (month != 0) {
            printCalendar(year, month);
        } else {
            for (int i = 1; i <= 12; i++) {
                printCalendar(year, i);
            }
        }
    }

    return 0;
}
