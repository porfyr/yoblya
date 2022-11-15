#pragma once
#include <stdio.h>
#include <cstdlib>

const int std_size = 50; 

class AbCom
{
    protected:
        char * name;
        float price;
        char * adress;
        int regDate;
        int dateLastCheck;
        int size;
        int * dateCheck_list;
        float debt;

        void strcp(char * target, char * sorce);     //  Кустарне копіювання стрічки
    public:
        AbCom();
        AbCom(char * _name, float _price, char * _adress,                                   // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt);
        AbCom(const AbCom &other);                                                          // конструктор копіювання
        ~AbCom();

        void getObj();
        void getPrice();
        void get_isLate();
        void getNextCh();
};