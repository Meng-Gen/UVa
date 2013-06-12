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
    for (char c = 'A'; c <= 'Z'; c++)
    {
        digit_value[c] = 10 + c - 'A';
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        digit_value[c] = 10 + c - 'a';
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

bool IsPalindrome(const std::string& word)
{
    int length = word.size();
    for (int i = 0; i < length/2; i++)
    {
        if (word[i] != word[length-1-i])
        {
            return false;
        }
    }
    return true;
}

// -----------------------------------------------------------------------------

std::string ReverseAndAdd(const std::string& number, int base)
{
    std::string palindrome_number = number;
    std::reverse(palindrome_number.begin(), palindrome_number.end());

    long long sum = ConvertToInteger(number, base) + 
        ConvertToInteger(palindrome_number, base);
    return ConvertToLiteral(sum, base);
}

int GetPalindromeSteps(const std::string& number, int base)
{
    int steps = 0;

    std::string next_number = number; 
    while (!IsPalindrome(next_number))
    {
        next_number = ReverseAndAdd(next_number, base);
        steps++;
    }

    return steps;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitDigitValue();

    std::string number;
    while (std::cin >> number)
    {
        int min_base = GetMinBase(number);
        for (int base = 15; base >= 2; base--)
        {
            if (base >= min_base)
            {
                printf("%d", GetPalindromeSteps(number, base));
            }
            else
            {
                putchar('?');
            }

            if (base != 2)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
    
    return 0;
}