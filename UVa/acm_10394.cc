#include <iostream>
#include <stdio.h>
#include <string.h>

bool prime[20000001] = {};
long twin_prime[100002] = {};

inline void InitPrimeTable()
{
    for (long i = 2; i < 20000001; i++)
    {
        prime[i] = true;
    }
    for (long i = 2; i < 20000001; i++)
    {
        if (prime[i])
        {
            for (long j = i + i; j < 20000001; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

inline void InitTwinPrimePairs()
{
    long curr_twin_pos = 1;
    for (long i = 2; i < 19999999; i++)
    {
        if (prime[i] && prime[i+2])
        {
            twin_prime[curr_twin_pos] = i;
            curr_twin_pos++;
        }
        if (curr_twin_pos > 100001)
        {
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    InitPrimeTable();
    InitTwinPrimePairs();

    long n;
    while (std::cin >> n)
    {
        printf("(%ld, %ld)\n", twin_prime[n], twin_prime[n] + 2);
    }
    return 0;
}