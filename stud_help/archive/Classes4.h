#include <stdio.h>
#include <iostream>
#include <cmath>

class Base
{
    protected:
        int m, n;
        float ** matrix;
    public:
        Base();         // Конструктор
        void print();   // Друк масиву
        ~Base();
};

Base::Base()    // Конструктор
{
    printf("Введіть висоту: "); scanf("%d", &m);
    printf("Введіть ширину: "); scanf("%d", &n);
    printf("%d %d\n", m, n);
    matrix = new float *[m];
    for (int mi = 0; mi < m; ++mi)
    {
        matrix[mi] = new float[n];
        for (int ni = 0; ni < n; ++ni)
        {
            matrix[mi][ni] = (float)(rand() % 9) + 1.0 / ((float)(rand() % 10)+1);
            //printf("%d %d %f\n", mi, ni, matrix[mi][ni]);
        }
    }
}
void Base::print()                  // Друк масиву
{
    printf("Друк матриці\n");
    for (int mi = 0; mi < m; ++mi)
    {
        for (int ni = 0; ni < n; ++ni)
            printf("%f ", matrix[mi][ni]);
        printf("\n");
    }
}
Base::~Base()
{
    for (int mi = 0; mi < m; ++mi)
        delete[] matrix[mi];
    delete[] matrix;
}



// Клас наслідник

class Inherit_func: public Base
{
    public:
        void print_ABSGeom();   // знаходження сер. геометричного
};

void Inherit_func::print_ABSGeom()
{
    printf("Середні геометричні стовпців:\n");
    for (int ni = 0; ni < n; ++ni)
    {
        float mult = 1;
        for (int mi = 0; mi < m; ++mi)
            mult *= matrix[mi][ni];
        printf("  %d: %f\n", ni, std::pow(mult, 1.0/(float)n));
    }
    printf("Cереднє геом. всієї матриці:\n");
    float mult = 1;
    for (int mi = 0; mi < m; ++mi)
        for (int ni = 0; ni < n; ++ni)
            mult *= matrix[mi][ni];
    printf("    %f\n", std::pow(mult, 1.0/(float)(m*n)));
}