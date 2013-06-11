#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

long long ConvertToInteger(const std::string& number, int base)
{
    long long rv = 0;
    for (int i = 0; i < number.size(); i++)
    {
        rv *= base;
        rv += number[i] - '0';
    }
    return rv;
}

std::string ConvertToLiteral(long long number, int base)
{
    std::stringstream builder;
    long long d = number;
    while (d)
    {
        builder << (d % base);
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

int main(int argc, char* argv[])
{
    int base;
    std::string p_literal;
    std::string m_literal;
    long long m;

    while (std::cin >> base && base)
    {
        std::cin >> p_literal >> m_literal;
        m = ConvertToInteger(m_literal, base);
        long long remainder = 0;
        for (int i = 0; i < p_literal.size(); i++)
        {
            remainder = (remainder * base) % m;
            remainder = (remainder + p_literal[i] - '0') % m;
        }
        std::cout << ConvertToLiteral(remainder, base) << std::endl;
    }
    
    return 0;
}