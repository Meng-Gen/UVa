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

bool IsPrime(long long n)
{
    for (long long i = 0; i < 4851 && (prime[i] * prime[i] <= n); i++)
    {
        if (n == prime[i])
        {
            return true;
        }
        if (n % prime[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    long long L, U;
    while (std::cin >> L >> U)
    {
        long long prev_prime = -1;
        
        long long max_distance = 0;
        long long max_distance_pair[2] = {};
        long long min_distance = U - L + 1;
        long long min_distance_pair[2] = {};
        long long curr_distance;

        if (L <= 2)
        {
            prev_prime = 2;
            L = 3;
        }
        if (L % 2 == 0)
        {
            L++;
        }
        for (long long n = L; n <= U; n += 2)
        {
            if (!IsPrime(n))
            {
                continue;
            }
            if (prev_prime < 0)
            {
                prev_prime = n;
                continue;
            }
            curr_distance = n - prev_prime;
            if (curr_distance > max_distance)
            {
                max_distance = curr_distance;
                max_distance_pair[0] = prev_prime;
                max_distance_pair[1] = n;
            }
            if (curr_distance < min_distance)
            {
                min_distance = curr_distance;
                min_distance_pair[0] = prev_prime;
                min_distance_pair[1] = n;
            }
            prev_prime = n;
        }

        if (max_distance == 0)
        {
            puts("There are no adjacent primes.");
        }
        else
        {
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
                min_distance_pair[0],
                min_distance_pair[1],
                max_distance_pair[0],
                max_distance_pair[1]);
        }
    }
    return 0;
}