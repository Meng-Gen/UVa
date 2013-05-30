#include <iostream>
#include <stdio.h>

long long maximum(long long a, long long b)
{
    return (a > b) ? a : b;
}

long long GetTax(long long income, long long tax_rate_percentage)
{
    long long rv = income * tax_rate_percentage;
    if (rv % 100 == 0)
    {
        return rv/100;
    }
    return rv/100 + 1;
}

int main(int argc, char* argv[]) 
{
    long long progressive_tax_rate[] = { 0, 10, 15, 20, 25 };
    long long progressive_income[] = { 180000, 300000, 400000, 300000 };

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        long long income; 
        std::cin >> income;

        long long tax = 0;
        long long prev_income = 0;
        long long curr_income = income;
        for (int i = 0; i < 4; i++)
        {
            prev_income = curr_income;
            curr_income = maximum(0, prev_income - progressive_income[i]);
            tax += GetTax(prev_income - curr_income, progressive_tax_rate[i]);
        }
        tax += GetTax(curr_income, progressive_tax_rate[4]);

        if ((tax > 0) && (tax < 2000))
        {
            tax = 2000;
        }

        printf("Case %d: %lld\n", case_id, tax);
    }
    return 0;
}
