#include <stdio.h>
#include "Figura.h"

class Konus: private Figura
{
    private:
        int height, radius;
    public:
        Konus(int hight, int radius);
        ~Konus() { printf("Деструктор Konus"); }
        virtual float getVolume() override;
};


Konus::Konus(int height, int radius)
{
    this->height = height;
    this->radius = radius;
    printf("Констркутор Konus дррндндн\n");
}

float Konus::getVolume()
{
    return float(radius * radius * height) * 3.14 / 3;
}