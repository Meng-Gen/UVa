#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long N;
    while (std::cin >> N && N)
    {
        printf("%lld\n", 
            N - (long long)sqrt(double(N)) - (long long)sqrt(double(N)/2.0));
    }
    return 0;
}