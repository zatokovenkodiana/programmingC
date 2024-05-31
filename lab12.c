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
_______________________________________________________

#include <stdio.h>
#include <time.h>
 
int main()
{   time_t now;
    struct tm * timeinfo;
    int year, m, i, j;
    char* month[] = { "January","February", "March","April", "May","June", 
            "July", "August","September","October", "November","December"};
    
    printf ("YEAR: "); scanf ("%d",&year);
    time (&now); 
    timeinfo = localtime (&now);
    timeinfo->tm_year = year-1900; 
    timeinfo->tm_mon = 0;
 
    m =-1;
while(m<12)
{   for(i=1; i<33; i++) 
    {   timeinfo->tm_mday = i;
        mktime (timeinfo);  
 
        if(timeinfo->tm_mon > m) 
        {   printf("\n                        %s\n",month[timeinfo->tm_mon]);
            printf("_______________________________\n");
            printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");
            printf("_______________________________\n");
            for(j=0;j<(timeinfo->tm_wday);j++)
                printf("    ");
            m++;
            break;
        }
        if (m==11 && timeinfo->tm_mon ==0) 
        {   m++;
            break;
        }
        
        printf("%4d",timeinfo->tm_mday); 
            
        if(timeinfo->tm_wday==6)
            printf("\n");
    }
}
    getchar();getchar();
    return 0;
}
_____________________________________________________________________________

#include <stdio.h>
#include <string.h>
#include <time.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int get_day_of_week(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int c = year / 100;
    year %= 100;
    int w = (day + 13*(month+1)/5 + year + year/4 + c/4 + 5*c) % 7;
    return (w + 5) % 7 + 1;
}

void print_calendar(int year, int month) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (is_leap_year(year)) {
        days_in_month[2] = 29;
    }

    printf("   %s %d", month_names[month], year);
    printf(" Su Mo Tu We Th Fr Sa");

    int day_of_week = get_day_of_week(year, month, 1);
    for (int i = 1; i < day_of_week; i++) {
        printf("   ");
    }

    for (int day = 1; day <= days_in_month[month]; day++) {
        printf("%3d", day);
        if ((day + day_of_week - 1) % 7 == 0 || day == days_in_month[month]) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_year = tm.tm_year + 1900;
    int current_month = tm.tm_mon + 1;
    int current_day = tm.tm_mday;
    int user_year, user_month, user_day;

    char date_input[11];
    printf("Enter the date (YYYY.MM.DD, YYYY.MM, YYYY, or 'now'): ");
    scanf("%s", date_input);

    if (strcmp(date_input, "now") == 0) {
        printf("%02d.%02d.%d ", current_day, current_month, current_year);
        switch (get_day_of_week(current_year, current_month, current_day)) {
            case 1:
                printf("Monday");
                break;
            case 2:
                printf("Tuesday");
                break;
            case 3:
                printf("Wednesday");
                break;
            case 4:
                printf("Thursday");
                break;
            case 5:
                printf("Friday");
                break;
            case 6:
                printf("Saturday");
                break;
            case 7:
                printf("Sunday");
                break;
        }
    } else {
        sscanf(date_input, "%d.%d.%d", &user_year, &user_month, &user_day);
        if (user_day > 0) {
            printf("%s %d, %d is a ", user_day, user_month, user_year);
            switch (get_day_of_week(user_year, user_month, user_day)) {
                case 1:
                    printf("Monday");
                    break;
                case 2:
                    printf("Tuesday");
                    break;
                case 3:
                    printf("Wednesday");
                    break;
                case 4:
                    printf("Thursday");
                    break;
                case 5:
                    printf("Friday");
                    break;
                case 6:
                    printf("Saturday");
                    break;
                case 7:
                    printf("Sunday");
                    break;
            }
        }
        if (user_month > 0) {
            print_calendar(user_year, user_month);
        }
        if (user_year > 0) {
            for (int month = 1; month <= 12; month++) {
                print_calendar(user_year, month);
            }
        }
    }

    return 0;
}
