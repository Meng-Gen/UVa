#include <iostream>
#include <stdio.h>

long long P[77] = {};
long long Q[77] = {};

void InitQueryTable()
{
    P[1] = 1;
    Q[1] = 0;
    P[2] = 1;
    Q[2] = 1;
    for (int i = 3; i <= 76; i++)
    {
        P[i] = Q[i-1] + Q[i-2];
        Q[i] = P[i-1];
    }
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    int N;
    while (std::cin >> N)
    {
        std::cout << P[N] + Q[N] << std::endl;
    }
    return 0;
}