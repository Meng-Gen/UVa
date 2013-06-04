#include <iostream>
#include <string>
#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int GetYearDiff(const Date& begin, const Date& end)
{
    int y = begin.year - end.year;
    int m = begin.month - end.month;
    int d = begin.day - end.day;
    
    if (y > 0 || (y == 0 && (m > 0 ||(m == 0 && d > 0))))
    {
        return -1;
    }

    int rv = -y;
    if (m > 0 || (m == 0 && d > 0))
    {
        rv--;
    }
    return rv;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        Date curr_date;
        Date birth_date;
        char slash;
        std::cin >> curr_date.day >> slash >> curr_date.month >> 
            slash >> curr_date.year;
        std::cin >> birth_date.day >> slash >> birth_date.month >> 
            slash >> birth_date.year;

        int year_diff = GetYearDiff(birth_date, curr_date);
        if (year_diff < 0)
        {
            printf("Case #%d: Invalid birth date\n", case_id);
        }
        else if (year_diff > 130)
        {
            printf("Case #%d: Check birth date\n", case_id);
        }
        else
        {
            printf("Case #%d: %d\n", case_id, year_diff);
        }
    }

    return 0;
}