#include <iostream>
#include <stdio.h>

bool visited[3200] = {};
long long prime[452] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 3200; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 3200; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

bool IsPrime(long long n)
{
    for (long long i = 0; i < 452 && (prime[i] * prime[i] <= n); i++)
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
        if (n < 8)
        {
            puts("Impossible.");
        }
        else 
        {
            if (n % 2 == 0)
            {
                for (long long i = 2; i <= n; i++)
                {
                    if (IsPrime(i) && IsPrime(n-4-i))
                    {
                        printf("2 2 %lld %lld\n", i, n-4-i);
                        break;
                    }
                }
            }
            else
            {
                for (long long i = 2; i <= n; i++)
                {
                    if (IsPrime(i) && IsPrime(n-5-i))
                    {
                        printf("2 3 %lld %lld\n", i, n-5-i);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}