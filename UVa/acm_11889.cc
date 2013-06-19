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

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int num_testcases;
    std::cin >> num_testcases;

    long long A, B, C; // Find minimum B such that LCM(A, B) = C
    while (num_testcases--)
    {
        std::cin >> A >> C;
        if (C % A)
        {
            puts("NO SOLUTION");
            continue;
        }

        B = 1;
        long long d = C;
        for (long long i = 0; i < 452 && (prime[i] * prime[i] <= d); i++)
        {
            long long almost_prime = 1;
            if (d % prime[i] == 0)
            {
                do 
                {
                    almost_prime *= prime[i];
                    d /= prime[i];
                }
                while (d % prime[i] == 0);
            }

            if (A % almost_prime)
            {
                B *= almost_prime;
            }
        }
        if (d > 1)
        {
            if (A % d)
            {
                B *= d;
            }
        }
        printf("%lld\n", B);
    }
    return 0;
}