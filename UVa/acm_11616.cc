#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// -----------------------------------------------------------------------------

std::map<int, std::string> roman_digit_base1;
std::map<int, std::string> roman_digit_base10;
std::map<int, std::string> roman_digit_base100;
std::map<int, std::string> roman_digit_base1000;

void InitRomanDigitBase1()
{
    roman_digit_base1[1] = "I";
    roman_digit_base1[2] = "II";
    roman_digit_base1[3] = "III";
    roman_digit_base1[4] = "IV";
    roman_digit_base1[5] = "V";
    roman_digit_base1[6] = "VI";
    roman_digit_base1[7] = "VII";
    roman_digit_base1[8] = "VIII";
    roman_digit_base1[9] = "IX";
}

void InitRomanDigitBase10()
{
    roman_digit_base10[1] = "X";
    roman_digit_base10[2] = "XX";
    roman_digit_base10[3] = "XXX";
    roman_digit_base10[4] = "XL";
    roman_digit_base10[5] = "L";
    roman_digit_base10[6] = "LX";
    roman_digit_base10[7] = "LXX";
    roman_digit_base10[8] = "LXXX";
    roman_digit_base10[9] = "XC";
}

void InitRomanDigitBase100()
{
    roman_digit_base100[1] = "C";
    roman_digit_base100[2] = "CC";
    roman_digit_base100[3] = "CCC";
    roman_digit_base100[4] = "CD";
    roman_digit_base100[5] = "D";
    roman_digit_base100[6] = "DC";
    roman_digit_base100[7] = "DCC";
    roman_digit_base100[8] = "DCCC";
    roman_digit_base100[9] = "CM";
}

void InitRomanDigitBase1000()
{
    roman_digit_base1000[1] = "M";
    roman_digit_base1000[2] = "MM";
    roman_digit_base1000[3] = "MMM";
}

void InitRomanDigits()
{
    InitRomanDigitBase1();
    InitRomanDigitBase10();
    InitRomanDigitBase100();
    InitRomanDigitBase1000();
}

std::string ConvertToRomanNumber(const std::string& number)
{
    int digit_count = number.size();
    
    std::stringstream builder;
    if (digit_count > 3)
    {
        builder << roman_digit_base1000[number[digit_count - 4] - '0'];    
    }
    if (digit_count > 2)
    {
        builder << roman_digit_base100[number[digit_count - 3] - '0'];    
    }
    if (digit_count > 1)
    {
        builder << roman_digit_base10[number[digit_count - 2] - '0'];    
    }
    builder << roman_digit_base1[number[digit_count - 1] - '0'];

    return builder.str();
}

// -----------------------------------------------------------------------------

std::map<char, int> arabic_numbers;

void InitArabicNumbers()
{
    arabic_numbers['I'] = 1;
    arabic_numbers['V'] = 5;
    arabic_numbers['X'] = 10;
    arabic_numbers['L'] = 50;
    arabic_numbers['C'] = 100;
    arabic_numbers['D'] = 500;
    arabic_numbers['M'] = 1000;
}

int ConvertToArabicNumber(const std::string& number)
{
    int sum = 0;
    int prev_x = 0;
    for (int i = 0; i < number.size(); i++)
    {
        int x = arabic_numbers[number[i]];
        if (x > prev_x)
        {
            sum = sum - prev_x + x - prev_x;
        }
        else
        {
            sum += x;
        }
        prev_x = x;
    }
    return sum;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitRomanDigits();
    InitArabicNumbers();

    std::string buffer;
    while (std::cin >> buffer)
    {
        if (IsDecimalDigit(buffer[0]))
        {
            std::cout << ConvertToRomanNumber(buffer) << std::endl;
        }
        else
        {
            std::cout << ConvertToArabicNumber(buffer) << std::endl;
        }
    }
    
    return 0;
}