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

    std::string number;
    int src_base;
    int dest_base;
    while (std::cin >> number >> src_base >> dest_base)
    {
        long long src_number = ConvertToInteger(number, src_base);
        std::string dest_number = ConvertToLiteral(src_number, dest_base);
        int length = dest_number.size();
        if (length > 7)
        {
            puts("  ERROR");
        }
        else
        {
            printf("%7s\n", dest_number.c_str());
        }
    }
    
    return 0;
}