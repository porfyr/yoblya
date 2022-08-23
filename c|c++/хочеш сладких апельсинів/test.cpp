#include <iostream> 
#include <stdio.h>

int main()
{ 
    
    char d[3][4] = {
        "123", "456", "789"
    };

    for (int r = 0; r < 3; r++) {
        if (r <= 1)
            std::cout << d[r] << std::endl;
        else {
            std::cout << d[r];
            std::cin.get();
        }
    }

    return 0; 
}