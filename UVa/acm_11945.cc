#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        long long sum = 0;
        for (int month = 0; month < 12; month++)
        {
            long long dollars;
            char dot;
            long long cents;
            std::cin >> dollars >> dot >> cents;

            sum = sum + dollars * 100 + cents;
        }
        long long avg = sum / 12;
        long long avg_rest = sum % 12;

        printf("%d $", case_id);
        long long avg_thousands = avg / 100000;
        long long avg_dollars = (avg % 100000)/100;
        long long avg_cents = avg % 100;
        if (avg_rest >= 6)
        {
            avg_cents++;
        }

        if (avg_thousands)
        {
            printf("%lld,%03lld.%02lld\n", 
                avg_thousands, avg_dollars, avg_cents);
        }
        else
        {
            printf("%lld.%02lld\n", avg_dollars, avg_cents);
        }
    }

    return 0;
}