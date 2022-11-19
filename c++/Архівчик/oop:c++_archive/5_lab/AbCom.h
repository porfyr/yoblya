#pragma once
#include <stdio.h>
#include <cstdlib>

const int std_size = 50; 

/*
    Клас описує користувача комунальних послуг
*/

class AbCom
{
    protected:
        char * name;            // Ім'я користувача комун. послуг
        char * service_name;    // Назва сервісу
        float price;            // Ціна за кубометр
        char * adress;          // Адреса
        int regDate;            // Дата реєстрації
        int dateLastCheck;      // Дата останньої провірки
        int size;               // Розмір масиву
        int * dateCheck_list;   // Лист дат перевірок
        float debt;             // Борг користувача комун. послуг

        void strcp(char * target, char * sorce);     //  Кустарне копіювання стрічки
    public:
        AbCom();
        AbCom(char * _name, char * _service_name, float _price, char * _adress,             // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt);
        AbCom(const AbCom &other);                                                          // конструктор копіювання
        AbCom &operator= (const AbCom &other);                                       // Оператор присвоєння
        ~AbCom();

        char* getName();
        char* getServce();
        float getDebt();
        void swap(AbCom &other);

        void getObj();
        void getPrice();
        void get_isLate();
        void getNextCh();
};