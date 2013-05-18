#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

long long land_prices[41] = {};
long long kBudgetLimit = 5000000;

int main(int argc, char* argv[])
{
    int T; // the number of test cases
    std::cin >> T;

    for (int t = 0; t < T; t++)
    {
        int i = 0;
        long long price;
        while (std::cin >> price)
        {
            if (price == 0)
            {
                break;
            }
            land_prices[i] = price;
            i++;
        }
        std::sort(land_prices, land_prices + i);

        long long min_price_so_far = 0;
        bool is_expensive = false;
        for (int j = i-1; j >= 0; j--)
        {
            long long curr_price = 2 * land_prices[j];
            for (int k = 0; k < i-j-1; k++)
            {
                curr_price *= land_prices[j];
                if (curr_price > kBudgetLimit)
                {
                    is_expensive = true;
                    break;
                }
            }
            if (is_expensive)
            {
                break;
            }

            min_price_so_far += curr_price;
            if (min_price_so_far > kBudgetLimit)
            {
                is_expensive = true;
                break;
            }
        }

        if (is_expensive)
        {
            printf("Too expensive\n");
        }
        else 
        {
            printf("%lld\n", min_price_so_far);
        }
    }
    
    return 0;
}