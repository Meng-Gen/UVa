// Idea:
// With 3 objects, A and B and C, we arrange them by the relationship "=":
//     k = 1: ABC
//     k = 2: AB|C, AC|B, A|BC
//     k = 3: A|B|C
//
// For k = 1, ABC means A = B = C
// For k = 2, AB|C means A = B < C or C < A = B
// For k = 3, A|B|C means A < B < C, A < C < B, B < A < C, 
//                        B < C < A, C < A < B, C < B < A.
//
// In general, with n objects, the answer = \sum_{k = 1 to n} S(n,k) k!
// where S(n,k) is the Stirling number of second kind.

#include <iostream>
#include <stdio.h>

long long factorial[12] = {};
long long S[12][12] = {};
long long query[12] = {};

inline void InitFactorial()
{
    factorial[0] = 1;
    for (int i = 1; i < 12; i++)
    {
        factorial[i] = factorial[i-1] * i;
    }
}

// S(0, 0) = 1. S(n, 1) = S(n, n) = 1.
// S(n, k) = k S(n-1, k) + S(n-1, k-1).
inline void InitStirlingNumbersOfSecondKind()
{
    S[0][0] = 1;
    for (int i = 1; i < 12; i++)
    {
        S[i][1] = 1;
        S[i][i] = 1;
    }
    for (int i = 1; i < 12; i++)
    {
        for (int j = 2; j < i; j++)
        {
            S[i][j] = j * S[i-1][j] + S[i-1][j-1];
        }
    }
}

inline void InitQueryTable()
{
    for (int i = 1; i < 12; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            query[i] += S[i][j] * factorial[j];
        }
    }
}

int main(int argc, char* argv[])
{
    InitFactorial();
    InitStirlingNumbersOfSecondKind();
    InitQueryTable();

    int num_testcases; 
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int n;
        std::cin >> n;   
        std::cout << query[n] << std::endl;
    }
    return 0;
}