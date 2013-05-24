#include <iostream>
#include <stdio.h>
#include <string.h>

bool visited[20000001] = {};
long long prime[1270607] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 20000001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 20000001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// c = ab - (a+b)/2 + 1 = (a - 1/2)(b - 1/2) + 3/4
// So, 4c-3 = (2a-1)(2b-1).  Let x = 4c-3.  
// The answer is sigma_0(x) = sigma_0(p_1^{a_1} * p_2^{a_2} * ...
//                          = (a_1 + 1) * (a_2 + 1) * ...
// (Reference: http://mathworld.wolfram.com/DivisorFunction.html)
//
// I want to know any fast algorithm to calcuate sigma_0(x).
// Time: 4.019s (bottleneck)
long long Count(long long n)
{
    long long d = 4 * n - 3;
    long long rv = 1;
    for (long long i = 0; i < 1270607 && (prime[i] * prime[i] <= d); i++)
    {
        long long prime_power = 0;
        while (d % prime[i] == 0)
        {
            d /= prime[i];
            prime_power++;
        }
        rv *= (prime_power + 1);
    }

    if (d > 1) 
    {
        rv *= 2;
    }
    return rv;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    while (std::cin >> n && n)
    {
        printf("%lld %lld\n", n, Count(n));
    }
    return 0;
}