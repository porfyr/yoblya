#include "AbEnergo.h"

AbEnergo::AbEnergo(char * _name, float _price, char * _adress,            // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt, float _start, float _end)
{
    name = new char[std_size];
    strcp(name, _name);
    price = _price;
    adress = new char[std_size];
    strcp(adress, _adress);
    regDate = _regDate;
    dateLastCheck = _dateLastCheck;
    size = _size;
    dateCheck_list = new int[size];
    for (int i = 0; i < size; i++)
        dateCheck_list[i] = _dateCheck_list[i];
    debt = _debt;
    start = _start;
    end = _end;
    printf("  * Конструктор AbEnergo %p бррр\n", this);
}

AbEnergo::AbEnergo(const AbEnergo &other)                                 // конструктор копіювання
{
    this->name = new char[std_size];
    strcp(this->name, AbCom::name);
    this->adress = new char[std_size];
    strcp(this->adress, AbCom::adress);
    this->dateCheck_list = new int[std_size];
    this->price = AbCom::price;
    this->regDate = AbCom::regDate;
    this->dateLastCheck = AbCom::dateLastCheck;
    this->debt = AbCom::debt;
    this->start = other.start;
    this->end = other.end;
    printf("  * Копіювання AbEnergo %p вжух\n", this);
}

AbEnergo::~AbEnergo()
{
    printf("  * Деструктор AbEnergo %p пфф\n", this);
}

void AbEnergo::getCost()
{
    printf("%s просвітив на %f\n", AbCom::name , (end - start)*4.2 );
}