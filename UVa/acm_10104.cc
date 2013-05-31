#include <iostream>
#include <stdio.h>

// http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

long long last_x;
long long last_y;

void extended_gcd(long long a, long long b)
{
    long long x = 0;
    long long y = 1;
    last_x = 1;
    last_y = 0;
    
    long long quotient;
    long long temp;
    while (b)
    {
        quotient = a / b;        
    
        temp = b;
        b = a % b;
        a = temp;

        temp = x;
        x = last_x - quotient * x;
        last_x = temp;
        
        temp = y;
        y = last_y - quotient * y;
        last_y = temp;
    }
}

int main(int argc, char* argv[])
{
    long long A;
    long long B;
    while (std::cin >> A >> B)
    {
        extended_gcd(A, B);
        printf("%lld %lld %lld\n", last_x, last_y, A * last_x + B * last_y);
    }
    return 0;
}