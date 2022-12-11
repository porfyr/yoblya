#include <stdio.h>
#include "Figura.h"

class Cylinder: public Figura
{
    private:
        int height, radius;
    public:
        Cylinder(int height, int radius);
        ~Cylinder() { printf("Деструктор Cylinder\n"); }
        virtual float getVolume() override;
};

Cylinder::Cylinder(int height, int radius)
{
    this->height = height;
    this->radius = radius;
    printf("Конструктор Cylinder ррннн\n");
}

float Cylinder::getVolume()
{
    return (float)this->height * (float)this->radius * 3.14;
}