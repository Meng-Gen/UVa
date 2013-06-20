#include <iostream>
#include <stdio.h>

// The number of ways is 
//     C(n,1) + 2 * C(n,2) + 3 * C(n,3) + ... + n * C(n, n)
//             ^^^  ^^^^^^
//      the number  the number of ways
//      of ways to  to select a team 
//      select      with N players
//      captain
//   = n * C(n-1, 0) + n * C(n-1, 1) + ... + n C(n-1, n-1)
//   = n * (C(n-1, 0) + C(n-1, 1) + ... + C(n-1, n-1))
//   = n * 2^{n-1}

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
    long long mod = 1000000007;
    long long n;
    
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> n;
        printf("Case #%d: %lld\n", case_id, (n * ModPow(2, n-1, mod)) % mod);
    }
    return 0;
}