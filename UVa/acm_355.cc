#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

// -----------------------------------------------------------------------------

std::map<char, int> digit_value;
std::map<int, char> inverse_digit_value;

void InitDigitValue()
{
    for (char c = '0'; c <= '9'; c++)
    {
        digit_value[c] = c - '0';
    }
    for (char c = 'A'; c <= 'F'; c++)
    {
        digit_value[c] = 10 + c - 'A';
    }
    
    for (char c = '0'; c <= '9'; c++)
    {
        inverse_digit_value[c - '0'] = c;
    }
    for (char c = 'A'; c <= 'F'; c++)
    {
        inverse_digit_value[10 + c - 'A'] = c;
    }
}

bool IsVaild(const std::string& number, int base)
{
    for (std::string::const_iterator it = number.begin();
        it != number.end(); it++)
    {
        if (digit_value[*it] >= base)
        {
            return false;
        }
    }
    return true;
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

// Test case: 11 15 1821 
std::string ConvertToLiteral(long long number, int base)
{
    std::stringstream builder;
    long long d = number;
    while (d)
    {
        builder << inverse_digit_value[d % base];
        d /= base;
    }
    std::string rv = builder.str();
    if (rv.size() == 0)
    {
        return "0";
    }
    std::reverse(rv.begin(), rv.end());
    return rv;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitDigitValue();

    int src_base;
    int dest_base;
    std::string number;
    while (std::cin >> src_base >> dest_base >> number)
    {
        if (IsVaild(number, src_base))
        {
            long long decimal_number = ConvertToInteger(number, src_base);
            printf("%s base %d = %s base %d\n", 
                number.c_str(), 
                src_base,
                ConvertToLiteral(decimal_number, dest_base).c_str(), 
                dest_base);
        }
        else
        {
            printf("%s is an illegal base %d number\n", 
                number.c_str(), 
                src_base);
        }
    }
    
    return 0;
}