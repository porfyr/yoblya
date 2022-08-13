#include <iostream>


void day_count (int * m_q)
{
    int d1, m1, y1,
        d2, m2, y2;
    std::cout << "Повводь 2 дати у форматі (день місяць рік)";
    std::cout << "Введи дату 1: ";
    std::cin >> d1 >> m1 >> y1;
    std::cout << "Введи дату 2: ";
    std::cin >> d2 >> m2 >> y2;

    int sum = 0;
    if (y1 == y2 && m1 == m2)
    {
        sum += d2 - d1;
    } else
    {
        int m, y = y1;
        bool approve = true;
        if (y1 % 4 == 0 && m1 == 2)
        {
            sum += 29 - d1;
            std::cout << "Додано решту високосного лютого: " << 29 - d1 << std::endl;
        } else {
            sum += m_q[m1-1] - d1;
            std::cout << "Додано решту звичайного місяця: " << m_q[m1-1] - d1 << "  <-  " << m_q[m1-1] << " - " << d1 << std::endl;
        }
        for (m = m1; approve; m++) {                    // Зсув ч-з особливість масиву на змінній m
            if (y == y2 && m == m2 - 1)
                break;
            if (y % 4 == 0 && m == 1) {
                sum += 29;
                std::cout << "Додано високосний лютий: " << 29 << std::endl;
            } else {
                sum += m_q[m];
                std::cout << "Додано дні чергового місяця: " << m_q[m] << std::endl;
            }
            if (m == 11) {
                y++;
                std::cout << "Додано рік, тепер " << y << std::endl;
                m = -1;
            }
        }
        sum += d2 + 1;
        std::cout << "Додано решту останнього місяця: " << d2 << std::endl;
    }
    std::cout << sum << " днів" << std::endl;
}

void new_years (int * m_q, std::string * d_w)
{
    int y1, y2, cur_dw = 0, cur_dm = 1, cur_m = 0, cur_y = 1990;
    bool approve = true;
    std::cout << "Введи почергово 2 роки: ";
    std::cin >> y1 >> y2;
    // y1 = 1990; y2 = 1991;
    for ( ; approve; cur_dm ++, cur_dw ++)
    {
        if ( (cur_y % 4 != 0) || (cur_y % 4 == 0 && cur_m != 1) )
        {
            if (cur_dm > m_q[cur_m])
            {
                cur_dm = 1;
                cur_m += 1;
            }
        } else if (cur_y % 4 == 0 && cur_m == 1)
        {
            if (cur_dm >= m_q[cur_m] + 2)
            {
                cur_dm = 1;
                cur_m += 1;
            }
        }
        if (cur_m == 12)
        {
            cur_m = 0;
            cur_y ++;
        }
        if (cur_dw == 7)
        {
            cur_dw = 0;
        }
        //if (cur_y > 1991)
        //    std::cout << "  " << d_w[cur_dw] << "\t" << cur_dm << "\t" << cur_m << "\t" << cur_y << std::endl;
        if (cur_y >= y1 && cur_y <= y2 && cur_dm == 1 && cur_m == 0)
            std::cout << cur_y << " – " << cur_dw << " " << d_w[cur_dw] << std::endl;
        if (cur_y == y2)
            approve = false;
    }
}

void fri_13_ct (int * m_q, std::string * d_w)
{
    int y, cur_y = 1990, cur_dw = 0, cur_dm = 1, cur_m = 0, fri13_count = 0;
    bool approve = true;
    std::cout << "Введи рік: ";
    std::cin >> y;
    for ( ; approve; cur_dm ++, cur_dw ++)
    {
        if ( (cur_y % 4 != 0) || (cur_y % 4 == 0 && cur_m != 1) )
        {
            if (cur_dm > m_q[cur_m])
            {
                cur_dm = 1;
                cur_m += 1;
            }
        } else if (cur_y % 4 == 0 && cur_m == 1)
        {
            if (cur_dm >= m_q[cur_m] + 2)
            {
                cur_dm = 1;
                cur_m += 1;
            }
        }
        if (cur_m == 12)
        {
            cur_m = 0;
            cur_y ++;
        }
        if (cur_dw == 7)
        {
            cur_dw = 0;
        }
        if (cur_dw == 4 && cur_dm == 13 && cur_y == y)
        {
            std::cout << "Номер місяця " << cur_m+1 << std::endl;
            fri13_count += 1;
        }
        if (cur_y == y+1)
        {
            approve = false;
        }
    }
    std::cout << "Загалом було " << fri13_count << " п'ятниць 13. Вот" << std::endl;
}

void bd_dw (int * m_q, std::string * d_w)
{
    int y, m, d, cur_y = 1990, cur_dw = 0, cur_dm = 1, cur_m = 0;
    bool approve = true;
    std::cout << "Введи дату (день місяць рік): ";
    std::cin >> d >> m >> y;
    m--;
    for ( ; approve; cur_dm ++, cur_dw ++)
    {
        if ( (cur_y % 4 != 0) || (cur_y % 4 == 0 && cur_m != 1) )
        {
            if (cur_dm > m_q[cur_m])
            {
                cur_dm = 1;
                cur_m += 1;
            }
        } else if (cur_y % 4 == 0 && cur_m == 1)
        {
            if (cur_dm >= m_q[cur_m] + 2)
            {
                cur_dm = 1;
                cur_m += 1;
            }
        }
        if (cur_m == 12)
        {
            cur_m = 0;
            cur_y ++;
        }
        if (cur_dw == 7)
        {
            cur_dw = 0;
        }
        if (cur_m == m && cur_dm == d && cur_y == y)
        {
            std::cout << d_w[cur_dw] << std::endl;
            approve = false;
        }
    }
}

