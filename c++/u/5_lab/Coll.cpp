#include <stdio.h>
#include <fstream>
#include "Coll.h"

void Coll::read_obj(AbCom &obj, std::ifstream &fin)
{
    char * _name = new char[std_size]; fin >> _name;
    char * _service_name = new char[std_size]; fin >> _service_name;
    float _price; fin >> _price;
    char * _adress = new char[std_size]; fin >> _adress;
    int _regDate; fin >> _regDate;
    int _dateLastCheck; fin >> _dateLastCheck;
    int _size; fin >> _size;
    int * _dateCheck_list = new int[_size];
    for (int i = 0; i < _size; i++)
        fin >> _dateCheck_list[i];
    float _debt; fin >> _debt;
    AbCom temp(_name, _service_name, _price, _adress,
             _regDate, _dateLastCheck, _size, _dateCheck_list, _debt);
    obj = temp;
}

Coll::Coll(int _size, char *filename)
{
    printf("  * Конструктор Coll");
    size = _size;
    mas = new AbCom[size];
    std::ifstream fin;
    fin.open(filename);
    for (int i = 0; i < size; i++)
        read_obj(mas[i], fin);
    fin.close();
}
Coll::~Coll()
{
    printf("  * Деструктор Coll");
    delete[] mas;
}

void Coll::getMas()
{
    for (int i = 0; i < size; i++)
    {
        mas[i].getObj();
    }
}