#include <stdio.h>
#include <iostream>
#include <stack>
#include <math.h>


int main()
{
    int N;
    printf("Введіть число: ");
    scanf("%d", &N);

    std::stack<int> sk;
    for (int i = 0, m = 1; i < floor(log10(abs(N))) + 1; ++i, m *= 10)
        if ((N%m*10)/m == 1)
            sk.push(0);
        else if ((N%m*10)/m == 0)
            sk.push(1);
        else
            printf("%d\n", %%%%%%%%%%%%);
            //sk.push((N%m*10)/m);

    std::cout << sk.top();

    return 0;
}