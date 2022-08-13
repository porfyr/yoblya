#include <iostream>



int main()
{

    int pre_n;
    std::cout << "Введи n: ";
    std::cin >> pre_n; std::cout << std::endl;
    const int size = pre_n * 2;
    int arr[size][size];
    for (int i = 0; i < size; ++i) {                    // Надання масиву рандомних значеннь значеннь
        for (int j = 0; j < size; ++j)
            arr[i][j] = rand() % 40;
    }

    std::cout << "Друк масиву: " << std::endl;;         // Друк масиву
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int max_num = -1;                                   // Фіксація індексу найбільшого значення
    int inx[2];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] > max_num) {
                max_num = arr[i][j];
                inx[0] = i; inx[1] = j;
            }
        }
    }
    
    arr[inx[0]][inx[1]] = arr[size - 1][size - 1];      // Міняємо місцями потрібні значення
    arr[size - 1][size - 1] = max_num;

    std::cout << "\nДрук масиву: " << std::endl;;       // Друк масиву
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nВоно робе\n" << std::endl;

    return 0;
}




/*
      Чернетки


    std::cout << "hehe" <<std::endl;

    void pt_arr(int ** arr, int size)        // Вивід масиву для перевірки
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << arr[i][j] << " " << std::endl;
        std::cout << std::endl;
    }
}
*/