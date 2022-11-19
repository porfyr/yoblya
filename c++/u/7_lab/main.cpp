#include <stdio.h>
#include "List.h"


int main()
{

    List lst("arr.txt");
    lst.print();
    // lst.rm_negatives();          // Усуває всі від'ємні елементи
    lst.mv_min();
    lst.print();
    // lst.push_head(1);            // Додає з кінця новий елемент
    // lst.push_head(0);
    // lst.print();
    // lst.push_back(32);
    // lst.print();
    // lst.rm_head();
    // lst.print();
    // lst.rm_back();
    // lst.print();

    printf("Розмір листа %d\n", lst.getSize());
    //lst.push_back(13);
    //printf("Берем елемент по індексу %d\n", lst[3]);

    return 0;
}