#include <iostream>
#include <string>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int GetMinBase(const std::string& number)
{
    int min_base = 1;
    bool has_zero_digit = false;
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        int digit = *it - '0';
        if (digit == 0)
        {
            has_zero_digit = true;
        }
        min_base = maximum(digit, min_base);
    }

    if (min_base == 1 && !has_zero_digit)
    {
        return 1;
    }
    return min_base + 1;
}

int ConvertToInteger(const std::string& number, int base)
{
    int rv = 0;
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        rv *= base;
        rv += *it - '0';
    }
    return rv;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;

    std::string a, b, c;
    char op; // + =
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        std::cin >> a >> op >> b >> op >> c;

        int min_base = maximum(GetMinBase(a), GetMinBase(b));
        min_base = maximum(min_base, GetMinBase(c));

        bool has_base = false;
        int base = min_base;
        for (; base <= 18; base++)
        {
            int operand[3] = 
            {
                ConvertToInteger(a, base),
                ConvertToInteger(b, base),
                ConvertToInteger(c, base),
            };
            if (operand[0] + operand[1] == operand[2])
            {
                has_base = true;
                break;
            }
        }

        if (has_base)
        {
            printf("%d\n", base);
        }
        else
        {
            puts("0");
        }
    }
    
    return 0;
}