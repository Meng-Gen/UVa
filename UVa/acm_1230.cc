#include <iostream>
#include <stdio.h>

long long ModPow(long long a, long long n, long long mod)
{
    long long rv = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1)
        {
            rv *= a;
            rv %= mod;
        }
        a *= a;
        a %= mod;
    }
    return rv % mod;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    
    long long x, y, n;
    while (num_testcases--)
    {
        std::cin >> x >> y >> n;
        std::cout << ModPow(x, y, n) << std::endl;
    }

    int dummy;
    std::cin >> dummy;

    return 0;
}