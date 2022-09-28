#include <stdio.h>
#include <string>

int main()
{
    std::string ha;
    ha = "kk";
    ha += "hh";
    printf("%s\n", ha.c_str());

    return 0;
}