#include <iostream>
#include <string>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsAsciiLowerAlpha(char c) {
    return IsInRange(c, 'a', 'z');
}

int GetDigitSum(int num)
{
    int rv = 0;
    while (num > 0)
    {
        rv += (num % 10);
        num /= 10;
    }
    return rv;
}

int CalculateLoveSum(const std::string& name) 
{
    int digit_sum = 0;
    for (std::string::const_iterator it = name.begin(); it != name.end(); it++)
    {
        char c = AsciiAlphaToLower(*it);
        if (IsAsciiLowerAlpha(c))
        {
            digit_sum += (c - 'a' + 1);
        }
    }
    while (digit_sum >= 10)
    {
        digit_sum = GetDigitSum(digit_sum);
    }
    return digit_sum;
}

int main(int argc, char* argv[])
{
    std::string shanto; // problem setter
    std::string saima; // his girlfriend
    while (getline(std::cin, shanto))
    {
        getline(std::cin, saima);
        int shanto_sum = CalculateLoveSum(shanto);
        int saima_sum = CalculateLoveSum(saima);

        if (shanto_sum == saima_sum)
        {
            puts("100.00 %");
        }
        else if (shanto_sum > saima_sum)
        {
            printf("%.2lf %%\n", (double)(saima_sum)/(double)(shanto_sum) * 100.0);
        }
        else
        {
            printf("%.2lf %%\n", (double)(shanto_sum)/(double)(saima_sum) * 100.0);
        }
    }
    
    return 0;
}
