#include <stdio.h>
#include "List.h"


int main()              // Двозв'язний список 8 лабка
{
    List ls("arr.txt");
    ls.print();
    ls.push_back(4);
    ls.push_head(7);
    ls.push_back(14);
    ls.push_head(-7);
    ls.print();
    ls.printSize();

    ls.rm_negatives();
    ls.print();
    ls.mv_min();
    ls.print();

    return 0;
}