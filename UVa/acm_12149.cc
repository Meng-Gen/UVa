#include <iostream>
#include <stdio.h>

int napkin[101] = {};

int main(int argc, char* argv[])
{
    // a(n) = 1^2 + 2^2 + 3^2 + 4^2 + ... + n^2.
    for (int i = 1; i < 101; i++)
    {
        napkin[i] = napkin[i-1] + i*i;
    }

    int N;
    while (std::cin >> N && N)
    {
        std::cout << napkin[N] << std::endl;
    }
    return 0;
}