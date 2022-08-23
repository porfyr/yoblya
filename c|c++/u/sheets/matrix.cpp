#include <iostream>

void init_matrix (int **& matrix, int & rows, int & cols);
void display (int **& matrix, int & rows, int & cols);
void var1 (int **& matrix, int & rows, int & cols);

int main()
{
    int ** matrix;
    int rows, columns;
    init_matrix (matrix, rows, columns);
    var1 (matrix, rows, columns);
    display (matrix, rows, columns);
    
    return 0;
}


void init_matrix (int **& matrix, int & rows, int & columns)
{
    int rand_or_hand;
    std::cout << "рядки = ";
    std::cin >> rows;
    std::cout << "стовпці = ";
    std::cin >> columns;
    std::cout << "Для рандомного вводу тицьни 1\nдля ручного 0\n-> ";
    std::cin >> rand_or_hand;
    matrix = new int *[rows+1];
    for (int r = 0; r < rows; ++r)    matrix[r] = new int[columns];
    if (rand_or_hand)
    {
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < columns; c++)
                matrix[r][c] = rand() % 42 - 42/2;
    } else {
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < columns; c++)
                std::cin >> matrix[r][c];
    }
    std::cout << "Ініціалізовано матрицю:" << std::endl;
    display (matrix, rows, columns);
}

void swap_arrays(int * arr1, int * arr2, int size) {
    for (int c = 0; c < size; c++)
        std::swap (arr1[c], arr2[c]);
}
void var1 (int **& matrix, int & rows, int & columns)
{
    int max_el, max_inx, signed_count, max_sgd_ct, sg_row_inx, k = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < columns; c++)
        {
            if (matrix[r][c] == max_el && c >= max_inx)
                max_inx = c;
            else if (matrix[r][c] > max_el)
            {
                max_el = matrix[r][c];
                max_inx = c;
            }
        }
    columns ++;
    for (int r = 0; r < rows; r++)
        matrix[r][columns-1] = 0;
    std::cout << "Найбільший елемент " << max_el << " з внутріщнім індексом " << max_inx << std::endl;
    //max_inx = 4;
    for (int r = 0; r < rows; r++)
        for (int c = columns-1; c > max_inx+1; c--) {
            std::swap (matrix[r][c], matrix[r][c-1]);
        }
    
    for (int r = 0; r < rows; r++) {
        int ct_cand = 0;
        bool have_sgd = 0;
        for (int c = 0; c < columns; c++)
            if (matrix[r][c] < 0)
            {
                ct_cand ++;
                have_sgd = 1;
            }
        if (!have_sgd)
            k ++;
        if (ct_cand > max_sgd_ct)
        {
            max_sgd_ct = ct_cand;
            sg_row_inx = r;
        }
    }
    std::cout << "k = " << k << std::endl;
    std::cout << sg_row_inx+1 << " рядок ми змушені конфіскувати:" << std::endl;
    for (int r = sg_row_inx; r < rows-1; r++)
        swap_arrays (matrix[r], matrix[r+1], columns);
    rows --;
}


void display (int **& matrix, int & rows, int & columns)
{
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++)
            std::cout << matrix[r][c] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/*

    std::cout << "њ" << std::endl;

*/