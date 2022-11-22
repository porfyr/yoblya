#pragma once
#include "Student.h"
#include <string>

template <typename T>
class Bachelor: public Student<T>
{
    private:
        T ratingOfWork;
    public:
        Bachelor() { printf("Конструктор Bachelor\n"); }
        ~Bachelor() { printf("Деструктор Bachelor\n"); }
        Bachelor(int, std::string, T);
        T getRatingOfWork();
};

template<typename T>
Bachelor<T>::Bachelor(int number, std::string name, T ratingOfWork)
    //:Student<T>(number,name)
{
    this->ratingOfWork = ratingOfWork;
    this->number = number;
    this->name = name;
}

template<typename T>
T Bachelor<T>::getRatingOfWork()
{
    return ratingOfWork;
}