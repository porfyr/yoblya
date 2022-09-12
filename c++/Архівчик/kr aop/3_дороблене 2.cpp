#include <iostream>
#include <fstream>

struct fuel_consumption {
    double town;
    double highway;
};

struct tachka {
    char name[50];
    int  price;
    int  year_present;
    fuel_consumption rozhid;
};


void read (tachka *&tachky, int tc)
{
    std::ifstream fin("tachky.txt");
    for (int i = 0; i < tc; i++)
    {
        char n;
        int j = 0;
        while (fin.get(n) && n != '\n')
        {
            tachky[i].name[j] = n;
            j++;
        }
        std::cout << tachky[i].name << std::endl;
        fin >> tachky[i].price;
        fin >> tachky[i].year_present;
        fin >> tachky[i].rozhid.town;
        fin >> tachky[i].rozhid.highway;
        fin.get();
        fin.get();
    }
    fin.close();
}

void newest (tachka *&tachky, int tc)
{
    int just_newest_inx = 0;
    int year = 0;
    for (int i = 0; i < tc; i++)
        if (tachky[i].year_present > year)
            {
                year = tachky[i].year_present;
                just_newest_inx = i;
            }
    std::strcpy(tachky[tc-1].name, tachky[just_newest_inx].name);
    tachky[tc-1].price = tachky[just_newest_inx].price;
    tachky[tc-1].year_present = tachky[just_newest_inx].year_present;
    tachky[tc-1].rozhid.town = tachky[just_newest_inx].rozhid.town;
    tachky[tc-1].rozhid.highway = tachky[just_newest_inx].rozhid.highway;
}

void yamy (tachka *&tachky, int tc)
{
    int benzosmk = 7;
    //std::cout << "Введи, який же додатковий розхід палива очікує мешканців Львова: ";
    //std::cin >> benzosmk;
    for (int i = 0; i < tc; i++)
        tachky[i].rozhid.town += benzosmk;
}

void write (tachka *&tachky, int tc)
{
    std::ofstream fout("out.txt");
    for (int i = 0; i < tc; i++)
    {
        fout << tachky[i].name << std::endl;
        fout << tachky[i].price << std::endl;
        fout << tachky[i].year_present << std::endl;
        fout << tachky[i].rozhid.town << std::endl;
        fout << tachky[i].rozhid.highway << std::endl;
        fout << std::endl;
    }
    

    fout.close();
}

int main()
{
    int tachky_count = 7;
    tachka * tachky = new tachka [tachky_count];
    read (tachky, tachky_count-1);
    newest (tachky, tachky_count);
    yamy (tachky, tachky_count);
    write (tachky, tachky_count);

    delete [] tachky;
    return 0;
}