#include <iostream>
#include <stdio.h>

#define MAGIC_EPSILON (1e-7)

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

// -----------------------------------------------------------------------------

int query[10001] = {};

void InitQueryTable()
{
    for (long long n = 0; n < 40; n++)
    {
        query[n] = n + 1;
    }
    query[40] = 40;

    for (long long n = 41; n < 10001; n++)
    {
        query[n] = query[n-1];
        long long x = n * n + n + 41;
        if (IsPrime(x))
        {
            query[n]++;
        }
    }
}

int main(int argc, char* argv[])
{
    InitPrimeTable();
    InitQueryTable();

    long long a, b;
    while (std::cin >> a >> b)
    {
        double ratio;
        if (a)
        {
            ratio = (double)(query[b] - query[a-1]) / 
                (double)(b - a + 1) * 100.0;
        }
        else
        {
            ratio = (double)(query[b]) / (double)(b - a + 1) * 100.0;
        }
        printf("%.2lf\n", ratio + MAGIC_EPSILON);
    }
    return 0;
}