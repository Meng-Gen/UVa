#include <iostream>
#include <stdio.h>
#include <string.h>

int mu[1000001] = {};
int M[1000001] = {};

inline void InitMobiusFunction()
{
    mu[1] = 1; // by definition
    for (long long i = 2; i < 1000001; i++)
    {
        if (!mu[i])
        {
            for (long long j = 1; j * i < 1000001; j++)
            {
                mu[j*i]++;
            }
        }
    }

    for (long long i = 2; i < 1000001; i++)
    {
        if (mu[i] == 1)
        {
            long long square = i * i;
            for (long long j = 1; j * square < 1000001; j++)
            {
                mu[j * square] = 0;
            }
        }
    }

    for (long long i = 2; i < 1000001; i++)
    {
        if (mu[i] % 2 == 1)
        {
            mu[i] = -1;
        }
        else if (mu[i] > 0)
        {
            mu[i] = 1;
        }
    }
}

inline void InitMertensFunction()
{
    M[1] = mu[1];
    for (long long i = 2; i < 1000001; i++)
    {
        M[i] = M[i-1] + mu[i];
    }
}

int main(int argc, char* argv[])
{
    InitMobiusFunction();
    InitMertensFunction();

    int n;
    while (std::cin >> n && n)
    {
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }
    return 0;
}