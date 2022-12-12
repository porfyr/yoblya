#include <stdio.h>
#include <math.h>

int main()
{
    float x, y;
    printf("Введи x: ");
    scanf("%f", &x);
    printf("Введи y: ");
    scanf("%f", &y);        // Введення x y

    // Свіч попадання в область
    switch ( x >= 0 && x <= 1 &&
           ((y >= 0 && y <= 1) || (y >= -1 && y < 0 && 
                sqrt(std::pow(x, 2) + std::pow(y, 2)) <= 1)))
    {
        case 1:
            printf("Точка належить заданій області\n");
            break;
        case 0:
            printf("Точка не належить заданій області\n");
            break;
        default:
            printf("Точка не належить заданій області default\n");
            break;
    }

    return 0;
}