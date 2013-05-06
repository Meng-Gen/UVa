#include <iostream>
#include <stdio.h>

// You might get TLE if you design a naive algorithm of T(P) = O(P).
long long get_modular_pow(long long B, long long P, long long M)
{
    if (B == 0)
    {
        return 0LL;
    }

    long long rv = 1LL % M;
    long long temp = B % M;

    // T(P) = O(log P).
    for (; P > 0; P >>= 1)
    {
        if (P & 1)
        {
            rv = (rv * temp) % M;
        }
        temp = (temp * temp) % M;
    }
    
    return rv % M;
}

// R = B^P mod M
int main(int argc, char* argv[])
{
    long long B;
    long long P;
    long long M;
    while (std::cin >> B >> P >> M)
    {
        std::cout << get_modular_pow(B, P, M) << std::endl;
    }

    return 0;
}