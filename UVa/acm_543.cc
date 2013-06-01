#include <iostream>
#include <stdio.h>

bool prime[1000002] = {};

inline void InitPrimeTable()
{
    for (int i = 2; i < 1000002; i++) 
    {
        prime[i] = true;
    }

    for (int i = 2; i < 1000002; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j < 1000002; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int n;
    while (std::cin >> n && n)
    {
        // If there is no such pair, print a line saying 
        // ``Goldbach's conjecture is wrong.''  
        // However, it is impossible while n is less than 10^7.
        for (int i = 3; i <= n; i += 2)
        {
            if (prime[i] && prime[n-i])
            {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }

    return 0;
}