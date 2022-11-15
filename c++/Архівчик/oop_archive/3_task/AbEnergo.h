#pragma once
#include <stdio.h>
#include "AbCom.h"

class AbEnergo: public AbCom
{
    private:
        float start,
              end;
    public:
        AbEnergo(char * _name, float _price, char * _adress,            // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt, float _start, float _end);
        AbEnergo(const AbEnergo &other);                                // конструктор копіювання
        ~AbEnergo();
        void getCost();
};