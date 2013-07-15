#include <iostream>
#include <stdio.h>

long long query[101][6] = {};

inline void InitQueryTable()
{
    long long side = 0;
    for (long long i = 1; i < 101; i++)
    {
        side += i;
        query[i][0] = query[i-1][0] + i * i;
        query[i][1] = side * side - query[i][0];
        query[i][2] = query[i-1][2] + i * i * i;
        query[i][3] = side * side * side - query[i][2];
        query[i][4] = query[i-1][4] + i * i * i * i;
        query[i][5] = side * side * side * side - query[i][4];
    }
}

void PrintSolution()
{
    for (int i = 0; i < 6; i++)
    {
        printf("%lld", query[i]);
        putchar((i == 5) ? '\n' : ' ');
    }
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    long long N;
    while (std::cin >> N)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%lld", query[N][i]);
            putchar((i == 5) ? '\n' : ' ');
        }
    }
    return 0;
}