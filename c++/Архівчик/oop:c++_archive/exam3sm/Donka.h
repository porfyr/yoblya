#include "Batko.h"

class Donka: public Batko
{
    private:
        std::string umovy = "не спрогнозовано";
    public:
        Donka();                // Дефолтний к-тор
        Donka(char * filename);         // К-тор зчитування з файлу
        Donka(char *name, int t0, int t1, char *place, char *umovy);   // К-тор класичний
        Donka (const Donka &other);     // К-тор копіювання
        ~Donka() { printf("  * Donka %s припинила своє існування\n", name.c_str()); }
        void operator+=(const Donka &other);

        void setUmovy(char * umovy) { this->umovy = umovy; }

        virtual void print() override;      // Друк об'єкта в консоль
        void hereVal(float val) { printf(" * Прийом параметра float у перекритий метод класу Donka\n"); }
        // ^ Перекритий метод
};

Donka::Donka()      // Дефолтний к-тор
{
    time = new int[2];
    name = "noname";
    code = cur_code;
    time[0] = 0; time[1] = 0;
    place = "no_place";
}

Donka::Donka(char * filename)               // К-тор зчитування з файлу
{
    time = new int[2];
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

Donka::Donka(char *name, int t0, int t1, char *place, char *umovy)     // Класичний к-тор
{
    this->time = new int[2];
    this->name = name;
    this->code = code;
    this->time[0] = t0, this->time[1] = t1;
    this->place = place;
    this->umovy = umovy;
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
    this->umovy = other.umovy;
    ++ cur_code;
}

void Donka::operator+=(const Donka &other)      // Оператор +=
{
    if (this->name == "noname")
    {
        name = other.name;
        time[0] = other.time[0], time[1] = other.time[1];
        place = other.place;
        umovy = rand()%2 == 0 ? "хороші" : "погані";
    } else
    {
        name += ('-' + other.name);
        time[1] = other.time[1];
        place += ("_&_" + other.place);
        umovy = rand()%2 == 0 ? this->umovy : other.umovy;
    }
}

void Donka::print()                         // Друк об'єкта у консоль
{
    printf("[Donka]%s [код %d] відбудеться з %d по %d годину у %s, погода очікується %s\n",
        name.c_str(), code, time[0], time[1], place.c_str(), umovy.c_str());
}