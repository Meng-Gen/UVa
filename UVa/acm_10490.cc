#include <iostream>
#include <stdio.h>

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

bool IsPrime(long long n)
{
    for (long long i = 0; i < 4851 && (prime[i] * prime[i] <= n); i++)
    {
        if (n == prime[i])
        {
            return true;
        }
        if (n % prime[i] == 0)
        {
            return false;
        }
    }
    return true;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitPrimeTable();
    
    long long n;
    while (std::cin >> n && n)
    {
        if (IsPrime(n))
        {
            if (IsPrime((1 << n) - 1))
            {
                printf("Perfect: %lld!\n", 
                    (long long)(1 << n - 1) * (long long)((1 << n) - 1));
            }
            else
            {
                puts("Given number is prime. But, NO perfect number is available.");
            }
        }
        else
        {
            puts("Given number is NOT prime! NO perfect number is available.");
        }
    }
    return 0;
}