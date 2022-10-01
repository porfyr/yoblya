#include <stdio.h>

class Book {
    private:
        char name[20];
        char author[20];
        int year;
        int cost;

        void strcp (char source[20], char target[20])
        {
            for (int i = 0; i < 20; i++)
                target[i] = source[i];
        }

    public:
        Book(char _name[20], char _author[20], int _year, int _cost)
        {
            strcp(_name, name);
            strcp(_author, author);
            year = _year;
            cost = _cost;
        }

        void getBook()
        {
            printf("%s - %s %d року, %d гривнів\n", name, author, year, cost);
        }
};