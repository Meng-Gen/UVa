#include <iostream>
#include <stdio.h>

inline long long norm(long long n)
{
    return (n < 0) ? -n : n;
}

// -----------------------------------------------------------------------------

bool visited[101] = {};
int prime[25] = {};

inline void InitPrimeTable()
{
    int curr_pos = 0;
    for (int i = 2; i < 101; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (int j = i + i; j < 101; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

int factorial[101][25] = {};

inline void InitFactorizationTable()
{
    InitPrimeTable();
    for (int n = 2; n <= 100; n++)
    {
        int d = n;
        for (int i = 0; i < 25; i++)
        {
            factorial[n][i] = factorial[n-1][i];
            if (d % prime[i] == 0)
            {
                do 
                {
                    factorial[n][i]++;
                    d /= prime[i];
                }
                while (d % prime[i] == 0);
            }
        }
    }
}

// -----------------------------------------------------------------------------

int factorized[25] = {};
long long unfactorized = 0;

void Factorize(long long n)
{
    unfactorized = n;
    for (int i = 0; i < 25; i++)
    {
        factorized[i] = 0;
        if (unfactorized % prime[i] == 0)
        {
            do 
            {
                factorized[i]++;
                unfactorized /= prime[i];
            }
            while (unfactorized % prime[i] == 0);
        }
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitFactorizationTable();
    
    int n;
    long long d;
    while (std::cin >> n >> d && (n || d))
    {
        Factorize(norm(d));
        if (unfactorized > 1)
        {
            puts("0");
            continue;
        }
        
        long long num_divisors = 1;
        for (int i = 0; i < 25; i++)
        {
            int diff = factorial[n][i] - factorized[i];
            if (diff < 0)
            {
                num_divisors = 0;
                break;
            }
            num_divisors *= (diff + 1);
        }
        printf("%lld\n", num_divisors);
    }
    return 0;
}