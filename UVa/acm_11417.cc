#include <iostream>
#include <stdio.h>

// Euclidean Algorithm
long long gcd(long long a, long long b)
{
    while (b)
    {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

long long G(long long N)
{
    long long rv = 0;
    for (int i = 1; i < N; i++)
    {
        for(int j = i+1; j <= N; j++)
        {
            rv += gcd(i,j);
        }
    }
    return rv;
}

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n && n)
    {
        std::cout << G(n) << std::endl;
    }
    return 0;
}