#include <stdio.h>
#include <string>
#include <fstream>
#include "Operate.h"


int main()
{
    Operate text("t.txt");  // Ініціалізація
    text.task_1();
    text.task_2();
    text.task_3();
    text.task_4();
    text.task_9();

    return 0;
}