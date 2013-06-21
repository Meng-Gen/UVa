#include <iostream>
#include <stdio.h>

bool visited[10000002] = {};
long long prime[664579] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 10000002; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 10000002; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

long long prime_factor[20];

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    long long d;
    while (std::cin >> n && n)
    {
        d = (n < 0) ? -n : n;
        if (d == 1)
        {
            puts("-1");
            continue;
        }
        int prime_factor_pos = 0;
        for (long long i = 0; i < 664579 && (prime[i] * prime[i] <= d); i++)
        {
            if (d % prime[i] == 0)
            {
                prime_factor[prime_factor_pos] = prime[i];
                prime_factor_pos++;
                do
                {
                    d /= prime[i];
                }
                while (d % prime[i] == 0);
            }
        }
        if (d > 1)
        {
            prime_factor[prime_factor_pos] = d;
            prime_factor_pos++;
        }
        if (prime_factor_pos < 2)
        {
            puts("-1");
        }
        else
        {
            printf("%lld\n", prime_factor[prime_factor_pos - 1]);
        }
    }

    return 0;
}