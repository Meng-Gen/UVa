#include <iostream>
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

bool IsGood(const std::string& isbn)
{
    int digits[10];
    int digit_pos = 0;
    for (unsigned int i = 0; i < isbn.size(); i++)
    {
        char c = isbn[i];
        if (IsDecimalDigit(c))
        {
            if (digit_pos > 9)
            {
                return false;
            }
            digits[digit_pos] = c - '0';
            digit_pos++;
        }
        else if (c == 'X')
        {
            if (digit_pos != 9)
            {
                return false;
            }
            digits[digit_pos] = 10;
            digit_pos++;
        }
        else if (c != '-')
        {
            return false;
        }
    }
    if (digit_pos != 10)
    {
        return false;
    }

    // Check sum
    int partial_sums[10] = {};
    partial_sums[0] = digits[0];
    for (int i = 1; i < 10; i++)
    {
        partial_sums[i] = partial_sums[i-1] + digits[i];
    }

    int running_totals = 0;
    for (int i = 0; i < 10; i++)
    {
        running_totals += partial_sums[i];
    }

    return (running_totals % 11 == 0);
}

int main(int argc, char* argv[])
{
    std::string isbn;
    while (getline(std::cin, isbn))
    {
        // Trim
        size_t end_pos = isbn.find_last_not_of(" \t");
        if (std::string::npos != end_pos)
        {
            isbn = isbn.substr(0, end_pos + 1);
        }
        size_t start_pos = isbn.find_first_not_of(" \t");
        if (std::string::npos != start_pos)
        {
            isbn = isbn.substr(start_pos);
        }

        if (IsGood(isbn))
        {
            printf("%s is correct.\n", isbn.c_str());
        }
        else
        {
            printf("%s is incorrect.\n", isbn.c_str());
        }
    }

    return 0;
}