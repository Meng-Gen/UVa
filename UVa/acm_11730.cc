#include <iostream>
#include <queue>
#include <stdio.h>

#define INFINITY_WEIGHT (999)

inline int minimum(int a, int b) 
{
    return (a < b) ? a : b;
}

int sieve_visited[1001] = {};
int query[1001][1001] = {};

inline void InitQueryTable()
{
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (i != j)
            {
                query[i][j] = INFINITY_WEIGHT;
            }
            else 
            {
                query[i][j] = 0;
            }
        }
    }

    for (int i = 2; i < 1001; i++)
    {
        if (!sieve_visited[i]) 
        {
            for (int j = i + i; j < 1001; j += i)
            {
                query[j][j+i] = 1;
                sieve_visited[j] = true;
            }
        }
    }

    // Super slow (0.745s)
    for (int k = 2; k < 1001; k++)
    {
        for (int i = 2; i < 1001; i++)
        {
            for (int j = i+1; j < 1001; j++)
            {
                if (k < j && k > i)
                {
                    query[i][j] = minimum(
                        query[i][j], query[i][k] + query[k][j]);
                }
            }
        }
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitQueryTable();
    
    int case_id = 1;
    int S, T;
    while (std::cin >> S >> T && (S || T))
    {
        if (query[S][T] != INFINITY_WEIGHT)
        {
            printf("Case %d: %d\n", case_id, query[S][T]);
        }
        else
        {
            printf("Case %d: -1\n", case_id);
        }
        case_id++;
    }

    return 0;
}