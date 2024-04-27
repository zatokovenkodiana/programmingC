Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов типа humen. 
  Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения. Вывести результат. 

 #include <stdio.h>
#include <math.h>
#include <string.h>
 
 struct humen{
    char name[100], sname[100];
    int byear;
};

int main(){

    int N = 4;
    struct humen a[N], b[N], t;
    char name[100], sname[100];
    int byear;
    for(int i = 0; i<N; i++){
        printf("введите имя %d-го человека: ", i+1);
        scanf("%s", name);
        printf("введите фамилию %d-го человека: ", i+1);
        scanf("%s", sname);
        printf("введите год рождения %d-го человека: ", i+1);
        scanf("%d", &byear);
        strcpy(a[i].name, name);
        strcpy(a[i].sname, sname);
        a[i].byear = byear;
    }
    
    for(int i = 0; i<N; i++) b[i] = a[i];
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<N-i-1; j++){
            if(b[j].byear < b[j+1].byear){
                t = b[j+1];
                b[j+1] = b[j];
                b[j] = t;
            }
        }
    }
    for(int i = 0; i<N; i++){
        printf("%d %s %s %d\n", i, b[i].name, b[i].sname, b[i].byear);
    }
    return 0;
}
