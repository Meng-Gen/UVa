#include <iostream>
#include <stdio.h>

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

bool visited[32001] = {};
int prime[3432] = {};

inline void InitPrimeTable()
{
    int curr_pos = 0;
    for (int i = 2; i < 32001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (int j = i + i; j < 32001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

int chain[100];

inline void PrintSolution(int lower_bound, int upper_bound)
{
    int diff = 0;
    for (int i = 0; i < 3431; i++)
    {
        if (prime[i] < lower_bound)
        {
            continue;
        }
        if (prime[i] > upper_bound)
        {
            continue;
        }
        if (prime[i+1] - prime[i] == diff)
        {
            continue;
        }
        diff = prime[i+1] - prime[i];
        if (i > 0 && prime[i] - prime[i-1] == diff)
        {
            continue;
        }

        chain[0] = prime[i];
        chain[1] = prime[i+1];
        int chain_pos = 2;
        int next = i+2;
        while (next < 3432 && prime[next] - prime[next-1] == diff)
        {
            chain[chain_pos] = prime[next];
            chain_pos++;
            next++;
        }

        if (chain[chain_pos-1] > upper_bound)
        {
            continue;
        }
        if (chain_pos <= 2)
        {
            continue;
        }
        for (int i = 0; i < chain_pos; i++)
        {
            printf("%d", chain[i]);
            if (i != chain_pos-1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitPrimeTable();
    int x, y;
    while (std::cin >> x >> y && (x || y))
    {
        PrintSolution(minimum(x, y), maximum(x, y));
    }
    return 0;
}