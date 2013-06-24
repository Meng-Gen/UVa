#include <iostream>
#include <stdio.h>

long long GetDigitSum(long long num) {
    long long rv = 0;
    while (num > 0) {
        rv += (num % 10);
        num /= 10;
    }
    return rv;
}

// -----------------------------------------------------------------------------

bool visited[32000] = {};
long long prime[3432] = {};
long long prime_digit_sum[3432] = {};

inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 32000; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            prime_digit_sum[curr_pos] = GetDigitSum(i);
            curr_pos++;
            for (long long j = i + i; j < 32000; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

long long PrimeFactorsDigitSum(long long n)
{
    long long rv = 0;
    long long d = n;
    for (long long i = 0; i < 3432 && (prime[i] * prime[i] <= d); i++)
    {
        // exclude prime number
        if (n == prime[i])
        {
            return 0;
        }
        while (d % prime[i] == 0) 
        {
            rv += prime_digit_sum[i];
            d /= prime[i];
        }
    }
    // exclude prime number
    if (d == n)
    {
        return 0;
    }
    if (d > 1)
    {
        rv += GetDigitSum(d);
    }
    return rv;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        long long n;
        std::cin >> n;
        while (1)
        {
            n++;
            if (PrimeFactorsDigitSum(n) == GetDigitSum(n))
            {
                printf("%lld\n", n);
                break;
            }
        }
    }
    return 0;
}