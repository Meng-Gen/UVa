#include <iostream>
#include <stdio.h>

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

// -----------------------------------------------------------------------------

long long factorized[4851] = {};
long long unfactorized = 0;

void Factorize(int n)
{
    unfactorized = n;
    for (long long i = 0; i < 4851; i++)
    {
        factorized[i] = 0;
        if (unfactorized % prime[i] == 0)
        {
            do 
            {
                factorized[i]++;
                unfactorized /= prime[i];
            }
            while (unfactorized % prime[i] == 0);
        }
    }
}

long long GetFactorialFactorPower(long long factorial, long long factor)
{
    long long power = 0;
    long long d = factorial;
    while (d)
    {
        d /= factor;
        power += d;
    }
    return power;
}

bool IsDivided(long long factorial, long long n)
{
    // Reduce time from 1.502(s) to 0.789(s)
    if (factorial >= n)
    {
        return true;
    }

    Factorize(n);
    if (unfactorized > 1 && unfactorized > factorial)
    {
        return false;
    }

    for (long long i = 0; i < 4851; i++)
    {
        if (factorized[i] && 
            GetFactorialFactorPower(factorial, prime[i]) < factorized[i])
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
    
    long long n, m;
    while (std::cin >> m >> n)
    {
        if (IsDivided(m, n))
        {
            printf("%lld divides %lld!\n", n, m);
        }
        else
        {
            printf("%lld does not divide %lld!\n", n, m);
        }
    }
    return 0;
}