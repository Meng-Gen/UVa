#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>

struct Integer
{
    int number;
    int prime_factor_count;
};

Integer orders[2000001] = {};

// -----------------------------------------------------------------------------

bool Compare(const Integer& a, const Integer& b)
{
    if (a.prime_factor_count < b.prime_factor_count)
    {
        return true;
    }
    else if (a.prime_factor_count > b.prime_factor_count)
    {
        return false;
    }
    return a.number < b.number;
}

void InitIntegerOrder()
{
    for (int i = 1; i < 2000001; i++)
    {
        orders[i].number = i;
        orders[i].prime_factor_count = 0;
    }

    for (int i = 2; i < 2000001; i++)
    {
        if (!orders[i].prime_factor_count)
        {

            for (int j = i; j < 2000001; j += i)
            {
                orders[j].prime_factor_count++;
                int d = j / i;
                while (d % i == 0)
                {
                    orders[j].prime_factor_count++;
                    d /= i;
                }
            }
        }
    }

    std::sort(orders, orders + 2000001, Compare);

    // The last one should be 1572864
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitIntegerOrder();

    int case_id = 1;
    int n;
    while (std::cin >> n && n)
    {
        printf("Case %d: %d\n", case_id, orders[n].number);
        case_id++;
    }
    return 0;
}