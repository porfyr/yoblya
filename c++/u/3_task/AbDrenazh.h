#include <stdio.h>
#include "AbCom.h"

const float taryf_vody = 48.5;

class AbDrenazh: public AbCom
{
    private:
        float vypyv;
    public:
        AbDrenazh(char * _name, float _price, char * _adress,            // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt, float _vypyv);
        AbDrenazh(const AbDrenazh &other);                                // конструктор копіювання
        ~AbDrenazh();
        void getVypyv();
};