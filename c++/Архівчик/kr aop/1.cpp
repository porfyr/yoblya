#include <iostream>

int sum(long long int * arr, int n)
{
    long long int sumr = 0;
    for (int i = 0; i < n; i++)
    {
        sumr += arr[i];
        //std::cout << i << std::endl;
        //std::cout << sumr << ' ' << arr[i] << std::endl;
        //std::cout << sumr << std::endl;
    }
    std::cout << sumr << std::endl;
    return sumr;
}

int mul(long long int * arr, int n)
{
    long long int mulr = 1;
    for (int i = 0; i < n; i++)
    {
        //std::cout << arr[i] << ' ' << mulr << std::endl;
        mulr *= arr[i];
    }
    std::cout << "mulr " << mulr << std::endl;
    return mulr;
}

int div(long long int * arr, int n)
{
    long long int sum_rest = 0;
    for (int i = 1; i < n; i++)
    {
        //std::cout << sum_rest << ' ' << arr[i] << std::endl;
        sum_rest += arr[i];
    }
    if (sum_rest != 0) {
        return arr[0] / sum_rest;
    } else
        return 2147483647;
}

void e(long long int * arr, int n, char c);

void display(long long int * arr, int n)
{
    std::cout << "\nПоказ масиву" << std::endl;
    for (int i = 0; i < n; ++i)
        std::cout << "arr[" << i << "] " << arr[i] << '\n';
    std::cout << std::endl;
}

int main()
{
    int n;
    char c;
    std::cout << "Введи n: ";
    std::cin >> n;
    //n = 10;


    long long int * arr = new long long int [n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 - 50;

    display(arr, n);

    std::cout << "Введи c: ";
    std::cin >> c;

    e(arr, n, c);


    return 0;
}


void e(long long int * arr, int n, char c)
{
    switch (c)
    {
        case '+':
            std::cout << "Вибрано додавання" << std::endl;
            for (int i = 0; i < n; ++i)
            {
                arr[i] += sum(arr, n);
                //std::cout << arr[i] << std::endl;
            }
            std::cout << "Закінчено додавання" << std::endl;
            display(arr, n);
            break;
        case '*':
            std::cout << "Почато перемножування" << std::endl;
            for (int i = 0; i < n; ++i)
            {
                arr[i] += mul(arr, n);
            }
            std::cout << "Закінчено перемножування" << std::endl;
            display(arr, n);
            break;
        case '/':
            std::cout << "Почато переділення" << std::endl;
            for (int i = 0; i < n; ++i)
            {
                //std::cout<< "arr[" << i << "]: " << arr[i] << std::endl;
                arr[i] -= div(arr, n);
            }
            std::cout << "Закінчено переділення" << std::endl;
            display(arr, n);
            break;
        default:
            std::cout << "char введений неправильно" << std::endl;
            std::cout << "Введи c: ";
            std::cin >> c;
            e(arr, n, c);
            break;
    }
}