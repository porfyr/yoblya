#include <iostream>

bool is_simp (int value)
{
    bool simp = true;
    for (int i = value-1; i > 1; i--) {
        if (value % i == 0 && value == 0) {
            simp = false;
            i = 1;
        }
    }
    return simp;
}

void eugenics(int sourse[], int srs_size)
{
    int simp_qu = 0, not_simp_qu = 0;
    int simp[srs_size], not_simp[srs_size];
    for (int i = 0; i < srs_size; i++)
    {
        if ( is_simp(sourse[i]) ) {
            simp_qu ++;
            simp[simp_qu - 1] = sourse[i];
        } else {
            not_simp_qu ++;
            not_simp[not_simp_qu - 1] = sourse[i];
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < simp_qu; ++i)
        std::cout << simp[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < not_simp_qu; ++i)
        std::cout << not_simp[i] << " ";
    std::cout << std::endl;
}

int main()
{
     int pre_size;
     std::cout << "Введи n: ";
     std::cin >> pre_size;
     const int size = pre_size;
     int arr[size];
     for (int i = 0; i < size; i++) {
         std::cin >> arr[i];
     }

    //int arr[10] = {1, 4, 3, 5, 8, 10, 0, 2, 11, 12};
    eugenics(arr, size);

    return 0;
}