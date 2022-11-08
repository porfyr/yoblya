#include <stdio.h>
#include "Book.h"

int main()
{
    Book lystok = Book("Євтимій вухоляп", "Василь Колісник", 45, 70);
    lystok.getBook();

    Book papirus(lystok);
    papirus.getBook();

    return 0;
}