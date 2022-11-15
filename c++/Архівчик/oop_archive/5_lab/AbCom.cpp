//#pragma once
#include <fstream>
#include "AbCom.h"

void AbCom::strcp(char * target, char * sorce)        //  Кустарне копіювання стрічки
{
    for (int i = 0; i < std_size; i++)
        target[i] = sorce[i];
}
void AbCom::swap(AbCom &other)
{
    std::swap(this->name, other.name);
    std::swap(this->service_name, other.service_name);
    std::swap(this->price, other.price);
    std::swap(this->adress, other.adress);
    std::swap(this->regDate, other.regDate);
    std::swap(this->dateLastCheck, other.dateLastCheck);
    std::swap(this->size, other.size);
    std::swap(this->dateCheck_list, other.dateCheck_list);
    // for (int i = 0; i < this->size; i++)
    //     std:swap(this->dateCheck_list[i], other.dateCheck_list[i]);
    std::swap(this->debt, other.debt);
}

AbCom::AbCom()
{
    printf("  * дефолтний конструктор AbCom %p бррр\n", this);
}
AbCom::AbCom(char * _name, char * _service_name, float _price, char * _adress,             // конструктор ініціалізації
      int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt)
{
    name = new char[std_size];
    strcp(name, _name);
    service_name = new char[std_size];
    strcp(service_name, _service_name);
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
    printf("  * Конструктор AbCom %p бррр\n", this);
}
AbCom::AbCom(const AbCom &other)                                                           // конструктор копіювання
{
    this->name = new char[std_size];
    strcp(this->name, other.name);
    this->service_name = new char[std_size];
    strcp(this->service_name, other.service_name);
    this->adress = new char[std_size];
    strcp(this->adress, other.adress);
    this->dateCheck_list = new int[std_size];
    this->price = other.price;
    this->regDate = other.regDate;
    this->dateLastCheck = other.dateLastCheck;
    this->debt = other.debt;
    printf("  * Копіювання AbCom %p вжух\n", this);
}
AbCom &AbCom::operator= (const AbCom &other)                //  Присвоєння
{
    if (this != &other)
    {
        delete[] name;
        name = new char[std_size];
        strcp(name, other.name);
        delete[] service_name;
        service_name = new char[std_size];
        strcp(service_name, other.service_name);
        price = other.price;
        delete[] adress;
        adress = new char[std_size];
        strcp(adress, other.adress);
        regDate = other.regDate;
        dateLastCheck = other.dateLastCheck;
        size = other.size;
        delete[] dateCheck_list;
        dateCheck_list = new int[size];
        for (int i = 0; i < size; i++)
            dateCheck_list[i] = other.dateCheck_list[i];
        debt = other.debt;
    }
    return *this;
}
AbCom::~AbCom()
{
    delete[] name;
    delete[] service_name;
    delete[] adress;
    delete[] dateCheck_list;
    printf("  * Деструктор AbCom %p пфф\n", this);
}

char* AbCom::getName()
{
    return name;
}
char* AbCom::getServce()
{
    return service_name;
}
float AbCom::getDebt()
{
    return debt;
}

void AbCom::getObj()
{
    printf("\n%s користується %s\n%f за кубометр\n%s\n%d зареєструвався\n%d остання дата\n%d дати: ", name, service_name, price, adress, regDate, dateLastCheck, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", dateCheck_list[i]);
    }
    printf("\nБорг %f\n\n", debt);
}
void AbCom::getPrice()
{
    if (dateCheck_list[size-1] - dateCheck_list[size-2] < 1096)
        printf("Ціна за кубометр %f\n", price);
    else
        printf("Ціна за кубометр %f\n", price*3);
}
void AbCom::get_isLate()
{
    if (dateCheck_list[size-1] - dateCheck_list[size-2] < 1096)
        printf("Термін дотриманий\n");
    else
        printf("Термін не дотриманий\n");
}
void AbCom::getNextCh()
{
    printf("Наступна перевірка %d дня\n", dateCheck_list[size-1] + rand()%50);
}