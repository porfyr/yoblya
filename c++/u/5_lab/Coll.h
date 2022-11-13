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
    public:
        Coll(int _size, char *filename);
        ~Coll();

        void getMas();
};