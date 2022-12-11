#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "AbCom.h"

void read_obj(AbCom &obj, std::ifstream &fin);

int main()              // 9 лабка
{
    int size = 4;
    std::vector<AbCom> container;
    AbCom temp;
    for (int i = 0; i < size; i++)
    {
        std::ifstream fin("hromada.txt");
        read_obj(temp, fin);
        container.push_back(temp);
    }
    for (int i = 0; i < size; i++)
        container[i].getObj();
    

    return 0;
}


void read_obj(AbCom &obj, std::ifstream &fin)
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