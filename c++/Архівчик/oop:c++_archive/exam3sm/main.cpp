//#include <stdio.h>
#include <vector>
#include "Batko.h"
#include "Donka.h"


int main()
{
    Batko tur("info.txt");
    tur.print();
    Batko ruv("info.txt");
    ruv.print();

    Donka d("info.txt");
    d.setUmovy("хороші");
    d.hereVal(4);
    d.print();

    // Batko tur2(tur);
    // tur2.print();
    // tur2.hereVal(3);

    Batko fyr("info.txt");
    fyr.print();
    fyr += ruv;
    fyr.print();

    Donka dym;
    dym.print();
    dym += d;
    dym.print();

    std::vector<Batko> ls;
    ls.push_back(tur);
    ls.push_back(fyr);
    ls.push_back(d);

    printf("Друк об'єкта vector\n");
    ls[2].print();
    ls[2].print_inFile("out.txt");

    return 0;
}