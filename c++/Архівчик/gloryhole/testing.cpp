#include <iostream>


void pt_arr(int arr[][], size_t size)        // Вивід масиву для перевірки
{
    for ( size_t i = 0; i < size; i++ )
    {
        for ( size_t j = 0; j < size; j++ )
            std::cout << arr[i][j] << " " << std::endl;;
    }
}

int main(){

    extern const int size = 3;
    int arr[size][size] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    //pt_arr(reinterpret_cast<int *>( arr ), size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    

    return 0; 

}

/*
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << arr[i][j] << " " << std::endl;
        
    }

    std::cout << std::endl;
*/