#include <iostream>
#include <stdio.h>
#include <string.h>

bool h_prime[1000003];
bool h_semiprime[1000003] = {};
int query[1000003] = {};

inline void InitHilbertPrime()
{
    memset(h_prime, true, 1000003);
    h_prime[1] = false;
    for (long long i = 5; i < 1000003; i += 4)
    {
        if (h_prime[i])
        {
            for (long long j = 5; j * i < 1000003; j += 4)
            {
                h_prime[j * i] = false;
            }
        }
    }
}

inline void InitHilbertSemiprime()
{
    for (long long i = 5; i < 1000003; i += 4)
    {
        if (h_prime[i])
        {
            for (long long j = i; j * i < 1000003; j += 4)
            {
                if (h_prime[j])
                {
                    h_semiprime[i * j] = true;
                }
            }
        }
    }
}

// Make each query in O(1) time. 
inline void InitQueryTable()
{
    query[0] = 0;
    for (long long i = 1; i < 1000003; i++)
    {
        query[i] = query[i-1];
        if (h_semiprime[i])
        {
            query[i]++;
        }
    }
}   

int main(int argc, char* argv[])
{
    InitHilbertPrime();
    InitHilbertSemiprime();
    InitQueryTable();

    int n;
    while (std::cin >> n && n)
    {
        printf("%d %d\n", n, query[n]);
    }
    return 0;
}
