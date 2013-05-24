#include <iostream>
#include <stdio.h>
#include <string.h>

// Square root of 2^31 is 46340.95...
bool visited[47000] = {};
long long prime[4851] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 47000; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 47000; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// Dirty...
void PrintFactor(long long n)
{
    bool is_leading_term = true;
    printf("%lld =", n);
    if (n < 0)
    {
        printf(" -1");
        n = -n;
        is_leading_term = false;
    }

    long long d = n;
    for (long long i = 0; i < 4851 && (prime[i] * prime[i] <= d); i++)
    {
        while (d % prime[i] == 0)
        {
            if (is_leading_term)
            {
                printf(" %lld", prime[i]);
                is_leading_term = false;
            }
            else
            {
                printf(" x %lld", prime[i]);
            }
            d /= prime[i];
        }
    }

    if (d > 1) 
    {
        if (is_leading_term)
        {
            printf(" %lld", d);
            is_leading_term = false;
        }
        else
        {
            printf(" x %lld", d);
        }
    }

    if (is_leading_term)
    {
        puts(" 1");    
    }
    else
    {
        putchar('\n');
    }
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    while (std::cin >> n && n)
    {
        PrintFactor(n);
    }
    return 0;
}