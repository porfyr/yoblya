#include <stdio.h>
#include <fstream>
#include "Coll.h"

void Coll::read_obj(AbCom &obj, std::ifstream &fin)
{
    char * _name = new char[std_size]; fin >> _name;
    char * _service_name = new char[std_size]; fin >> _service_name;
    float _price; fin >> _price;
    char * _adress = new char[std_size]; fin >> _adress;
    int _regDate; fin >> _regDate;
    int _dateLastCheck; fin >> _dateLastCheck;
    int _size; fin >> _size;
    int * _dateCheck_list = new int[_size];
    for (int i = 0; i < _size; i++)
        fin >> _dateCheck_list[i];
    float _debt; fin >> _debt;
    AbCom temp(_name, _service_name, _price, _adress,
             _regDate, _dateLastCheck, _size, _dateCheck_list, _debt);
    obj = temp;
}
void Coll::quicksort(AbCom * res, int fst, int lst, int ornl_size)    // Алгоритм швидкого сортування
{
    if (fst < lst) {
        int l = fst, r = lst;
        float midd = res[ (l+r)/2 ].getDebt();
        while (l < r) {
            while (res[l].getDebt() < midd)
                l++;
            while (res[r].getDebt() > midd)
                r--;
            if (l <= r) {
                res[l].swap(res[r]);
                l++; r--;
            }
        }
        quicksort (res, fst, r, 0);
        quicksort (res, l, lst, 0);
    }
}

Coll::Coll(int _size, char *filename)
{
    printf("  * Конструктор Coll\n");
    size = _size;
    mas = new AbCom[10];
    std::ifstream fin;
    fin.open(filename);
    for (int i = 0; i < size; i++)
        read_obj(mas[i], fin);
    fin.close();
}
Coll::~Coll()
{
    printf("  * Деструктор Coll\n");
    delete[] mas;
}


void Coll::getMas()
{
    for (int i = 0; i < size; i++)
    {
        printf("індекс %d", i);
        mas[i].getObj();
    }
}
void Coll::getNames()
{
    for (int i = 0; i < size; i++)
        printf("%s   \t%f\n", mas[i].getName(), mas[i].getDebt());
}
void Coll::sortMas()
{
    quicksort(mas, 0, size-1, size);
}
void Coll::addAb()
{
    printf("Введи одною стрічкою абонента у форматі \"hromada.txt\"\n");
    size ++;
    char _name[50]; scanf("%s", &_name);
    char _service_name[50]; scanf("%s", &_service_name);
    float _price; scanf("%f", &_price);
    char _adress[50]; scanf("%s", &_adress);
    int _regDate; scanf("%d", &_regDate);
    int _dateLastCheck; scanf("%d", &_dateLastCheck);
    int _size; scanf("%d", &_size);
    int * _dateCheck_list = new int[_size];
    for (int i = 0; i < _size; i++)
        scanf("%d", &_dateCheck_list[i]);
    float _debt; scanf("%f", &_debt);
    
    AbCom temp(_name, _service_name, _price, _adress,
             _regDate, _dateLastCheck, _size, _dateCheck_list, _debt);
    printf("Створено temp\n");
    mas[size-1] = temp;
}
void Coll::rmAb()
{
    int inx;
    printf("Введи індекс абонента, якого потрібно позбавити сервісу\n-> ");
    scanf("%d", &inx);
    for (int i = inx; i < size-2; i++)
        mas[i] = mas[i+1];
    size --;
}