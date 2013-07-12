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

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// ----------------------------------------------------------------------------

std::string source;
int begin_pos;
int end_pos;

void Trim()
{
    int len = source.size();
    begin_pos = 0;
    end_pos = len;
    for (; source[begin_pos] == ' ' && begin_pos < len; begin_pos++);
    for (; source[end_pos - 1] == ' ' && end_pos >= 0; end_pos--);
    source = source.substr(begin_pos, end_pos - begin_pos);
}

// -----------------------------------------------------------------------------

int GetExponentSymbolPos(const std::string& number)
{
    int pos = -1;

    bool found = false;
    int len = number.size();
    for (int i = 0; i < len; i++)
    {
        if (AsciiAlphaToLower(number[i]) == 'e')
        {
            if (found)
            {
                return -1;
            }
            else 
            {
                pos = i;
                found = true;
            }
        }
    }

    return pos;
}

int GetDecimalPointPos(const std::string& number)
{
    int pos = -1;

    bool found = false;
    int len = number.size();
    for (int i = 0; i < len; i++)
    {
        if (number[i] == '.')
        {
            if (found)
            {
                return -1;
            }
            else 
            {
                pos = i;
                found = true;
            }
        }
    }

    return pos;
}

bool IsLegalIntegerNumberWithoutSignSymbol(const std::string& number)
{
    int len = number.size();
    if (len == 0)
    {
        return false;
    }
    for (int pos = 0; pos < len; pos++)
    {
        if (!IsDecimalDigit(number[pos]))
        {
            return false;
        }
    }
    return true;
}

bool IsLegalIntegerNumber(const std::string& number)
{
    int len = number.size();
    if (len == 0)
    {
        return false;
    }

    int pos = (number[0] == '+' || number[0] == '-') ? 1 : 0;
    for (; pos < len; pos++)
    {
        if (!IsDecimalDigit(number[pos]))
        {
            return false;
        }
    }
    return true;
}

bool IsLegalDecimalNumber(const std::string& number)
{
    int decimal_point_pos = GetDecimalPointPos(number);
    if (decimal_point_pos < 0)
    {
        return false;
    }

    if (!IsLegalIntegerNumber(number.substr(0, decimal_point_pos)))
    {
        return false;
    }
    return IsLegalIntegerNumberWithoutSignSymbol(
        number.substr(decimal_point_pos+1));
}

bool IsLegalRealConstant()
{
    int e_pos = GetExponentSymbolPos(source);
    if (e_pos < 0)
    {
        return IsLegalDecimalNumber(source);
    }
    std::string mantissa_part = source.substr(0, e_pos);
    if (!IsLegalDecimalNumber(mantissa_part) &&
        !IsLegalIntegerNumber(mantissa_part))
    {
        return false;
    }

    std::string exponent_part = source.substr(e_pos + 1);
    return IsLegalIntegerNumber(exponent_part);
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    while (getline(std::cin, source) && (source != "*"))
    {
        Trim();
        if (IsLegalRealConstant())
        {
            printf("%s is legal.\n", source.c_str());
        }
        else
        {
            printf("%s is illegal.\n", source.c_str());
        }
    }
    return 0;
}