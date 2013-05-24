#include <iostream>
#include <stdio.h>
#include <string.h>

bool visited[1001] = {};
long long prime[168] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 1001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 1001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

inline long long absolute(long long n)
{
    return (n >= 0) ? n : -n;
}

// m/x + n/y = 1/p => (x - pm)(y - pn) = mnp^2.  
// Note that (x, y) = (0, 0) is not a solution of m/x + n/y = 1/p
// because we don't like dividing by zero.
long long Count(long long m, long long n, long long p)
{
    long long d = absolute(m * n * p * p);
    long long rv = 1;
    for (long long i = 0; i < 168; i++)
    {
        long long prime_power = 0;
        while (d % prime[i] == 0)
        {
            d /= prime[i];
            prime_power++;
        }
        rv *= (prime_power + 1);
    }

    rv = rv * 2 - 1;
    return rv;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long m;
    long long n;
    long long p;
    int case_id = 1;
    while (std::cin >> m >> n >> p)
    {
        if (m == 0 || n == 0 || p == 0)
        {
            break;
        }
        printf("Case %d: %lld\n", case_id, Count(m, n, p));
        case_id++;
    }
    return 0;
}