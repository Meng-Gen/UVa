#include <iostream>
#include <stdio.h>
#include <string.h>

bool prime[1000001] = {};

inline void InitPrimeTable()
{
    for (int i = 2; i < 1000001; i++) 
    {
        prime[i] = true;
    }

    for (int i = 2; i < 1000001; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j < 1000001; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

// -----------------------------------------------------------------------------

int query[1000001] = {};

inline int GetDigitCount(int number)
{
    if (number < 10)
    {
        return 1;
    }
    if (number < 100)
    {
        return 2;
    }
    if (number < 1000)
    {
        return 3;
    }
    if (number < 10000)
    {
        return 4;
    }
    if (number < 100000)
    {
        return 5;
    }
    return 6;
}

inline int GetNextCircularNumber(int number)
{
    if (number < 10)
    {
        return number;
    }
    if (number < 100)
    {
        return number / 10 + (number % 10) * 10;
    }
    if (number < 1000)
    {
        return number / 10 + (number % 10) * 100;
    }
    if (number < 10000)
    {
        return number / 10 + (number % 10) * 1000;
    }
    if (number < 100000)
    {
        return number / 10 + (number % 10) * 10000;
    }
    return number / 10 + (number % 10) * 100000;
}

void InitQueryTable()
{
    InitPrimeTable();

    for (int i = 2; i < 1000001; i++) 
    {
        int d = i;
        bool is_circular_prime = true;
        int digit_count = GetDigitCount(i);
        for (int i = 0; i < digit_count; i++)
        {
            if (!prime[d]) 
            {
                is_circular_prime = false;
                break;
            }
            d = GetNextCircularNumber(d);
        }

        query[i] = query[i-1];
        if (is_circular_prime)
        {
            query[i]++;
        }
    }
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    int lower_bound = 0;
    int upper_bound = 0;
    while (std::cin >> lower_bound && (lower_bound != -1))
    {
        std::cin >> upper_bound;
        int count = query[upper_bound] - query[lower_bound - 1];
        if (count == 0)
        {
            puts("No Circular Primes.");
        }
        else if (count == 1)
        {
            puts("1 Circular Prime.");
        }
        else
        {
            printf("%d Circular Primes.\n", count);
        }
    }
    return 0;
}