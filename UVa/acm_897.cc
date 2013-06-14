#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

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

template <class T>
inline std::string to_string(const T& t)
{
    std::stringstream builder;
    builder << t;
    return builder.str();
}

template <class T>
inline T to_type(const std::string& s)
{
    std::stringstream builder(s);
    T t;
    builder >> t;
    return t;
}

bool IsAnagrammaticPrime(long long n)
{
    if (!IsPrime(n))
    {
        return false;
    }
    std::string n_literal = to_string(n);
    std::sort(n_literal.begin(), n_literal.end());

    do
    {
        long long n_permutation = to_type<long long>(n_literal);
        if (!IsPrime(n_permutation))
        {
            return false;
        }
    }
    while (std::next_permutation(n_literal.begin(), n_literal.end()));

    return true;
}

// Loop from 2 to 10000000.  We can find 22 anagrammatic primes in this range.
long long anagrammatic_prime[22] = 
{
    2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 
    73, 79, 97, 113, 131, 199, 311, 337, 373, 733,
    919, 991
};

bool IsAnagrammaticPrimeFast(long long n)
{
    for (int i = 0; i < 22; i++)
    {
        if (n == anagrammatic_prime[i])
        {
            return true;
        }
    }
    return false;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    long long n;
    while (std::cin >> n && n)
    {
        if (n > 991)
        {
            puts("0");
            continue;
        }

        long long upper_limit = 0;
        if (n < 10)
        {
            upper_limit = 10;
        }
        else if (n < 100)
        {
            upper_limit = 100;
        }
        else if (n < 1000)
        {
            upper_limit = 1000;
        }

        bool found = false;
        for (long long i = n+1; i < upper_limit; i++)
        {
            if (IsAnagrammaticPrimeFast(i))
            {
                printf("%lld\n", i);
                found = true;
                break;
            }
        }

        if (!found)
        {
            puts("0");
        }
    }
    return 0;
}