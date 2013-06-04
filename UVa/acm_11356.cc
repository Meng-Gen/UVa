#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

struct Date
{
    Date() : jd(0) { }
    Date(int year, int month, int day)
    {
        jd = JulianDayFromDate(year, month, day);
    }

    void AddDays(int ndays)
    {
        jd += ndays;
    }

    int year() const 
    {
        int y;
        GetDateFromJulianDay(jd, &y, 0, 0);
        return y;
    }

    int month() const
    {
        int m;
        GetDateFromJulianDay(jd, 0, &m, 0);
        return m;
    }

    int day() const
    {
        int d;
        GetDateFromJulianDay(jd, 0, 0, &d);
        return d;
    }

    // http://www.hermetic.ch/cal_stud/jdn.htm
    static unsigned int JulianDayFromDate(int year, int month, int day)
    {
        return (1461 * (year + 4800 + (month - 14) / 12)) / 4
            + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12
            - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4
            + day - 32075;
    }

    // http://www.hermetic.ch/cal_stud/jdn.htm
    static void GetDateFromJulianDay(
        unsigned jd, int *year, int *month, int *day)
    {
        int y, m, d;

        unsigned long long l, n, i, j;
        l = (unsigned long long)(jd) + 68569;
        n = (4 * l) / 146097;
        l = l - (146097 * n + 3) / 4;
        i = (4000 * (l + 1)) / 1461001;
        l = l - (1461 * i) / 4 + 31;
        j = (80 * l) / 2447;
        d = l - (2447 * j) / 80;
        l = j / 11;
        m = j + 2 - (12 * l);
        y = 100 * (n - 49) + i + l;

        if (year)
        {
            *year = y;
        }
        if (month)
        {
            *month = m;
        }
        if (day)
        {
            *day = d;
        }
    }

    unsigned int jd;
};

// -----------------------------------------------------------------------------

int FromString(const std::string &int_literal) 
{
    int rv;
    std::stringstream result_builder(int_literal);
    result_builder >> rv;
    return rv;
}

std::string month_names[] = 
{
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

std::map<std::string, int> months;

void InitMonthsMap()
{
    for (int i = 0; i < 12; i++)
    {
        months[month_names[i]] = i;
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitMonthsMap();

    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::string date_literal;
        int ndays;
        std::cin >> date_literal >> ndays;

        std::size_t first_hyphen = date_literal.find("-");
        std::size_t second_hyphen = date_literal.find("-", first_hyphen + 1);
        int year = FromString(date_literal.substr(0, first_hyphen));
        int month = months[date_literal.substr(
            first_hyphen + 1, second_hyphen - first_hyphen - 1)] + 1;
        int day = FromString(date_literal.substr(second_hyphen + 1));

        Date date(year, month, day);
        date.AddDays(ndays);

        printf("Case %d: %d-%s-%02d\n", 
            case_id, 
            date.year(), 
            month_names[date.month() - 1].c_str(), 
            date.day());
    }

    return 0;
}