#pragma once
#include <stdio.h>
#include <fstream>
#include "AbCom.h"

class Coll
{
    private:
        int size;
        AbCom * mas;
        static void read_obj(AbCom &obj, std::ifstream &fin);
        void quicksort(AbCom * res, int fst, int lst, int ornl_size);
    public:
        Coll(int _size, char *filename);
        ~Coll();

        void getMas();
        void getNames();
        void sortMas();
        void addAb();
        void rmAb();
};