// Mathematics :: Ad Hoc Mathematics Problems :: Finding Pattern or Formula
#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long N;
    while (std::cin >> N)
    {
        long long rv = 6 * ((N+1)/2) * ((N+1)/2) - 9;
        std::cout << rv << std::endl;
    }
    return 0;
}