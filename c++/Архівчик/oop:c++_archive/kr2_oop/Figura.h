#pragma once
#include <stdio.h>

//const size_t std_size = 10;

class Figura
{
    public:
        Figura() { /*printf("Конструктор Figura\n");*/ }    // Дефолтний конструктор Figura
        ~Figura() { /*printf("Деструктор Figura\n");*/ }
        virtual float getVolume() = 0;                    // Абстрактний метод
};