#include "AbDrenazh.h"

AbDrenazh::AbDrenazh(char * _name, float _price, char * _adress,            // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt, float _vypyv)
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
    vypyv= _vypyv;
    printf("  * Конструктор AbDrenazh %p бррр\n", this);
}

AbDrenazh::AbDrenazh(const AbDrenazh &other)                                 // конструктор копіювання
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
    this->vypyv = other.vypyv;
    printf("  * Копіювання AbDrenazh %p вжух\n", this);
}

AbDrenazh::~AbDrenazh()
{
    printf("  * Деструктор AbDrenazh %p пфф\n", this);
}

void AbDrenazh::getVypyv()
{
    printf("%s випив на %f\n", AbCom::name, vypyv * taryf_vody );
}