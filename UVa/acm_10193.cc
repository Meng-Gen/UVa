#include <iostream>
#include <string>
#include <stdio.h>

// Euclidean Algorithm
long long GetGCD(long long a, long long b) 
{
    while (b) 
    {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

long long ConvertToBase10(const std::string& base2)
{
    long long rv = 0;
    for (int i = 0; i < base2.size(); i++)
    {
        rv *= 2;
        rv += base2[i] - '0';
    }
    return rv;
}

int main(int argc, char* argv[])
{
    std::string S1, S2;
    long long N1, N2;
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> S1 >> S2;
        N1 = ConvertToBase10(S1);
        N2 = ConvertToBase10(S2);
        if (GetGCD(N1, N2) == 1)
        {
            printf("Pair #%d: Love is not all you need!\n", case_id);
        }
        else
        {
            printf("Pair #%d: All you need is love!\n", case_id);
        }
    }
    return 0;
}