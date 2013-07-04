#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    // Sigma function is multiplicative, i.e.,
    //     S(n) = S(p_1^{a_1} * ... * p_r^{a_r}) 
    //          = S(p_1^{a_1}) * ... * S(p_r^{a_r})
    //
    // Also, S(p^a) = (1 + p + p^2 + ... + p^a + p^{a+1}).
    // S(p^a) is odd <=> p = 2 or a is even (p^a is a square).
    // So, S(n) is odd <=> all S(p_i^{a_i}) is odd
    //                 <=> n = m^2 or n = 2 * m^2.
    // 
    // Therefore, the answer = N - #{ S(n) is odd : 1 <= n <= N }
    //                       = N - #{ m^2 : 1 <= m^2 <= N }
    //                           - #{ 2*m^2 : 1 <= 2*m^2 <= N }.
    long long N;
    while (std::cin >> N && N)
    {
        printf("%lld\n", 
            N - (long long)sqrt(double(N)) - (long long)sqrt(double(N)/2.0));
    }
    return 0;
}