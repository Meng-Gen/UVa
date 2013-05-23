#include <iostream>
#include <stdio.h>

// Suppose a = p_1^{a_1} * p_2^{a_2} * ... * p_n^{a_n} where p_i is prime.
//         b = p_1^{b_1} * p_2^{b_2} * ... * p_n^{b_n}
//
// Then gcd(a,b) = p_1^{min(a_1, b_1)} * ... * p_n^{min(a_n, b_n)}
//      lcm(a,b) = p_1^{max(a_1, b_1)} * ... * p_n^{max(a_n, b_n)}
//
// To output the pair for which a is minimized, we simply choose a = gcd.
// Surely, lcm | gcd.

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++)
    {
        long long gcd;
        long long lcm;
        std::cin >> gcd >> lcm;

        if (lcm % gcd == 0)
        {
            printf("%lld %lld\n", gcd, lcm);
        }
        else
        {
            puts("-1");
        }
    }

    return 0;
}