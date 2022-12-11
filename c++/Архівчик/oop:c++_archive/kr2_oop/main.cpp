#include <stdio.h>
#include "Parallelepiped.h"
#include "Cylinder.h"
#include "Konus.h"

int main()
{

    Parallelepiped par(3, 3, 5);
    printf(" -- Об'єм паралелепіпеда %f\n", par.getVolume());
    Cylinder cyl(10, 4);
    printf(" -- Об'єм циліндра %f\n", cyl.getVolume());
    Konus ko(7, 4);
    printf(" -- Об'єм конуса %f\n", ko.getVolume());

    return 0;
}