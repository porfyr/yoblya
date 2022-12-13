#include <stdio.h>

static const int std_length = 30;   // Стандартна довжина масиву чарів

class Book
{
    private:
        char  * name;
        char  * auth;
        int     year;
        int     price;
        void strcp(char * target, char * sorce);    //  Кустарне копіювання стрічки

    public:
        Book(char * _name, char * _auth, int _year, int _price);    //  Конструктор ініціалізації
        Book(const Book &other);    //  Конструктор копіювання
        ~Book();                    //  Деструктор

        void getBook()              //  Друк об'єкта
        {
            printf("name\t%s\nauth\t%s\nyear\t%d\n$\t%d\n", name, auth, year, price);
        }
};



void Book::strcp(char * target, char * sorce)     //  Кустарне копіювання стрічки
        {
            for (int i = 0; i < std_length; i++)
                target[i] = sorce[i];
        }


Book::Book(char * _name, char * _auth, int _year, int _price)   //  Конструктор ініціалізації
    : name(new char[std_length]),
      auth(new char[std_length])
{
    strcp(name, _name);
    strcp(auth, _auth);
    year = _year;
    price = _price;

    printf("\n  * Конструктор ерндндн *\n    %p\n\n", this);
}


Book::Book(const Book &other)       //  Конструктор копіювання
{
    this->name = new char[std_length];\
    strcp(this->name, other.name);
    this->auth = new char[std_length];\
    strcp(this->auth, other.auth);
    this->year = other.year;
    this->price = other.price;

    printf("\n  * Копіювання фурр\n    %p\n", this);
}


Book::~Book()       //  Деструктор
{
    delete [] name;
    delete [] auth;
    printf("\n  * Деструктор пуфф *\n    %p\n", this);
}