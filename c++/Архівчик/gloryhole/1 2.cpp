#include <iostream>
#include <cmath>

int * sqrt_len(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";                   //  Друк масиву для перевірки передачі
    } std::cout << std::endl;

    int len_cand = 0, f_len = -1, first_inx_cand = -1, f_inx;
    for (int i = 0; i < size; i++) {
        if ( fmod( pow(arr[i], 0.5), 1 ) == 0 ) {
            if (len_cand == 0)
                first_inx_cand = i;
            len_cand ++;
        } else
            len_cand = 0;
        if (len_cand > f_len) {
            f_len = len_cand;
            f_inx = first_inx_cand;
        }
    }

    static int res[2] = {f_inx, f_len};
    return res;
}

int main() {

    int arr[6] = {7, 9, 4, 1, 2, 8};
    int * ptr = sqrt_len(arr, 6);

    std::cout << "Індекс першого елемента і довжина послідовності:\t" << ptr[0] << " " << ptr[1] << std::endl;

    return 0;
}