#include <algorithm>
#include <iostream>
#include <stdio.h>

int prices[20002];

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int num_items;
        std::cin >> num_items;

        for (int i = 0; i < num_items; i++)
        {
            std::cin >> prices[i];
        }

        std::sort(prices, prices + num_items);
 
        int discount = 0;
        for (int i = num_items - 1; i >= 0; i -= 3)
        {
            if (i - 2 >= 0)
            {
                discount += prices[i - 2];
            }
        }
        printf("%d\n", discount);
    }
    return 0;
}