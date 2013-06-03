#include <iostream>
#include <string>
#include <stdio.h>

int BigIntegerMod(const std::string& number, int mod)
{
    int rv = 0;

    for (std::string::const_iterator it = number.begin(); 
        it != number.end(); it++)
    {
        rv *= 10;
        rv += ((*it) - '0');
        rv %= mod;
    }

    return rv;
}

// ----------------------------------------------------------------------------

std::string year;

bool IsLeapYear()
{
    if (BigIntegerMod(year, 400) == 0)
    {
        return true;
    }
    if (BigIntegerMod(year, 100) == 0)
    {
        return false;
    }
    return (BigIntegerMod(year, 4) == 0);
}

int main(int argc, char* argv[])
{
    bool is_first_testcase = true;
    while (getline(std::cin, year))
	{
        if (is_first_testcase)
        {
            is_first_testcase = false;
        }
        else
        {
            putchar('\n');
        }

        bool is_ordinary_year = true;
        bool is_leap_year = IsLeapYear();
        if (IsLeapYear())
        {
            puts("This is leap year.");
            is_ordinary_year = false;
        }
        if (BigIntegerMod(year, 15) == 0)
        {
            puts("This is huluculu festival year.");
            is_ordinary_year = false;
        }
        if ((BigIntegerMod(year, 55) == 0) && is_leap_year)
        {
            puts("This is bulukulu festival year.");
            is_ordinary_year = false;
        }
        if (is_ordinary_year)
        {
            puts("This is an ordinary year.");
        }
	}
	
	return 0;
}