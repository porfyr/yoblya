#include <stdio.h>
#include "Coll.h"

static void read_obj(AbCom &obj);

int main()
{
    Coll arr(5, "hromada.txt"); // Вводиться розмір масиву і файл зчитування
    arr.getMas();               // Друк всього масиву екземплярів
    arr.sortMas();              // Сортування масиву за величиною боргу
    printf("\nРезультат сортування за боргом:\n");
    arr.getNames();             // Поіменний друк масиву для перегляду посортованого
    arr.addAb();              // Додавання абонента
    //arr.rmAb();                 // Видалення абонента
    arr.getMas();


    return 0;
}

/*
    У роботі відсутні меню, нарахування сумарних виплат(через нерозуміння),
    визначення абонентів, що у цей місяць повинні провести перевірку приладів обліку (також),
    виведення користувачів однакових видів послуг, бо видалось надто складним для мене
    і слайсова/векторна система збільшення масиву
*/