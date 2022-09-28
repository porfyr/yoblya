#include <stdio.h>
#include <string>
#include <fstream>
#include "Operate.h"


int main()
{
    Operate text("t.txt");
    text.task_1();
    text.task_2();
    text.task_3();

    return 0;
}