#include <iostream>
#include <fstream>

void obernuty (int *& arr, int size)
{
    int *temp = new int [size];
    for (int i = 0; i < size; i++)
        temp[size-1 - i] = arr[i];
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];

    delete [] temp;
}

void init()
{
    std::ifstream fin("FNC.TXT");
    std::ofstream fout("PROBLEM4.TXT");
    int lths[4];
    for (int i = 0; i < 4; i++)
        fin >> lths[i];
                                        // грубо, бо у масивів різні довжини, то не пайтон
    int *p_m1 = new int [lths[0]];
    int *p_m2 = new int [lths[1]];
    int *p_m3 = new int [lths[2]];
    int *p_m4 = new int [lths[3]];
    int most_neg_inx, neg_num = 0, neg_num_cand;
    for (int i = 0; i < lths[0]; i++)
    {
        fin >> p_m1[i];
        if (p_m1[i] < 0)
            neg_num_cand ++;
    }
    if (neg_num_cand > neg_num)
    {
        neg_num = neg_num_cand;
        most_neg_inx = 0;
    }
    fout << "У першому масиві " << neg_num_cand << " від'ємних чисел" << std::endl;
    neg_num_cand = 0;

    for (int i = 0; i < lths[1]; i++)
    {
        fin >> p_m2[i];
        if (p_m2[i] < 0)
            neg_num_cand ++;
    }
    if (neg_num_cand > neg_num)
    {
        neg_num = neg_num_cand;
        most_neg_inx = 1;
    }
    fout << "У другому масиві " << neg_num_cand << " від'ємних чисел" << std::endl;
    neg_num_cand = 0;

    for (int i = 0; i < lths[2]; i++)
    {
        fin >> p_m3[i];
        if (p_m3[i] < 0)
            neg_num_cand ++;
    }
    if (neg_num_cand > neg_num)
    {
        neg_num = neg_num_cand;
        most_neg_inx = 2;
    }
    fout << "У третьому масиві " << neg_num_cand << " від'ємних чисел" << std::endl;
    neg_num_cand = 0;

    for (int i = 0; i < lths[3]; i++)
    {
        fin >> p_m4[i];
        if (p_m4[i] < 0)
            neg_num_cand ++;
    }
    if (neg_num_cand > neg_num)
    {
        neg_num = neg_num_cand;
        most_neg_inx = 3;
    }
    fout << "У четвертому масиві " << neg_num_cand << " від'ємних чисел" << std::endl;
    neg_num_cand = 0;

    //std::cout << most_neg_inx << std::endl;

    switch (most_neg_inx)
    {
        case 0:
            obernuty(p_m1, lths[0]);
            fout << "\nОбернули перший масив." << std::endl;
            for (int i = 0; i < lths[0]; i++)
                fout << p_m1[i] << ' ';
            fout << std::endl;
            break;
        case 1:
            obernuty(p_m2, lths[1]);
            fout << "\nОбернули другий масив." << std::endl;
            for (int i = 0; i < lths[1]; i++)
                fout << p_m2[i] << ' ';
            fout << std::endl;
            break;
        case 2:
            obernuty(p_m3, lths[2]);
            fout << "\nОбернули третій масив." << std::endl;
            for (int i = 0; i < lths[2]; i++)
                fout << p_m3[i] << ' ';
            fout << std::endl;
            break;
        case 3:
            obernuty(p_m4, lths[3]);
            fout << "\nОбернули перший масив." << std::endl;
            for (int i = 0; i < lths[3]; i++)
                fout << p_m4[i] << ' ';
            fout << std::endl;
            break;
    }

    delete [] p_m1;
    delete [] p_m2;
    delete [] p_m3;
    delete [] p_m4;
    fin.close();
    fout.close();
}

int main()
{

    init();

    return 0;
}