#include <stdio.h>
#include "Auto.h"

int main()
{

    Auto car1 = Auto("cars.txt");
    Auto car2 = Auto("cars.txt");
    Auto car3 = Auto("cars.txt");
    Auto car4 = car3;
    //car1.getAuto();
    //car2.getAuto();
    car1.getAuto();
    car2.getAuto();
    car3.getAuto();
    car4.getCount();
    printf("car1 + (car3 + car5) = %d\n", car1 + (car3 + car4));
    Auto car5 = Auto("Камаз", 10.8, 46000);
    car5 += car3 + car5;
    car5.getAuto();
    printf("car3 %s як car4\n", car3 == car4 ? "зветься" : "не зветься");
    printf("Привів %f\n", (float) car3);

    return 0;
}