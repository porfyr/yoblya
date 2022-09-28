#include "Book.h"
#include <stdio.h>

class Book_whose : publik Book
{
    private:
        char owner[std_length];
    public:
        Book_whose(char * _owner)
            : owner(new char[std_length])
};