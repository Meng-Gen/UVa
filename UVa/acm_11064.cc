#include <iostream>
#include <stdio.h>
#include <string.h>

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

// Euler phi function to get the number of positive integers less than or 
// equal to n that are relatively prime to n. 
//
// Sigma 0 function, number-of-divisors function, to get the number of 
// divisors of n.
long long EulerPhiPlusSigmaFunction(long long n)
{
    long long d = n;
    long long phi = n;
    long long sigma = 1;
    for (long long i = 0; i < 4851 && (prime[i] * prime[i] <= d); i++)
    {
        if (d % prime[i] == 0)
        {
            phi /= prime[i];
            phi *= (prime[i] - 1);
        }

        long long prime_power = 0;
        while (d % prime[i] == 0)
        {
            d /= prime[i];
            prime_power++;
        }
        sigma *= (prime_power + 1);
    }

    if (d > 1) 
    {
        phi /= d;
        phi *= (d - 1);
        sigma *= 2;
    }
    return phi + sigma;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    while (std::cin >> n)
    {
        // 1 is not only relatively prime to n but also a divisor of n.
        // So we need to count 1 back.
        long long rv = n - EulerPhiPlusSigmaFunction(n) + 1;
        printf("%lld\n", rv);
    }
    return 0;
}