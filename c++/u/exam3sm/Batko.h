#include <stdio.h>
#include <string>
#include <fstream>
#include "Abst.h"

class Batko: public Abst
{
    private:
        std::string name;
        int code;
        int * time;     // [0] Година початку, [1] година кінця
        std::string place; // Місце проведення
    public:
        Batko(): time(new int[2]) {}
        Batko(char* filename);
        ~Batko() { delete[] time; }

        virtual void print() override;
        void setName(std::string name) { this->name = name; }
        void setTime(int t0, int t1) { this->time[0] = t0; this->time[1] = t1; }
        void setPlace(std::string place) { this->place = place; }
};

Batko::Batko(char* filename)
    : time(new int[2])
{
    std::ifstream fin(filename);
    fin >> code;
    fin >> name;
    fin >> time[0]; fin >> time[1];
    fin >> place;
    fin.close();
}

void Batko::print()
{
    printf("%s код %d відбудеться з %d по %d у %s\n", name.c_str(), code, time[0], time[1], place.c_str());
}