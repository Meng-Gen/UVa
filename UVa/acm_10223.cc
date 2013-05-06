#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

// C(20) = 6564120420 > 4294967295
// C(19) = 1767263190 < 4294967295
long long catalan_number[21] = {}; 

int main(int argc, char* argv[])
{
    // C(0) = 1. 
    // C(n+1) = \sum_{i=0}^{n} C(i)*C(n-i)
    catalan_number[0] = 1;
    for (int i = 1; i < 21; i++)
    {
        for (int j = 0; j < i; j++)
        {
            catalan_number[i] += catalan_number[j] * catalan_number[i-1-j];
        }
    }

    std::map<long long, int> inverse_catalan_number;
    for (int i = 1; i < 21; i++)
    {
        inverse_catalan_number[catalan_number[i]] = i;
    }

    int n;
    while (std::cin >> n)
    {
        std::cout << inverse_catalan_number[n] << std::endl;
    }

    return 0;
}