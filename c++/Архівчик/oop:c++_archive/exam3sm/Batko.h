#pragma once
//#include <stdio.h>
#include <string>
#include <fstream>
#include "Abst.h"

int cur_code = 0;
int have_read = 0;

class Batko: public Abst
{
    protected:
        std::string name;
        int code;
        int * time;         // [0] Година початку, [1] година кінця
        std::string place;  // Місце проведення
    public:
        Batko();                    // Дефолтний к-тор
        Batko(char* filename);          // К-тор з файлу
        Batko(char *name, int t0, int t1, char *place);     // Класичний к-тор
        Batko (const Batko &other);         // К-тор копіювання
        ~Batko() { delete[] time; printf("  * Batko %s припинив існування\n", name.c_str()); }
        void operator+=(const Batko &other);

        // Сетери гетери
        void setName(char *name) { this->name = name; }
        void setTime(int t0, int t1) { this->time[0] = t0; this->time[1] = t1; }
        void setPlace(char *place) { this->place = place; }
        std::string getName() { return name; }
        int *getTime() {return time; }
        std::string getPlace() { return place; }

        virtual void print() override;          // Друк об'єкта у консоль
        void print_inFile(char * filename);     // у файл

        void hereVal(int val) { printf(" * Прийом параметра int у перекритий метод класу Batko\n"); }
        // ^ Перекритий метод
};

Batko::Batko()
    : time(new int[2])
{
    name = "noname";
    code = cur_code;
    time[0] = 0; time[1] = 0;
    place = "no_place";
}

Batko::Batko(char* filename)        // К-тор зчитування об'єкта з першої стрічки файла
    : time(new int[2])
{
    std::ifstream fin(filename);
    for (int i = 0; i <= have_read; i++)
    {
        code = cur_code;
        fin >> name;
        fin >> time[0]; fin >> time[1];
        fin >> place;
    }
    fin.close();
    ++ have_read;
    ++ cur_code;
}

Batko::Batko(char *name, int t0, int t1, char *place)
{
    this->time = new int[2];
    this->name = name, this->code = code, this->time[0] = t0, this->time[1] = t1, this->place = place; // :)
    ++ cur_code;
}

Batko::Batko (const Batko &other)       // К-тор копіювання
{
    this->name = other.name;
    this->code = cur_code;
    this->time = new int[2];
    this->time[0] = other.time[0];
    this->time[1] = other.time[1];
    this->place = other.place;
    ++ cur_code;
}

void Batko::operator+=(const Batko &other)
{
    if (this->name == "noname")
    {
        name = other.name;
        time[0] = other.time[0], time[1] = other.time[1];
        place = other.place;
        //pohoda = rand()%2 == 0 ? this->pohoda : other.pohoda;
    } else
    {
        name += ('-' + other.name);
        time[1] = other.time[1];
        place += ("_&_" + other.place);
    }
}

void Batko::print()                         // Друк об'єкта у консоль
{
    printf("[Batko]%s [код %d] відбудеться з %d по %d годину у %s\n", name.c_str(), code, time[0], time[1], place.c_str());
}

void Batko::print_inFile(char * filename)   // Друк об'єкта у файл
{
    std::ofstream fout(filename);
    fout << name.c_str() << '[код ' << code << "] відбудеться з " << time[0] << " по " << time[1] << " годин\n";
    fout.close();
}