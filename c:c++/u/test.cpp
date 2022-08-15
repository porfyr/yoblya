#include <iostream>
#include <cmath>


int main()
{
    int a = 198;

    int i = 0;
    std::cout << (a % (int) pow(10, i+1) - a % (int) pow(10, i))/ (int) pow(10, i) << std::endl;

    return 0;
}