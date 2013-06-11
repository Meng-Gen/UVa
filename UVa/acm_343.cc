#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

std::map<char, int> digit_value;

void InitDigitValue()
{
    for (char c = '0'; c <= '9'; c++)
    {
        digit_value[c] = c - '0';
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        digit_value[c] = 10 + c - 'A';
    }
}

long long ConvertToInteger(const std::string& number, int base)
{
    long long rv = 0;
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        rv *= base;
        rv += digit_value[*it];
    }
    return rv;
}

int GetMinBase(const std::string& number)
{
    int max_digit = 1;
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        max_digit = maximum(digit_value[*it], max_digit);
    }
    return max_digit + 1;
}

// -----------------------------------------------------------------------------

std::string a, b;
int base_a, base_b;

bool BuildGoodBases()
{
    for (int i = GetMinBase(a); i <= 36; i++)
    {
        for (int j = GetMinBase(b); j <= 36; j++)
        {
            if (ConvertToInteger(a, i) == ConvertToInteger(b, j))
            {
                base_a = i;
                base_b = j;
                return true;
            }
        }
    }
    return false;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitDigitValue();

    while (std::cin >> a >> b)
    {
        if (BuildGoodBases())
        {
            printf("%s (base %d) = %s (base %d)\n", 
                a.c_str(), base_a, b.c_str(), base_b);
        }
        else
        {
            printf("%s is not equal to %s in any base 2..36\n",
                a.c_str(), b.c_str());
        }
    }
    
    return 0;
}