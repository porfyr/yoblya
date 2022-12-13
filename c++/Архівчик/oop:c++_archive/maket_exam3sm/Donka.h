#include "Batko.h"

class Donka: public Batko
{
    private:
        std::string pohoda = "не спрогнозовано";
    public:
        Donka() {}                  // Дефолтний к-тор
        Donka(char * filename);         // К-тор зчитування з файлу
        Donka(char *name, int t0, int t1, char *place, char *pohoda);   // К-тор класичний
        Donka (const Donka &other);     // К-тор копіювання
        ~Donka() { printf("Donka %s припинила своє існування\n", name.c_str()); }

        void setPohoda(char * pohoda) { this->pohoda = pohoda; }

        virtual void print() override;      // Друк об'єкта в консоль
        void hereVal(float val) { printf("Прийом параметра float\n"); }
};

Donka::Donka(char * filename)
{
    std::ifstream fin(filename);
    fin >> code;
    fin >> name;
    time = new int[2];
    fin >> time[0]; fin >> time[1];
    fin >> place;
    fin.close();
    ++ cur_code;
}

Donka::Donka(char *name, int t0, int t1, char *place, char *pohoda)
{
    this->time = new int[2];
    this->name = name;
    this->code = code;
    this->time[0] = t0, this->time[1] = t1;
    this->place = place;
    this->pohoda = pohoda;
    ++ cur_code;
}

Donka::Donka (const Donka &other)       // К-тор копіювання
{
    this->name = other.name;
    this->code = cur_code;
    this->time = new int[2];
    this->time[0] = other.time[0];
    this->time[1] = other.time[1];
    this->place = other.place;
    this->pohoda = other.pohoda;
    ++ cur_code;
}

void Donka::print()                         // Друк об'єкта у консоль
{
    printf("%s [код %d] відбудеться з %d по %d годину у %s\nпогода очікується %s\n",
        name.c_str(), code, time[0], time[1], place.c_str(), pohoda.c_str());
}