#include <iostream>
#include <stdio.h>

bool visited[1000001] = {};
long long prime[78498] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 1000001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 1000001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

inline void PrintPrimeFactor(long long n)
{
    long long d = n;
    for (long long i = 0; i < 78498 && (prime[i] * prime[i] <= d); i++)
    {
        if (d % prime[i] == 0)
        {
            do 
            {
                printf("    %lld\n", prime[i]);
                d /= prime[i];
            }
            while (d % prime[i] == 0);
        }
    }
    if (d > 1)
    {
        printf("    %lld\n", d);
    }
    putchar('\n');
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitPrimeTable();
    
    long long n;
    while (std::cin >> n && (n >= 0))
    {
        PrintPrimeFactor(n);
    }
    return 0;
}