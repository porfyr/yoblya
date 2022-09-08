#include <iostream>

int size;

void print() {
    std::cout << "Розмір з іншої функції: " << size << std::endl;
}

int main()
{
    std::cout << "Введи розмір: ";
    std::cin >> size;

    print();

    std::cout << "Розмір з main(): " << size << std::endl;

    return 0;
}