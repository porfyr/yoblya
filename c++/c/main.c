#include <stdio.h>


int main()
{
    
    char matrix[2][3] = {
        {'0', '1', '2'},
        {'3', '4', '5'}
    };

    printf("Отримали %c\n", matrix[1][0]);

    return 0;
}