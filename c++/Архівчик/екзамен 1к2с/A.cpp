#include <iostream>
#include <cmath>


int main()
{
    int a, sum_p, sum_np;
    int fs[100];
    std::cout << "Введи число: ";
    std::cin >> a;
    for (int i = 0; i < 100; i++)
        fs[i] = (a % (int) pow(10, i+1) - a % (int) pow(10, i))/ (int) pow(10, i);
    
    for (int i = 0; i < 100; i++)
        if (fs[i] % 2 == 0)
            sum_p += fs[i];
        else
            sum_np += fs[i];
    if (sum_p == sum_np)
        std::cout << "Cума непарних цифер рівна сумі парних." << std::endl;
    else
        std::cout << "Cума непарних цифер не рівна сумі парних." << std::endl;

    return 0;
}