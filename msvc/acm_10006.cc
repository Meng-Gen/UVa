#include <iostream>
#include <stdio.h>
#include <string.h>

bool prime[65001] = {};

inline void InitPrimeTable()
{
    for (int i = 2; i < 65001; i++) 
    {
        prime[i] = true;
    }

    for (int i = 2; i < 65001; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j < 65001; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

long long ModPow(long long a, long long n, long long mod)
{
    long long rv = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1)
        {
            rv *= a;
            rv %= mod;
        }
        a *= a;
        a %= mod;
    }
    return rv % mod;
}

// Or hack:
// 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 
// 46657, 52633, 62745, 63973
bool HasPassedTest(long long n)
{
    for (int a = 2; a < n; a++)
    {
        if (ModPow(a, n, n) != a) 
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
        if (prime[n]) 
        {
            printf("%lld is normal.\n", n);
        }
        else if (HasPassedTest(n))
        {
            printf("The number %lld is a Carmichael number.\n", n);
        }
        else
        {
            printf("%lld is normal.\n", n);
        }
    }
    return 0;
}