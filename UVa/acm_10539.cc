#include <iostream>
#include <stdio.h>

bool visited[1000002] = {};
long long prime[78498] = {};
inline void InitPrimeTable()
{
    long long curr_pos = 0;
    for (long long i = 2; i < 1000002; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long long j = i + i; j < 1000002; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

int Query(long long bound)
{
    long long count = 0;

    for (long long i = 0; i < 78498 && (prime[i] * prime[i] <= bound); i++)
    {
        long long next = prime[i] * prime[i];
        while (next <= bound)
        {
            count++;
            next *= prime[i];
        }
    }

    return count;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        long long lower_bound, upper_bound;
        std::cin >> lower_bound >> upper_bound;
        printf("%d\n", Query(upper_bound) - Query(lower_bound - 1));
    }

    return 0;
}