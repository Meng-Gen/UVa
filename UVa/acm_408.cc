#include <iostream>
#include <stdio.h>

// Euclidean Algorithm
inline long long gcd(long long a, long long b)
{
    while (b)
    {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int main(int argc, char* argv[])
{
    long long step;
    long long mod;
    while (std::cin >> step >> mod)
    {
        if (gcd(step, mod) == 1)
        {
            printf("%10lld%10lld    Good Choice\n", step, mod);
        }
        else
        {
            printf("%10lld%10lld    Bad Choice\n", step, mod);
        }
        putchar('\n');
    }
    return 0;
}