#include <iostream>
#include <stdio.h>
#include <string.h>

bool visited[32000] = {};
long long prime[3432] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 32000; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 32000; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

long long SigmaFunction(long long n)
{
    long long d = n;
    long long sigma = 1;
    for (long long i = 0; i < 3432 && (prime[i] * prime[i] <= d); i++)
    {
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
        sigma *= 2;
    }
    return sigma;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long L, U;
    
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> L >> U;
        long long n_with_max_count = L; 
        long long max_count = SigmaFunction(L);
        long long curr_count;
        for (long long n = L+1; n <= U; n++)
        {
            curr_count = SigmaFunction(n);
            if (curr_count > max_count)
            {
                max_count = curr_count;
                n_with_max_count = n;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", 
            L, U, n_with_max_count, max_count);
    }
    return 0;
}