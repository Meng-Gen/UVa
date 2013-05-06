#include <iostream>
#include <string>
#include <stdio.h>

// Hack: initialize with { 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796 }.
int catalan_number[11] = {}; 

int main(int argc, char* argv[])
{
    // C(0) = 1. 
    // C(n+1) = \sum_{i=0}^{n} C(i)*C(n-i)
    catalan_number[0] = 1;
    for (int i = 1; i < 11; i++)
    {
        for (int j = 0; j < i; j++)
        {
            catalan_number[i] += catalan_number[j] * catalan_number[i-1-j];
        }
    }

    bool is_first_dataset = true;
    int n;
    while (std::cin >> n)
    {
        if (!is_first_dataset)
        {
            std::cout << std::endl;
        }
        else
        {
            is_first_dataset = false;
        }

        std::cout << catalan_number[n] << std::endl;
    }

    return 0;
}