#include <iostream>
#include <ctime>

clock_t start, stop;                                                 // Блок ініціалізації глобальних змінних для вимірювання
int rem_size;                                                       // часу швидкого сортування всередині функції
bool flag_first_end = false;


void print(int * arr, int size)                                      // Друк масиву
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void init(int * arr, int * res, int size, int dp)                    // Ініціалізація масиву й конпонентів
{
    if (dp == 0) {
        std::cout << "Введи діапазон: ";
        std::cin >> dp;
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = -dp + rand() % (2*dp + 1);
    }
    for (int i = 0; i < size; ++i) {
        res[i] = arr[i];
    }
}


void bulba(int * res, int size)                                      // Алгоритм бульбашки (обміну)
{
    start = clock();
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
    stop = clock();
    std::cout << "У масив res[" << size << "] записано посортований методом бульбашки масив arr[" << size << "]" << std::endl;
    std::cout << "Сортування тривало " << stop - start << " міліcекунд." << std::endl;
}

void vstav(int * res, int size)                                      // Алгоритм вставки
{
    start = clock();
    int key, i;
    for (int k = 1; k < size; ++k) {
        key = res[k];
        i = k - 1;
        while ((i >= 0) && (res[i] > key)) {
            res[i+1] = res[i];
            i = i - 1;
        }
        res[i+1] = key;
    }
    stop = clock();
    std::cout << "У масив res[" << size << "] записано посортований методом вставки масив arr[" << size << "]" << std::endl;
    std::cout << "Сортування тривало " << stop - start << " міліcекунд." << std::endl;
}

void quick(int * res, int fst, int lst, int ornl_size)               // Алгоритм швидкого сортування
{
    if (fst == 0 && lst == ornl_size-1) {
        start = clock();
        rem_size = ornl_size;
    }
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
    if (fst == lst && !flag_first_end) {
        stop = clock();
        std::cout << "У масив res[" << rem_size << "] записано посортований методом швидкого сортування масив arr[" << rem_size << "]" << std::endl;
        std::cout << "Сортування тривало " << stop - start << " міліcекунд." << std::endl;
        flag_first_end = true;
    }
}

void zlyv(int * arr, int l_size, int m, int r_size)                  // Алгоритм злиття
{
    int i, j, k, nl, nr;
    nl = m-l_size+1; nr = r_size-m;
    int larr[nl], rarr[nr];
    for(i = 0; i<nl; i++)
        larr[i] = arr[l_size+i];
    for(j = 0; j<nr; j++)
        rarr[j] = arr[m+1+j];
    i = 0; j = 0; k = l_size;
    while(i < nl && j<nr) {
        if(larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        }else{
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        arr[k] = larr[i];
        i++; k++;
    }
    while(j<nr) {
        arr[k] = rarr[j];
        j++; k++;
    }
}
void zlyi(int * res, int l_size, int r_size, int orn_size)
{
    if (orn_size) {
        start = clock();
        rem_size = orn_size;
    }
    int m;
    if(l_size < r_size) {
        int m = l_size+(r_size-l_size)/2;
        zlyi(res, l_size, m, 0);
        zlyi(res, m+1, r_size, 0);
        zlyv(res, l_size, m, r_size);
    } else  if (l_size == r_size && r_size == rem_size - 1){
        stop = clock();
        std::cout << l_size << " " << r_size << std::endl;
        std::cout << "У масив res[" << rem_size << "] записано посортований методом злиття масив arr[" << rem_size << "]" << std::endl;
        std::cout << "Сортування тривало " << stop - start << " міліcекунд." << std::endl;
    }
}

void brevno(int * arr, int size, int i)                              // Алгоритм пірамідального сортування
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        brevno(arr, size, largest);
    }
}
void MMM(int * res, int size)
{
    start = clock();
    for (int i = size / 2 - 1; i >= 0; i--)
        brevno(res, size, i);

    for (int i = size-1; i >= 0; i--)
    {
        std::swap(res[0], res[i]);
        brevno(res, i, 0);
    }
    stop = clock();
    std::cout << "У масив res[" << size << "] записано посортований методом пірамідального сортування масив arr[" << size << "]" << std::endl;
    std::cout << "Сортування тривало " << stop - start << " міліcекунд." << std::endl;
}

void rahuvaty(int * res, int size)
{
    start = clock();
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (res[i] > max)
            max = res[i];
        if (res[i] < min)
            min = res[i];
    }
    int *c = new int[max + 1 - min];
    for (int i = 0; i < max + 1 - min; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        c[res[i] - min] = c[res[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++) {
        while (c[j-min] != 0) {
            res[i] = j;
            c[j-min]--;
            i++;
        }
    }
    stop = clock();
    std::cout << "У масив res[" << size << "] записано посортований методом підрахунку масив arr[" << size << "]" << std::endl;
    std::cout << "Сортування тривало " << stop - start << " міліcекунд." << std::endl;
}

int main()
{
    const int size = 100000;
    int dp = 100;
    int arr[size], res[size];
    init (arr, res, size, dp);
    print (arr, size);

    bulba (res, size);

    //print (res, size);

    return 0;
}

/*
                                    Чернетки методів

    bulba (res, size);
    vstav (res, size);
    quick (res, 0, size-1, size);
    zlyi (res, 0, size-1, size);
    MMM (res, size);
    rahuvaty (res, size);

*/