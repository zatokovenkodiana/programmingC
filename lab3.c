#include <stdio.h>
#include <ctype.h>
 
int main()
{ 
     char masstr[80]="";
       char *rstr;
       char *gets (char *s);
   printf ("Введите строку:\n");
   rstr = gets (masstr);
   int i = 0;
    for ?????????????????
    {
        if (masstr[i] == "a")
            masstr[i] = "A";
        else if (masstr[i] == "b")
            masstr[i] = "B";
        i++;
    }
    
   printf ("Считана строка:\n%s\n", masstr);
 
    return 0;
}
