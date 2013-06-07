#include <iostream>
#include <stdio.h>
#include <stdlib.h>

char grid[2000][2000] = {};
int M;

inline int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int Distance(int x, int y)
{
    int rv = 5000;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '3')
            {
                rv = minimum(rv, abs(i - x) + abs(j - y));
            }
        }
    }

    return rv;
}

int main(int argc, char* argv[]) 
{
    while (std::cin >> M)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                std::cin >> grid[i][j];
            }
        }

        int diameter = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == '1')
                {
                    diameter = maximum(diameter, Distance(i, j));
                }
            }
        }

        printf("%d\n", diameter);
    }
    return 0;
}