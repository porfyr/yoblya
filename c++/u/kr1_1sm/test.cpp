#include <stdio.h>
//#include <fstream>

bool ch_eq(char * c1, char * c2)
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

int main()
{
    char car1[30] = "Богдан";
    char car2[30] = "Богдан";
    printf("%d\n", ch_eq(car1, car2));

    return 0;
}