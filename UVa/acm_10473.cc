#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// -----------------------------------------------------------------------------

bool IsHexNumber(const std::string& number)
{
    if (number.size() < 2)
    {
        return false;
    }
    return number[0] == '0' && number[1] == 'x';
}

long long HexToDecimal(const std::string& number)
{
    long long rv = 0;
    for (int i = 2; i < number.size(); i++)
    {
        char c = number[i];
        rv *= 16;
        if (IsInRange(c, '0', '9'))
        {
            rv += c - '0';
        }
        else 
        {
            rv += AsciiAlphaToLower(c) - 'a' + 10;
        }
    }
    return rv;
}

long long ToDecimal(const std::string& number)
{
    long long rv = 0;
    for (int i = 0; i < number.size(); i++)
    {
        rv *= 10;
        rv += number[i] - '0';        
    }
    return rv;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    std::string number;
    while (std::cin >> number && (number[0] != '-'))
    {
        if (IsHexNumber(number))
        {
            std::cout << std::dec << HexToDecimal(number) << std::endl;
        }
        else
        {
            std::cout << "0x" << std::hex << std::uppercase 
                << ToDecimal(number) << std::endl;
        }
    }
    
    return 0;
}