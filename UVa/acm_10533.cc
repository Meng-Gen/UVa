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

inline int GetDigitSum(int number)
{
    int sum = 0;
    while (number)
    {
        sum += (number % 10);
        number /= 10;
    }
    return sum;
}

void InitQueryTable()
{
    InitPrimeTable();

    for (int i = 2; i < 1000001; i++) 
    {
        query[i] = query[i-1];
        if (prime[i] && prime[GetDigitSum(i)])
        {
            query[i]++;
        }
    }
}

// -----------------------------------------------------------------------------
// Problem quote: 
//     You should at least use scanf() and printf() to take input and 
//     produce output for this problem. cin and cout is too slow for 
//     this problem to get it within time limit.
// 
// Hmmm...

int main(int argc, char* argv[])
{
    InitQueryTable();

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        int lower_bound, upper_bound;
        std::cin >> lower_bound >> upper_bound;
        std::cout << query[upper_bound] - query[lower_bound - 1] << std::endl;
    }
    return 0;
}