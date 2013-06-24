#include <iostream>
#include <stdio.h>

int ToDecimalTime(int traditional_time)
{
    long long rv = 0;
    rv += traditional_time % 10000; // CC and SS
    rv += traditional_time / 10000 % 100 * 60 * 100; // MM to CC
    rv += traditional_time / 1000000 * 60 * 60 * 100; // HH to CC
    rv = rv * 100000 / 86400;
    return rv;
}

int main(int argc, char* argv[]) 
{
    int traditional_time;
    while (std::cin >> traditional_time)
    {
        printf("%07d\n", ToDecimalTime(traditional_time));
    }
    return 0;
}