#include <iostream>
#include <stdio.h>
#include <string.h>

bool prime[60001];

inline void InitPrimeTable()
{
    for (int i = 0; i < 60001; i++)
    {
        prime[i] = true;   
    }
    prime[0] = false;
    prime[1] = false;
    for (long long i = 2; i < 60001; i++)
    {
        if (prime[i])
        {
            for (long long j = 2; j * i < 60001; j++)
            {
                prime[j * i] = false;
            }
        }
    }
}

// http://en.wikipedia.org/wiki/Divisor_function
long long SigmaFunction(int n)
{
    int divisor[60001] = {};
    while (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] && (n % i == 0))
            {
                divisor[i]++;
                n /= i;
                break;
            }
        }
    }

    long long sum = 1;
    for (int i = 2; i < 60001; i++)
    {
        if (divisor[i] == 0)
        {
            continue;
        }
        long long rv = 0;
        for (int j = 0; j <= divisor[i]; j++)
        {
            rv *= i;
            rv += 1;
        }
        sum *= rv;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    puts("PERFECTION OUTPUT");
    int n;
    while (std::cin >> n && n)
    {
        long long divisor_sum = SigmaFunction(n) - n;
        if (n == divisor_sum)
        {
            printf("%5d  PERFECT\n", n);
        }
        else if (n > divisor_sum)
        {
            printf("%5d  DEFICIENT\n", n);
        }
        else
        {
            printf("%5d  ABUNDANT\n", n);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}