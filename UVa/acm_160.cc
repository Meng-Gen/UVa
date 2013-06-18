#include <iostream>
#include <stdio.h>

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

int factorization[101][25] = {};

inline void InitFactorizationTable()
{
    InitPrimeTable();
    for (int n = 2; n <= 100; n++)
    {
        int d = n;
        for (int i = 0; i < 25; i++)
        {
            factorization[n][i] = factorization[n-1][i];
            if (d % prime[i] == 0)
            {
                do 
                {
                    factorization[n][i]++;
                    d /= prime[i];
                }
                while (d % prime[i] == 0);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitFactorizationTable();
    
    int n;
    while (std::cin >> n && n)
    {
        printf("%3d! =", n);
        for (int i = 0; i < 15; i++)
        {
            if (factorization[n][i])
            {
                printf("%3d", factorization[n][i]);
            }
        }
        for (int i = 15; i < 25; i++)
        {
            if (factorization[n][i])
            {
                if (i == 15)
                {
                    printf("\n      ");
                }
                printf("%3d", factorization[n][i]);
            }        
        }
        putchar('\n');
    }
    return 0;
}