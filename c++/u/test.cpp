#include <stdio.h>
#include <string>

int main()
{
    int i = 3 ? true : i = 2;
    //i = 9;
    printf("%d\n", i);

    return 0;
}