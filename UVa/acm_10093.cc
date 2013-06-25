#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

// -----------------------------------------------------------------------------

std::map<char, int> digit_value;

inline void InitDigitValue()
{
    for (int i = 0; i <= 9; i++)
    {
        digit_value['0' + i] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        digit_value['A' + i] = 10 + i;
        digit_value['a' + i] = 36 + i;
    }
}

int GetMinBase(const std::string& number)
{
    int min_base = 1;
    bool has_zero_digit = false;
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        if (*it == '+' || *it == '-')
        {
            continue;
        }
        int digit = digit_value[*it];
        if (digit == 0)
        {
            has_zero_digit = true;
        }
        min_base = maximum(digit, min_base);
    }

    return min_base + 1;
}

int GetDigitSum(const std::string& number, int base)
{
    int rv = 0;
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        if (*it == '+' || *it == '-')
        {
            continue;
        }
        rv += digit_value[*it];
    }
    return rv;
}

int main(int argc, char* argv[])
{
    InitDigitValue();

    std::string number;
    while (std::cin >> number)
    {
        int smallest_possible_base = 0;
        int digit_sum;
        for (int base = GetMinBase(number); base <= 62; base++)
        {
            digit_sum = GetDigitSum(number, base);
            if (digit_sum == 0 || digit_sum % (base-1) == 0)
            {
                smallest_possible_base = base;
                break;
            }
        }

        if (smallest_possible_base)
        {
            printf("%d\n", smallest_possible_base);
        }
        else
        {
            puts("such number is impossible!");
        }
    }
    
    return 0;
}