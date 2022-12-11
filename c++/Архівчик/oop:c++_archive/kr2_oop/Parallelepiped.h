#include <stdio.h>
#include "Figura.h"

class Parallelepiped: public Figura
{
    private:
        int lengh, width, height;
    public:
        Parallelepiped(int lengh, int width, int height);                // Конструктор
        ~Parallelepiped() { printf("Деструктор Paralelepiped\n"); }
        virtual float getVolume() override;                               // Віртуальна дайОб'єм
};


Parallelepiped::Parallelepiped(int lengh, int width, int height)
{
    this->lengh  = lengh;
    this->width  = width;
    this->height = height;
    printf("Конструктор Paralelepiped ерндндн\n");
}

float Parallelepiped::getVolume()
{
    return float(lengh * width * height);
}