#include <iostream>
#include <stdio.h>

bool prime_visited[225] = {};
long long prime[48] = {};
long long phi[50001] = {};
long long query[50001] = {};

inline void InitPrimeList()
{
    int curr_pos = 0;
    for (int i = 2; i < 225; i++)
    {
        if (!prime_visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (int j = i + i; j < 225; j += i)
            {
                prime_visited[j] = true;
            }
        }
    }
}

// Time complexity = O(N^{1.5} logN).
// Bottleneck.  (0.078s)
inline void InitEulerPhiFunction()
{
    // Time complexity = O(N)
    for (int i = 2; i < 50001; i++)
    {
        phi[i] = i;
        int n = i;
        
        // Time complexity = O(N^{1/2}).
        // Prime-counting function of N = O(N / logN)
        for (int j = 0; j < 48; j++)
        {
            if (n % prime[j] == 0)
            {
                phi[i] /= prime[j];
                phi[i] *= (prime[j] - 1);
            }

            // O(log N)
            while (n % prime[j] == 0)
            {
                n /= prime[j];
            }
        }
        if (n > 1) 
        {
            phi[i] /= n;
            phi[i] *= (n - 1);
        }
    }
}

inline void InitQueryTable()
{
    query[1] = 1;
    for (int i = 2; i < 50001; i++)
    {
        query[i] = query[i-1] + phi[i]*2;
    }
}

int main(int argc, char* argv[])
{
    InitPrimeList();
    InitEulerPhiFunction();
    InitQueryTable();

    long long n;
    while (std::cin >> n && n)
    {
        printf("%lld\n", query[n]);
    }
    return 0;
}