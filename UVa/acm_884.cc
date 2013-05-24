#include <iostream>
#include <stdio.h>

int prime_factor_count[1000001] = {};
int query[1000001] = {};

inline void InitPrimeFactorCount()
{
    for (int i = 2; i < 1000001; i++)
    {
        if (!prime_factor_count[i])
        {
            for (int j = i; j < 1000001; j += i)
            {
                prime_factor_count[j]++;
                int n = j/i;
                while (n % i == 0)
                {
                    n /= i;
                    prime_factor_count[j]++;
                }
            }
        }
    }
}

inline void InitQueryTable()
{
    for (int i = 2; i < 1000001; i++)
    {
        query[i] = query[i-1] + prime_factor_count[i];
    }
}

int main(int argc, char* argv[])
{
    InitPrimeFactorCount();
    InitQueryTable();

    long long n;
    while (std::cin >> n)
    {
        printf("%lld\n", query[n]);
    }
    return 0;
}