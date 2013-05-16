#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stdio.h>

long long GetFactorCount
(
    long long lower_limit, 
    long long upper_limit, 
    long long divisor
)
{
    long long begin_factor = lower_limit;
    if (begin_factor % divisor != 0)
    {
        begin_factor = (lower_limit/divisor + 1) * divisor;
    }
    long long end_factor = upper_limit;
    if (end_factor % divisor != 0)
    {
        end_factor = (upper_limit/divisor) * divisor;
    }

    if (begin_factor > end_factor)
    {
        return 0;
    }
    
    return (end_factor - begin_factor)/divisor + 1;
}

long long GetLeapYearCount(long long begin_year, long long end_year)
{
    long long factor_4_count = GetFactorCount(begin_year, end_year, 4);
    long long factor_100_count = GetFactorCount(begin_year, end_year, 100);
    long long factor_400_count = GetFactorCount(begin_year, end_year, 400);
    return factor_4_count - factor_100_count + factor_400_count;
}

std::map<std::string, int> month_names;

void init_month_names()
{
    month_names["January"] = 1;
    month_names["February"] = 2;
    month_names["March"] = 3;
    month_names["April"] = 4;
    month_names["May"] = 5;
    month_names["June"] = 6;
    month_names["July"] = 7;
    month_names["August"] = 8;
    month_names["September"] = 9;
    month_names["October"] = 10;
    month_names["November"] = 11;
    month_names["December"] = 12;
}

struct Date
{
    char date_string[30];
    long long year;
    int month;
    int day;

    void Parse()
    {
        std::stringstream month_string;
        int i = 0;
        for (; date_string[i] != ' '; i++)
        {
            month_string << date_string[i];
        }
        month = month_names[month_string.str()];

        day = 0;
        for (i++; date_string[i] != ','; i++)
        {
            day *= 10;
            day += (date_string[i] - '0');
        }

        year = 0;
        for (i += 2; date_string[i] != '\0'; i++)
        {
            year *= 10;
            year += (date_string[i] - '0');
        }
    }

    bool IsLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};

int main(int argc, char* argv[])
{
    init_month_names();

    int T;
    std::cin >> T;
    getchar();
    for (int t = 1; t <= T; t++)
    {
        Date dates[2];
        std::cin.getline(dates[0].date_string, 30);
        std::cin.getline(dates[1].date_string, 30);

        dates[0].Parse();
        dates[1].Parse();

        long long leap_year_count = GetLeapYearCount(dates[0].year, dates[1].year);
        if (dates[0].IsLeapYear())
        {
            if (dates[0].month > 2)
            {
                leap_year_count--;
            }
        }
        if (dates[1].IsLeapYear())
        {
            if ((dates[1].month < 2) || (dates[1].month == 2 && dates[1].day < 29))
            {
                leap_year_count--;
            }
        }
        printf("Case %d: %lld\n", t, leap_year_count);
    }

    return 0;
}
