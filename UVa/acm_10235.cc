#include <iostream>
#include <stdio.h>
#include <string.h>

bool prime[1000001] = {};

void InitPrimeTable()
{
    memset(prime, 1, 1000001);
    for (int i = 2; i < 1000001; i++)
    {
        if (prime[i])
        {
            for (int j = 2; j * i < 1000001; j++)
            {
                prime[j*i] = false;
            }
        }
    }
}

int ReversedInt(int n)
{
    int rv = 0;
    while (n > 0)
    {
        rv *= 10;
        rv += (n % 10);
        n /= 10;
    }
    return rv;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();
    int N;
    while (std::cin >> N)
    {
        if (!prime[N])
        {
            printf("%d is not prime.\n", N);
        }
        else 
        {
            // Test case: 2, 3, 5, 7, 11, 131
            int reversed_N = ReversedInt(N);
            if (!prime[reversed_N] || reversed_N == N)
            {
                printf("%d is prime.\n", N);
            }
            else
            {
                printf("%d is emirp.\n", N);
            }
        }
    }
    return 0;
}