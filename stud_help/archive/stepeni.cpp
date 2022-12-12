#include <stdio.h>


double pow(double base, int ex)
{
    if (ex == 0)                // піднесення до нульового
        return 1;
    else if (ex < 0)            // до від'ємного
        return 1 / pow(base, -ex);
    else if (ex % 2 == 0)       // до парного
    {
        double half_pow = pow(base, ex/2);
        return half_pow * half_pow;
    }
    else                        // до int
        return base * pow(base, ex - 1);
}

float pow(float base, int ex)
{
    if (ex == 0)                // піднесення до нульового
        return 1;
    else if (ex < 0)            // до від'ємного
        return 1 / pow(base, -ex);
    else if (ex % 2 == 0)       // до парного
    {
        float half_pow = pow(base, ex/2);
        return half_pow * half_pow;
    }
    else                        // до int
        return base * pow(base, ex - 1);
}

float pow(int base, int ex)
{
    if (ex == 0)                // піднесення до нульового
        return 1;
    else if (ex < 0)            // до від'ємного
        return 1 / pow(base, -ex);
    else if (ex % 2 == 0)       // до парного
    {
        int half_pow = pow(base, ex/2);
        return half_pow * half_pow;
    }
    else                        // до int
        return base * pow(base, ex - 1);
}

// int pow(int base, unsigned int ex)
// {
//     if (ex == 0)                // піднесення до нульового
//         return 1;
//     else if (ex < 0)            // до від'ємного
//         return 1 / pow(base, -ex);
//     else if (ex % 2 == 0)       // до парного
//     {
//         int half_pow = pow(base, ex/2);
//         return half_pow * half_pow;
//     }
//     else                        // до int
//         return base * pow(base, ex - 1);
// }

int main()
{
    printf("%f\n", pow(4, -2));

    return 0;
}