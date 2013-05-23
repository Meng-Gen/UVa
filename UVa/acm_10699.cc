#include <iostream>
#include <stdio.h>
#include <string.h>

int query[1000001] = {};

inline void InitQueryTable()
{
    for (long long i = 2; i < 1000001; i++)
    {
        if (!query[i])
        {
            for (long long j = 1; j * i < 1000001; j++)
            {
                query[j * i]++;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    int n;
    while (std::cin >> n && n)
    {
        printf("%d : %d\n", n, query[n]);
    }
    return 0;
}