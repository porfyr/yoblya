#include <iostream>
#include <fstream>

void copy(char * a, char * b)
{
    for (int i = 0; i < 30; i++)
        b[i] = a[i];
}

bool check_letter(char c)
{
    bool is_vowel = false;
    char vowels[13] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y', '\n'};

    for (int i = 0; i < 13; i++)
        if (c == vowels[i])
            is_vowel = true;

    return is_vowel;
}

void read(char **& sts)
{
    std::ifstream fin("ProblemIn.txt");
    int cur_word = 0, cur_letter = 0;
    char letter;
    while (fin.get(letter) && letter != '.')
    {
        //std::cout << letter;
        if (letter == ' ')
        {
            cur_word ++;
            cur_letter = 0;
        }
        else
        {
            sts[cur_word][cur_letter] = letter;
            cur_letter ++;
        }
            
    }
    //for (int i = 0; i <= cur_word; i++)
    //    std::cout << sts[i] << std::endl;
    fin.close();
}

void build (char ** sts, char **& new_sts)
{
    int cur_wd = 0;
    for (int i = 0; i < 100; i++)
        if (check_letter (sts[i][0]))
        {
            //std::cout << sts[i] << std::endl;
            copy(sts[i], new_sts[cur_wd]);
            //std::cout << new_sts[cur_wd] << std::endl;
            cur_wd ++;
        }
    for (int i = 0; i < cur_wd; i++)
        if (i < cur_wd-1)
            std::cout << new_sts[i] << ' ';
        else
            std::cout << new_sts[i] << ".\n";
}

int main()
{

    char ** sts = new char *[100];
    char ** new_sts = new char *[100];
    for (int i = 0; i < 100; i++)
    {
        sts[i] = new char [30];
        new_sts[i] = new char [30];
    }
    read (sts);
    build (sts, new_sts);
    //std::cout << check_letter ('a') << std::endl;

    delete [] sts;
    delete [] new_sts;
    return 0;
}