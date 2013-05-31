// Copy from UVa 583

#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

// Square root of 2^31 is 46340.95...
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

// Euclidean Algorithm
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

long long GetPthPower(long long n)
{
    bool is_negative = false;
    if (n < 0)
    {
        is_negative = true;
        n = -n;
    }

    std::map<long long, int> factors;
    long long d = n;
    for (long long i = 0; i < 4851 && (prime[i] * prime[i] <= d); i++)
    {
        while (d % prime[i] == 0)
        {
            factors[prime[i]]++;
            d /= prime[i];
        }
    }
    if (d > 1) 
    {
        factors[d]++;
    }

    long long pth_power = -1;
    for (std::map<long long, int>::iterator it = factors.begin(); 
        it != factors.end(); it++)
    {
        if (pth_power < 0)
        {
            pth_power = it->second;
        }
        else
        {
            pth_power = gcd(pth_power, it->second);
        }
    }

    // -64 is not equal to (-8)^2 but equal to (-4)^3.
    // We should consider this case.
    if (is_negative)
    {
        while (pth_power % 2 == 0)
        {
            pth_power /= 2;
        }
    }
    return pth_power;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long n;
    while (std::cin >> n && n)
    {
        std::cout << GetPthPower(n) << std::endl;
    }
    return 0;
}