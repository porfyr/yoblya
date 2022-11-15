#include <stdio.h>
#include "List.h"


int main()
{

    List lst;
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(10);
    lst.print();

    printf("%d\n", lst.getSize());
    lst.push_back(13);
    printf("%d\n", lst[1]);

    return 0;
}