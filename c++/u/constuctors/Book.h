#include <stdio.h>

class Book
{
    private:
        static const int std_length = 30;       // Стандартна довжина масиву чарів

        char * name;
        char * auth;
        int year;
        int price;

        void strcp(char * sorce, char * target)     //  Копіювання стрічки
        {
            for (int i = 0; i < std_length; i++)
                target[i] = sorce[i];
        }
    public:
        Book(char * _name, char * _auth, int _year, int _price)
        {
            name = new char[std_length];
            strcp(_name, name);
            auth = new char[std_length];
            strcp(_auth, auth);
            year = _year;
            price = _price;
            printf(" * Конструктор ерндндн *\n");
        }
        ~Book()
        {
            delete [] name;
            delete [] auth;
            printf(" * Деструктор пфф *\n");
        }

        void getBook()
        {
            printf("name\t%s\nauth\t%s\nyear\t%d\n$\t%d\n", name, auth, year, price);
        }
};
