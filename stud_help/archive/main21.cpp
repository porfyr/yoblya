#include <stdio.h>
#include <cstdlib>

void rand_init(int *x, int *y, int *m);         // заповнення масиву рандомними інтами [10 - 99]
void print(int *x, int *y, int *m);             // Друк масиву
void getGravityCenter(int *x, int *y, int *m);  // Виконання програми




int main()
{
    int x[10], y[10], m[10];
    int res[2]; // res[0] то є x, res[1] -- y
    rand_init(x, y, m);
    //print(x, y, m);
    getGravityCenter(x, y, m);

    return 0;
}




void rand_init(int *x, int *y, int *m)
{
    for (int i = 0; i < 10; ++i)
        x[i] = rand() % 90 + 10;
    for (int i = 0; i < 10; ++i)
        y[i] = rand() % 90 + 10;
    for (int i = 0; i < 10; ++i)
        m[i] = rand() % 90 + 10;
}

void print(int *x, int *y, int *m)
{
    for (int i = 0; i < 10; ++i)
        printf("%d ", x[i]);
    printf("\n");
    for (int i = 0; i < 10; ++i)
        printf("%d ", y[i]);
    printf("\n");
    for (int i = 0; i < 10; ++i)
        printf("%d ", y[i]);
    printf("\n");
}

void getGravityCenter(int *x, int *y, int *m)
{
    int sumX = 0, sumY = 0, sumM = 0;
    for (int i = 0; i < 10; ++i)
        sumX += m[i] * x[i];
    for (int i = 0; i < 10; ++i)
        sumY += m[i] * y[i];
    for (int i = 0; i < 10; ++i)
        sumM += m[i];
    int x0 = sumX / sumM;
    int y0 = sumY / sumM;
    printf("Центр тяжіння знаходиться у:\n   x0: %d\n   y0: %d\n", x0, y0);
}