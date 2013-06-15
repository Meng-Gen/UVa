#include <iostream>
#include <stdio.h>

bool visited[10005] = {};
long long prime[1229] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 10005; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 10005; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

bool IsPrime(long long n)
{
    for (long long i = 0; i < 1229 && (prime[i] * prime[i] <= n); i++)
    {
        if (n % prime[i] == 0 && n != prime[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    while (std::cin >> n)
    {
        if (n <= 3)
        {
            printf("%lld is not the sum of two primes!\n", n);
        }
        else if (n % 2 == 0)
        {
            bool found = false;
            for (long long i = n/2 - 1; i > 1; i--)
            {
                if (IsPrime(i) && IsPrime(n-i))
                {
                    printf("%lld is the sum of %lld and %lld.\n", n, i, n-i);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                printf("%lld is not the sum of two primes!\n", n);
            }
        }
        else
        {
            if (IsPrime(n - 2))
            {
                printf("%lld is the sum of 2 and %lld.\n", n, n-2);
            }
            else
            {
                printf("%lld is not the sum of two primes!\n", n);
            }
        }
    }
    return 0;
}