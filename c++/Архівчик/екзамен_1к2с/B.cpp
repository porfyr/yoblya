#include <iostream>
#include <fstream>

void check()
{
    std::ifstream fin("IN*.TXT");
    std::ofstream fout("OUT.TXT");
    char letter;
    int cur_letter = 1;
    bool is_len_4 = false;
    while (fin.get(letter))
    {
        if (letter != ' ' || letter != '\n')
            cur_letter ++;
        else
        {
            if (cur_letter == 4)
            {
                is_len_4 = true;
                break;
            }
            cur_letter = 1;
        }
    }

    fin.close();
    fout.close();

    if (is_len_4)
        fout << "Присутнє слово з довжиною 4." << std::endl;
    else
        fout << "Нема слова з довжиною 4." << std::endl;
        
}

int main()
{

    check();

    return 0;
}