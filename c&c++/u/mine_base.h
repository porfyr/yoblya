#include <iostream>


void ptn_pnh()
{
    std::cout << "TrO" << std::endl;
}

void print(int * arr, int size)                                // Друк масиву (int)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print(char * arr, int size)                               // Друк масиву (char)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

char charer(int n)                             // Перетворити цифри в символи чисел char
{
    if (n < 0)
        return (char) 48 - n%10;
    else
        return (char) 48 - n%10;
}











/*
            __________
           |Сортування|
            ––––––––––
*/

void bulba(int * res, int size)                      // Алгоритм бульбашки (обміну)
{
    while (true) {
        bool swap_exectd = false;
        for (int i = 0; i < size - 1; ++i) {
            if (res[i] > res[i+1]) {
                std::swap (res[i], res[i+1]);
                swap_exectd = true;
            }
        }
        if ( !swap_exectd )
            break;
    }
}

void quick(int * res, int fst, int lst, int ornl_size)    // Алгоритм швидкого сортування
{
    if (fst < lst) {
        int l = fst, r = lst;
        int midd = res[ (l+r)/2 ];
        do {
            while (res[l] < midd)
                l++;
            while (res[r] > midd)
                r--;
            if (l <= r) {
                std::swap (res[l], res[r]);
                l++; r--;
            }
        } while (l < r);
        quick (res, fst, r, 0);
        quick (res, l, lst, 0);
    }
}