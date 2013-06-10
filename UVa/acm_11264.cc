#include <iostream>
#include <stdio.h>

long long coins[1002];

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int num_coins;
        std::cin >> num_coins;

        for (int i = 0; i < num_coins; i++)
        {
            std::cin >> coins[i];
        }

        long long sum = coins[0];
        int max_num_coins = 1;
        for (int i = 1; i < num_coins; i++)
        {
            if (i == num_coins - 1)
            {
                sum += coins[i];
                max_num_coins++;
            }
            else if (sum + coins[i] < coins[i+1])
            {
                sum += coins[i];
                max_num_coins++;
            }
        }
        printf("%d\n", max_num_coins);        
    }
    return 0;
}