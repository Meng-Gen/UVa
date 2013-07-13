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

long long GetMinPrimeDivisor(long long n)
{
    for (long long i = 0; i < 168 && (prime[i]*prime[i] <= n); i++)
    {
        if (n % prime[i] == 0)
        {
            return prime[i];
        }
    }
    return n;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    long long next;
    while (std::cin >> n)
    {
        // WA. 100 => 160 but I gave 200
        next = n * GetMinPrimeDivisor(n);
        if (next < 2000000LL)
        {
            std::cout << next << std::endl;
        }
        else
        {
            puts("Not Exist!");
        }
    }
    return 0;
}