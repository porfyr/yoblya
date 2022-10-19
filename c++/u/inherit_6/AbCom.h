#include <stdio.h>
#include <string>

const int std_size = 30; 

class AbCom
{
    protected:
        char * name;
        float price;
        char * adress;
        int regDate;
        int dateLastCheck;
        int size;
        int * dateCheck_list;
        float debt;

        void strcp(char * target, char * sorce)     //  Кустарне копіювання стрічки
        {
            for (int i = 0; i < std_size; i++)
                target[i] = sorce[i];
        }
    public:
        AbCom()
        {
            printf("  * Конструктор AbCom %p бррр\n", this);
        }
        AbCom(char * _name, float _price, char * _adress,                                   // конструктор ініціалізації
              int _regDate, int _dateLastCheck, int _size, int * _dateCheck_list, float _debt) :
        name(new char[std_size]),
        adress(new char[std_size])
        {
            strcp(name, _name);
            price = _price;
            strcp(adress, _adress);
            regDate = _regDate;
            dateLastCheck = _dateLastCheck;
            size = _size;
            dateCheck_list = new int[size];
            for (int i = 0; i < size; i++)
                dateCheck_list[i] = _dateCheck_list[i];
            debt = _debt;
            printf("  * Конструктор AbCom %p бррр\n", this);
        }
        AbCom(const AbCom &other)                                                           // конструктор копіювання
        {
            this->name = new char[std_size];
            strcp(this->name, other.name);
            this->adress = new char[std_size];
            strcp(this->adress, other.adress);
            this->dateCheck_list = new int[std_size];
            this->price = other.price;
            this->regDate = other.regDate;
            this->dateLastCheck = other.dateLastCheck;
            this->debt = other.debt;
            printf("  * Копіювання AbCom %p вжух\n", this);
        }
        ~AbCom()
        {
            delete[] name;
            delete[] adress;
            delete[] dateCheck_list;
            printf("  * Деструктор AbCom %p пфф\n", this);
        }

        void getObj()
        {
            printf("\n%s\n%f за кубометр\n%s\n%d зареєструвався\n%d остання дата\n", name, price, adress, regDate, dateLastCheck);
            for (int i = 0; i < size; i++) {
                printf("%d ", dateCheck_list[i]);
            }
            printf("\nБорг %f\n\n", debt);
        }
        void getPrice()
        {
            if (dateCheck_list[size-1] - dateCheck_list[size-2] < 1096)
                printf("Ціна за кубометр %f\n", price);
            else
                printf("Ціна за кубометр %f\n", price*3);
        }
        void get_isLate()
        {
            if (dateCheck_list[size-1] - dateCheck_list[size-2] < 1096)
                printf("Термін дотриманий\n");
            else
                printf("Термін не дотриманий\n");
        }
        void getNextCh()
        {
            printf("Наступна перевірка %d дня\n", dateCheck_list[size-1] + rand()%50);
        }
};