int d_of_w(int * m_q, int d, int m, int y)
{
    int cur_y = 1990, cur_dw = 0, cur_dm = 1, cur_m = 0, res;
    bool approve = true;
    for ( ; approve; cur_dm ++, cur_dw ++)
    {
        if ( (cur_y % 4 != 0) || (cur_y % 4 == 0 && cur_m != 1) )
        {
            if (cur_dm > m_q[cur_m])
            {
                cur_dm = 1;
                cur_m += 1;
            }
        } else if (cur_y % 4 == 0 && cur_m == 1)
        {
            if (cur_dm >= m_q[cur_m] + 2)
            {
                cur_dm = 1;
                cur_m += 1;
            }
        }
        if (cur_m == 12)
        {
            cur_m = 0;
            cur_y ++;
        }
        if (cur_dw == 7)
        {
            cur_dw = 0;
        }
        if (cur_m == m && cur_dm == d && cur_y == y)
        {
            approve = false;
            std::cout << "Надано день тижня відштовхуючись від 1990 року – " << cur_dw << std::endl;
            res = cur_dw;
        }
    }
    return res;
}
void whare_my_date (int * m_q, std::string * d_w)
{
    int y, m, d, k, dw;
    bool approve = true;
    std::cout << "Введи дату (день місяць рік): ";
    std::cin >> d >> m >> y;
    m --;
    dw = d_of_w(m_q, d, m, y);
    std::cout << "Введи число k: ";
    std::cin >> k;
    for ( ; approve; d --, dw --, k--)
    {
        if ( (y % 4 != 0) || (y % 4 == 0 && m != 2) )
        {
            if (d == 0)
            {
                m --;
                d = m_q[m];
            }
        } else if (y % 4 == 0 && m == 2)
        {
            if (d == 0)
            {
                m --;
                d = m_q[m]+1;
            }
        }
        if (m == -1)
        {
            m = 11;
            y --;
        }
        if (dw == -1)
        {
            dw = 6;
        }
        if (k == 0)
        {
            std::cout << d << "." << m + 1 << "." << y << " " << d_w[dw] << std::endl;
            approve = false;
        }
    }
}

void fst_fri13 (int * m_q, std::string * d_w)
{
    int y, m, d, cur_y = 1900, cur_dw = 0, cur_dm = 1, cur_m = 0;
    bool approve = true;
    std::cout << "Введи дату (день місяць рік): ";
    std::cin >> d >> m >> y;
    m--;
    for ( ; approve; cur_dm ++, cur_dw ++)
    {
        if ( (cur_y % 4 != 0) || (cur_y % 4 == 0 && cur_m != 1) )
        {
            if (cur_dm > m_q[cur_m])
            {
                cur_dm = 1;
                cur_m += 1;
            }
        } else if (cur_y % 4 == 0 && cur_m == 1)
        {
            if (cur_dm >= m_q[cur_m] + 2)
            {
                cur_dm = 1;
                cur_m += 1;
            }
        }
        if (cur_m == 12)
        {
            cur_m = 0;
            cur_y ++;
        }
        if (cur_dw == 7)
        {
            cur_dw = 0;
        }
        if (cur_y >= y && cur_dw == 4 && cur_dm == 13)
        {
            std::cout << "Перша п'ятниця буде " << cur_dm << " " << cur_m+1 << " " << cur_y << std::endl;
            approve = false;
        }
    }
}

int main()
{
    int m_q[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string d_w[7] = {"понеділок", "вівторок", "середа   ", "четвер   ", "п'ятничка", "субота   ", "неділя   "};
    
    int choise;
    std::cout << "Дано вибір методів, введи в термінал його номер:" << std::endl;
    std::cout << "  1 - Знайти скільки днів пройшло від дати1 до дати2" << std::endl;
    std::cout << "  2 - Знайти на які дні тижня припадав чи буде припадати Новий рік" << std::endl;
    std::cout << "  3 - Знайти скільки п’ятниць, 13, буде (було) в заданому році." << std::endl;
    std::cout << "  4 - Знайти в який день тижня Ви народилися." << std::endl;
    std::cout << "  5 - Визначити який день тижня та яка дата була k днів тому від дати2." << std::endl;
    std::cout << "  6 - Знайти першу п’ятницю 13, яка йде після заданої дати." << std::endl;
    std::cout << "Вибери один з методів (1-6): ";
    std::cin >> choise;

    switch (choise)
    {
        case 1:
            day_count (m_q);
            break;
        case 2:
            new_years(m_q, d_w);
            break;
        case 3:
            fri_13_ct(m_q, d_w);
            break;
        case 4:
            bd_dw(m_q, d_w);
            break;
        case 5:
            whare_my_date(m_q, d_w);
            break;
        case 6:
            fst_fri13(m_q, d_w);
            break;
        default:
            std::cout << "Нема такого методу в списку" << std::endl;
    }
    

    return 0;
}

/*  Чернетка методів


    day_count (m_q);
    new_years(m_q, d_w);
    fri_13_ct(m_q, d_w);
    bd_dw(m_q, d_w);
    whare_my_date(m_q, d_w);
    fst_fri13(m_q, d_w);


*/