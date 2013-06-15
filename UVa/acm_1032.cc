#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

// http://www.hermetic.ch/cal_stud/jdn.htm
unsigned int JulianDayFromDate(int year, int month, int day) 
{
    return (1461 * (year + 4800 + (month - 14) / 12)) / 4
        + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12
        - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4
        + day - 32075;
}

// http://www.hermetic.ch/cal_stud/jdn.htm
void GetDateFromJulianDay(
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

    *year = y;
    *month = m;
    *day = d;
}

// -----------------------------------------------------------------------------

int BuildDeltaJulianDay(const std::string& date)
{
    int y = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + 
            (date[2] - '0') * 10 + date[3] - '0';
    int m = (date[4] - '0') * 10 + date[5] - '0';
    int d = (date[6] - '0') * 10 + date[7] - '0';
    return JulianDayFromDate(y, m, d) - 2341973;
}

bool past[146470] = {};
bool required[146470] = {};

int main(int argc, char* argv[])
{
    int case_id = 1;
    int NX, NR;
    std::string begin_date;
    std::string end_date;
    while (std::cin >> NX >> NR && (NX || NR))
    {
        // Otherwise you will get WA
        if (case_id > 1)
        {
            putchar('\n');
        }

        memset(past, false, 146470);
        memset(required, false, 146470);

        for (int i = 0; i < NX; i++)
        {
            std::cin >> begin_date >> end_date;
            int begin = BuildDeltaJulianDay(begin_date);
            int end = BuildDeltaJulianDay(end_date);
            for (int j = begin; j <= end; j++)
            {
                past[j] = true;
            }
        }

        bool is_required = false;
        for (int i = 0; i < NR; i++)
        {
            std::cin >> begin_date >> end_date;
            int begin = BuildDeltaJulianDay(begin_date);
            int end = BuildDeltaJulianDay(end_date);
            for (int j = begin; j <= end; j++)
            {
                if (!past[j])
                {
                    is_required = true;
                    required[j] = true;
                }
            }
        }

        printf("Case %d:\n", case_id);
        case_id++;

        if (!is_required)
        {
            puts("    No additional quotes are required.");
            continue;
        }
        
        bool is_interval = false;
        unsigned int begin_jd;
        for (int i = 0; i < 146470; i++)
        {
            if (required[i] && !is_interval)
            {
                begin_jd = i + 2341973;
                is_interval = true;
            }
            else if (!required[i] && is_interval)
            {
                if (i + 2341972 == begin_jd)
                {
                    int y, m, d;
                    GetDateFromJulianDay(begin_jd, &y, &m, &d);
                    printf("    %d/%d/%d\n", m, d, y);
                }
                else 
                {
                    int y[2], m[2], d[2];
                    GetDateFromJulianDay(begin_jd, &y[0], &m[0], &d[0]);
                    GetDateFromJulianDay(i + 2341972, &y[1], &m[1], &d[1]);
                    printf("    %d/%d/%d to %d/%d/%d\n", 
                        m[0], d[0], y[0], m[1], d[1], y[1]);
                }
                is_interval = false;
            }
        }
    }

    return 0;
}