#include <stdio.h>
#include "AbCom.h"
#include "AbEnergo.h"
//#include "AbDrenazh.h"

int main()
{
    int arr[3] = {1, 30, 150};          // Створення масиву перевірок
    //AbCom Paraskeviy = AbCom("Параскевій Пархолур", 8.2, "Zenyka Zloho 18", 1, 150, 3, arr, 0.0);
    AbEnergo Lavrentiy = AbEnergo("Лаврентій Імнадзе", 8.2, "Papycha 7", 1, 150, 3, arr, 50.3, 4.1, 5.6);
    //Paraskeviy.getObj();
    Lavrentiy.getObj();
    //Lavrentiy.getPrice();
    //Lavrentiy.get_isLate();
    //Lavrentiy.getNextCh();
    
    //AbDrenazh Prokop = AbDrenazh("Прокоп Стахій", 8.2, "Poderevyanskoho 14", 1, 150, 3, arr, 30.0, 4);
    //Prokop.getObj();
    //Prokop.getVypyv();


    return 0;
}
