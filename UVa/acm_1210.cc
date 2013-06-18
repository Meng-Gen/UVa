#include <iostream>
#include <stdio.h>
#include <string.h>

bool visited[10001] = {};
int prime[1229] = {};

inline void InitPrimeTable()
{
    int curr_pos = 0;
    for (int i = 2; i < 10001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long j = i + i; j < 10001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

int prime_sum[1230] = {};
int query[10001] = {};

inline void InitQueryTable()
{
    InitPrimeTable();

    // To get the sum of consecutive primes, we can precalculate
    //     S(0) = p(0)
    //     S(1) = p(0) + p(1)
    //     S(2) = p(0) + p(1) + p(2)
    //     ...
    //     S(n) = p(0) + p(1) + p(2) + ... + p(n-1) + p(n)
    // So, p(m) + p(m+1) + ... + p(n) = S(n) - S(m-1)
    //
    // Note that sum of all primes <= 10000 can be stored 
    // in the C++ native int data type.  
    //
    // Surely we can use |long long| or other data type.
    prime_sum[0] = 0;
    for (int i = 1; i < 1230; i++)
    {
        prime_sum[i] = prime_sum[i-1] + prime[i-1];
    }

    for (int i = 0; i < 1230; i++)
    {
        for (int j = i+1; j < 1230; j++)
        {
            int sum = prime_sum[j] - prime_sum[i];
            if (sum < 10001)
            {
                query[sum]++;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    int n;
    while (std::cin >> n && n)
    {
        std::cout << query[n] << std::endl;
    }
    return 0;
}