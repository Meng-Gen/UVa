#include <iostream>
#include <stdio.h>

// Chebyshev Polynomials:
//     T_0(x) = 1
//     T_1(x) = x
//     T_n(x) = 2x T_{n-1}(x) - T_n(x)
// Why? 
//     cos((n+1)x) = cos(nx + x) = cos(nx) cos(x) - sin(nx) sin(x)
//     cos((n-1)x) = cos(nx - x) = cos(nx) cos(x) + sin(nx) sin(x)
// Sum them up: cos((n+1)x) + cos((n-1)x) = 2 cos(nx) cos(x)
// So T_{n+1}(x) + T_{n-1}(x) = 2x T_n(x).
//    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

long long T[51][51] = {};

void InitChebyshevPolynomialsOfFirstKind()
{
    T[0][0] = 1;
    T[1][1] = 1;
    for (int i = 2; i < 51; i++)
    {
        for (int j = 50; j >= 1; j--)
        {
            T[i][j] += 2 * T[i-1][j-1];
        }

        for (int j = 50; j >= 0; j--)
        {
            T[i][j] -= T[i-2][j];
        }
    }
}

inline void PrintLeadingTerm(long long c, int n)
{
    if (n == 0)
    {
        printf("%lld", c);
    }
    else if (n == 1)
    {
        if (c == 1)
        {
            printf("Cos(A)");
        }
        else
        {
            printf("%lldCos(A)", c);
        }
    }
    else
    {
        if (c == 1)
        {
            printf("Cos^%d(A)", n);
        }
        else
        {
            printf("%lldCos^%d(A)", c, n);
        }
    }
}

inline void PrintNonLeadingTerm(long long c, int n)
{
    if (c == 0)
    {
        return;
    }
    else if (c > 0)
    {
        printf("+");
    }
    else 
    {
        c = -c;
        printf("-");
    }
    
    if (n == 0)
    {
        printf("%lld", c);
    }
    else if (n == 1)
    {
        if (c == 1)
        {
            printf("Cos(A)");
        }
        else
        {
            printf("%lldCos(A)", c);
        }
    }
    else
    {
        if (c == 1)
        {
            printf("Cos^%d(A)", n);
        }
        else
        {
            printf("%lldCos^%d(A)", c, n);
        }
    }
}

void PrintCosNA(int N)
{
    PrintLeadingTerm(T[N][N], N);
    for (int i = N - 1; i >= 0; i--)
    {
        PrintNonLeadingTerm(T[N][i], i);
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    InitChebyshevPolynomialsOfFirstKind();

    int N;
    while (std::cin >> N && N)
    {
        PrintCosNA(N);
    }
    return 0;
}