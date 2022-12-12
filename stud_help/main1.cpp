#include <stdio.h>
#include <iostream>
#include <string>

void switchRegs(std::string &str)           // Неробоча функція
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        } else if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
        else if (str[i] >= -64 && str[i] <= -33)
        {
            printf("%d\n", toascii(str[i]));
            std::cout << toascii(str[i]) << "\n";
            str[i] += 32;
        } else if (str[i] >= -32 && str[i] <= 0)
        {
            str[i] -= 32;
        }
    }
}

void change_men(std::string &str)       // Функція по заміні men на woman
{
    printf("%d\n", str.find("men"));
    for (int startInx = 0; startInx < str.length(); )
    {
        str.replace(startInx, 3, "women");
        startInx = str.find("men", startInx + 5);
    }
}

int main()
{
    setlocale(LC_CTYPE, "ua");

    std::string str = "MEN yoU haVe a nice сороЧки like that MEN!";
    switchRegs(str);
    printf("%s\n", str.c_str());
    change_men(str);
    printf("%s\n", str.c_str());

    return 0;
}