#include <stdio.h>
#include <iostream>


int main()
{
    int *arr = new int[2];
    std::cin >> arr[1];
    std::cin >> arr[2];
    printf("%d %d\n", arr[1], arr[2]);
    
    return 0;
}