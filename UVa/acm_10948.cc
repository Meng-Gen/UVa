#include <iostream>
#include <stdio.h>

bool visited[1000] = {};
long long prime[168] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 1000; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 1000; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

bool IsPrime(long long n)
{
    for (long long i = 0; i < 168 && (prime[i] * prime[i] <= n); i++)
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
    while (std::cin >> n && n)
    {
        printf("%lld:\n", n);
        if (n % 2 == 0)
        {
            for (long long i = 2; i <= n; i++)
            {
                if (IsPrime(i) && IsPrime(n-i))
                {
                    printf("%lld+%lld\n", i, n-i);
                    break;
                }
            }
        }
        else
        {
            if (IsPrime(n-2))
            {
                printf("2+%lld\n", n-2);
            }
            else
            {
                puts("NO WAY!");
            }
        }
    }
    return 0;
}