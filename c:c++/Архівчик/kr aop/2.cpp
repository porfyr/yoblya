#include <iostream>
#include <fstream>

int standart_words_count = 1000;
int standart_size_of_word = 40;
const int length = standart_size_of_word;
const int words_count = standart_words_count;


bool checkw(char * c)
{
    bool has = false, hasnt_0;
    char sy[7] = " ,.!?\n";
    for (int i = 0; i < length; i++)
        for (int s = 0; s < 6; s++)
            if (c[i] == sy[s]) 
                has = true;
    if (c[0] == 0)
        has = true;
    return has;
}

bool check(char c)
{
    bool has = false;
    char sy[7] = " ,.!?\n";
    for (int s = 0; s < 6; s++)
        if (c == sy[s])
            has = true;
    return has;
}

bool has_ae(char *c)
{
    //std::cout << "Слово " << c << '\t';
    bool has = false;
    for (int i = 0; i < length; ++i)
        if (c[i] == 'a' || c[i] == 'e' )
            has = true;
    //std::cout << has << std::endl;
    return has;
}

void char_cpy(char *a, char *b)
{
    for (int i = 0; i < length; ++i)
        b[i] = a[i];
}

void init_list(char **& words, int &kursor)
{
    std::ifstream fin("t.txt");

    words = new char *[words_count];                    // Створення масиву
    for (int i = 0; i < words_count; i++) words[i] = new char [length];

    char c;
    char buffer[length];
    for (int i = 0; fin.get(c);)
    {
        if ( check(c) )         // Маркeр закінчення слова
        {
            if (!has_ae(buffer) && !checkw(buffer) )           // Перевірка буфера слова на ae
            {
                //std::cout << "Слово " << buffer << std::endl;
                char_cpy(buffer, words[kursor]);
                kursor ++;
            }
            for (int j = 0; j < length; ++j) buffer[j] = 0;
            i = 0;
        }
        else {
            buffer[i] = c;
            i++;
            //buffer[i+1] = '\0';
        }
    }
    fin.close();

    // well works
}

void sort(char ** words, int size)
{
    //std::cout << "Почато сотрування" << std::endl;
    bool approve = true;
    while (approve)
    {
        //std::cout << "\n      -- Ше по одній --" << std::endl;
        bool is_swap_executed = false;
        for (int i = 0; i < size - 1; ++i)
        {
            //std::cout << "є " << words[i] << ' ' << words[i+1] << std::endl;
            if (words[i][0] < words[i+1][0])
            {
                std::swap (words[i], words[i+1]);
                //std::cout << "Відбулась заміна" << std::endl;
                //std::cout << "Замінено " << words[i] << ' ' << words[i+1] << std::endl;
                is_swap_executed = true;
            }
            else if (words[i][0] == words[i+1][0] && words[i][1] && words[i+1][1] && words[i][1] < words[i+1][1])
            {
                std::swap (words[i], words[i+1]);
                //std::cout << "Відбулась заміна" << std::endl;
                //std::cout << "Замінено по 2 букві " << words[i] << ' ' << words[i+1] << std::endl;
                is_swap_executed = true;
            }
        }
        if ( !is_swap_executed ) {
            approve = false;
            //std::cout << "Получається заміни не було" << std::endl;
        }
    }
    //std::cout << std::endl;
    //for (int i = 0; i < size; i++)
    //    std::cout << words[i] << std::endl;
}

void write(char **& words, int size)
{
    std::ofstream fout("t.txt", std::ios::out | std::ios::app);
    fout << std::endl;
    for (int i = 0; i <= size; ++i)
        fout << words[i] << std::endl;
    fout.close();
}

int main() 
{
    int size = 0;
    char ** words;
    //int size_of_buffer = 0;
    std::cout << "Створено матрицю символів" << std::endl;
    
    init_list (words, size);
    std::cout << "Ініціалізовано список слів" << std::endl;

    sort (words, size);
    std::cout << "Посортовано слова" << std::endl;

    write (words, size);
    std::cout << "Записано посортоване" << std::endl;

    return 0;
}