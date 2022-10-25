#include <stdio.h>
#include <fstream>

const int std_len = 20;
static int count = 0;

class Auto
{
    private:
        char * name;
        float en_vol;
        int mileage;
        void strcp(char * target, char * source)            // Копіювання стрички
        {
            for (int i = 0; i < std_len; i++)
                target[i] = source[i];
        }
        bool isCharEq(char * c1, char * c2)
        {
            bool res = true;
            for (int i = 0; i < 30; i++)
            {
                if (c1[i] != c2[i])
                {
                    res = false;
                    break;
                }
            }
            return res;
        }
    public:
        Auto()                                              // Дефолтний конструктор
        {
            printf("  * Дефолтний конструктор %p\n", this);
        }
        Auto(char * _name, float _en_vol, int _mileage):    // Ініціалізація класичним конструктором
            name(new char[std_len]),
            en_vol(_en_vol),
            mileage(_mileage)
        {
            strcp(name, _name);
            count ++;
            printf("  * Ініціалізація класична %p\n", this);
        }
        Auto(char * filename):                              // Конструктор з файлу
            name(new char[std_len])
        {
            static std::ifstream fin(filename);
            fin >> name;
            fin >> en_vol;
            fin >> mileage;
            count ++;
            printf("  * Ініціалізація з файлу %p\n", this);
        }
        Auto(const Auto &other)                             // Конструктор копіювання
        {
            this->name = new char[std_len];
            strcp(this->name, other.name);
            this->en_vol = other.en_vol;
            this->mileage = other.mileage;
            count ++;
            printf("  * Копіювання %p<-%p\n", this, &other);
        }
        int &operator+ (const Auto &other)                  // Оператор + об'єкт
        {
            int res_mileage = this->mileage + other.mileage;
            return res_mileage;
        }
        int &operator+ (int x)                              // Оператор + int
        {
            int res_mileage = this->mileage + x;
            return res_mileage;
        }
        Auto &operator= (const Auto &other)                 // Оператор присвоєнння
        {
            if (this == &other)
                return *this;
            else {
                delete[] name;
                en_vol = other.en_vol;
                mileage = other.mileage;
                name = new char[std_len];
                strcp(name, other.name);
                return *this;
            }
        }
        Auto &operator+= (int x)
        {
            this->mileage += x;
            return *this;
        }
        bool &operator== (const Auto &other)
        {
            bool res = isCharEq(this->name, other.name) ? true : false;
            return res;
        }
        operator float()
        {
            return this->en_vol;
        }

        ~Auto()                                             // Деструктор
        {
            delete[] name;
            printf("  * Деструктор %p\n", this);
        }

        void getAuto()
        {
            printf("%s\nоб'єм:\t%f\nпробіг:\t%d\n", name, en_vol, mileage);
        }
        void getCount()
        {
            printf("В нас %d екземплярів\n", count);
        }
};